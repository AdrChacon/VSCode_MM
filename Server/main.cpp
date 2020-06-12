#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "nlohmann/json.hpp"
#include "LinkedList.h"
#include "Node.h"

using json = nlohmann::json;
#define PORT_NUMBER 5000
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main()
{
    json ok = {{"id",""}};
    LinkedList lista;
    lista.printList();
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    bool continuar = false;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    std::string s;
    int id_cont = 0;
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

    bzero(buffer,256);

    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    for(int i = 0; i < 256; i++){
        s = s+buffer[i];
    };
    std ::cout << s <<std ::endl;
    auto j = json::parse(s);
    s = "";
    std::string s1 = j["tipo"];
    printf("Here is the message: %s\n",buffer);

    if (s1 == "int"){
        std::string ss = j["dato"];
        lista.addNode(ss, std::to_string (id_cont));
        bzero(buffer,256);
        ok["id"] = std::to_string(id_cont);
        std::cout << id_cont<< std::endl;
        id_cont ++;
        std:: string j13 = ok.dump();
        strcpy (buffer,j13.c_str());
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");
    }
    else if (s1 == "var"){
        std:: string valor1 = j["id"];
        std:: string valor2 = j["dato"];
        lista.change_data(valor1,valor2);

    }
    else if (s1 == "request"){
        std::string ss = j["id"];
        std::string valor = lista.obtencion(ss);
        json yson = {{"dato",valor}};
        bzero(buffer,256);
        std:: string j13 = yson.dump();
        strcpy (buffer,j13.c_str());
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");
    }
    else{
        bzero(buffer,256);
        std::string ss1 = j["pswd"];
        std ::cout <<ss1<<std ::endl;
        if (ss1 == "1234"){
            json yson = {{"dato","true"}};
            bzero(buffer,256);
            std:: string j13 = yson.dump();
            strcpy (buffer,j13.c_str());
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0)
                error("ERROR writing to socket");
        }
        else {

            json yson = {{"dato","false"}};
            bzero(buffer,256);
            std:: string j13 = yson.dump();
            strcpy (buffer,j13.c_str());
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0)
                error("ERROR writing to socket");
        };

    };
    lista.printList();
    };
    return 0;
}