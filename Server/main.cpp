#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER 5000
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT_NUMBER);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0)
    error("ERROR on binding");

    while (true){
    listen(sockfd,5);
    clilen = sizeof(struct sockaddr_in);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    printf("server: got connection from %s port %d\n",
           inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    send(newsockfd, "Hello, world!\n", 13, 0);

    bzero(buffer,256);

    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);


    };

    return 0;
}