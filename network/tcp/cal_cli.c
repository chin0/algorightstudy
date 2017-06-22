#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

struct cal_data
{
    int left_num;
    int right_num;
    char op;
    int result;
    short int error;
};

int main(int argc, char **argv)
{
    struct sockaddr_in client_addr, sock_addr;
    int listen_sockfd, client_sockfd;


