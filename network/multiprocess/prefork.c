#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SA struct sockaddr

struct _SocketInfo
{
    int pid;
    int fd;
    int status;
};

int write_fd(int fd, void *ptr, size_t nbytes, int sendfd);
int prefork_client(int fd);
int read_fd(int fd);

int main_server(int server_sockfd,
        struct _SocketInfo *SInfo,
        struct sockaddr_in clientaddr,
        int preforknum);

int main(int argc, char **argv)
{
    char buf_in[80];
    int state;
    int clilen;
    int n,i,pid;
    int preforknum;
    int ppid;
    int sv[2];
    struct _SocketInfo *SocketArray;

    int server_sockfd, client_sockfd;
    struct sockaddr_in clientaddr, serveraddr;

    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s [prefork#]\n", argv[0]);
        return 1;
    }
    preforknum = atoi(argv[1]);

    if((server_sockfd = socket(AF_INET, SOCK_STREAM 0)) < 0)
    {
        perror("Error");
        return 1;
    }
    bzero(&serveraddr, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(8083);

    bind(server_sockfd, (SA *)&serveraddr, sizeof(serveraddr));
    if((state = listen(server_sockfd, 5))<0)
    {
        perror("listen error: ");
        exit(0);
    }

    if(preforknum > 10)
    {
        fprintf(stderr, "Max preforknum is 10\n");
        exit(0);
    }
    ppid = getpid();

    SocketArray = (void *)malloc(sizeof(struct _SocketInfo)*preforknum);
    memset((void*)SocketArray, 0x00,sizeof(struct _SocketInfo)*preforknum);
    for( i = 0; i < preforknum; i++)
    {
        socketpair(AF_LOCAL, SOCK_STREAM, AF_LOCAL, sv);
        pid = fork();
        if(pid < 0)
        {
            perror("fork error");
            exit(0);
        }
        if(pid == 0)
        {
            dup2(sv[0], 0);
            close(sv[1]);
            close(sv[0]);
            close(server_sockfd);
            prefork_client(0);
        }
        else
        {
            close(sv[0]);
            SocketArray[i].pid = pid;
            SocketArray[i].fd = sv[1];
            SocketArray[i].status = 1;
        }
    }
    main_server(server_sockfd, SocketArray, clientaddr, preforknum);


