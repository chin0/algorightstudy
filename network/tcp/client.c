#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 1234

struct cal_data
{
    int left_num;
    int right_num;
    char op;
    int result;
    short int error;
};

int main(int argc, char *argv[])
{
    struct sockaddr_in addr;
    int server_sockfd;
    char buffer[256];
    int len;
    int sbyte, rbyte;
    struct cal_data sdata;
    if(argc != 4)
    {
        printf("Usage: %s [num1] [num2] [op\n",argv[0]);
        return -1;
    }

    bzero((void *)&sdata,sizeof(sdata));
    sdata.left_num = atoi(argv[1]);
    sdata.right_num = atoi(argv[2]);
    sdata.op = argv[3][0];

    server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_sockfd == -1)
    {
        perror("failed to create socket.");
        return -1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(server_sockfd,(struct sockaddr *)&addr,
                sizeof(addr)) == -1)
    {
        perror("failed to connect server.");
        close(server_sockfd);
        return -1;
    }

    len = sizeof(sdata);
    sdata.left_num = htonl(sdata.left_num);
    sdata.right_num = htonl(sdata.right_num);
    sbyte = send(server_sockfd, (char *)&sdata, len, 0);
    if(sbyte != len)
        return -1;

    rbyte = recv(server_sockfd, (char *)&sdata, len, 0);
    if(rbyte != len)
        return -1;
    if(ntohs(sdata.error != 0))
        printf("CALC Error %d\n", ntohs(sdata.error));

    printf("%d %c %d = %d\n", ntohl(sdata.left_num), sdata.op, ntohl(sdata.right_num), ntohl(sdata.result));
    close(server_sockfd);
    return 0;
}



