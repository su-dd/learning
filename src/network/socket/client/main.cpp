#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 4096

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[4096], sendline[4096];
    struct sockaddr_in servaddr;

    // if (argc != 2)
    // {
    //     printf("usage: ./client <ip address>\n");
    //     exit(0);
    // }

    char *host = (char *)(argc == 2 ? argv[1] : "127.0.0.1");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr)); // clear servaddr structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error for %s\n", host);
        exit(0);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connect error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    printf("send msg to server: \n");
    fgets(sendline, 4096, stdin);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0)
    {
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }

    close(sockfd);
    exit(0);
}