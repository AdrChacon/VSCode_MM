//
// Created by grero on 6/5/2020.
//

#include "Client.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

int puerto;
void error(const char *msg)
{
    perror(msg);
    exit(0);
}
//clase inicializador
// Le pide al servidor el id que se le va a asignar al puntero.
std::string Client::inicializador()
{
    json ejm = {{"dato","0"},{"tipo","int"}};
    std:: string j13 = ejm.dump();

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    std::string id;
    char buffer[256];
    std::string s;
    strcpy (buffer,j13.c_str());
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(puerto);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);
    close(sockfd);
    for(int i = 0; i < 256; i++){
        s = s+buffer[i];
    };
    auto j = json::parse(s);
    id = j["id"];

    return id;
}
//clase asignador
//Se encarga de perdir al servidor asignar un id  a un puntero especifico.
int Client::asignador(std::string x, std::string y)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    json ejm = {{"dato", x},{"tipo","var"},{"id",y}};
    std:: string j13 = ejm.dump();
    char buffer[256];
    strcpy (buffer,j13.c_str());
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(puerto);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    close(sockfd);
    return 0;
}
//clase peticion
// Le pide al server el dato de un puntero
std::string Client::peticion(std::string x)
{
    json ejm = {{"id",x},{"tipo","request"}};
    std:: string j13 = ejm.dump();

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    std::string data;
    char buffer[256];
    std::string s;
    strcpy (buffer,j13.c_str());
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(puerto);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);
    close(sockfd);
    for(int i = 0; i < 256; i++){
        s = s+buffer[i];
    };
    auto j = json::parse(s);
    data = j["dato"];
    return data;
}
//clase client
// Se envia el pswd al server para poder para poder acceder a sus funciones.
Client::Client(std::string pswd, std::string ip_dir,std::string port)
{
    json ejm = {{"pswd",pswd},{"tipo",""}};
    std:: string j13 = ejm.dump();
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    puerto = std::stoi (port);
    std::string data;
    char buffer[256];
    std::string s;
    strcpy (buffer,j13.c_str());
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(puerto);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);
    close(sockfd);
    for(int i = 0; i < 256; i++){
        s = s+buffer[i];
    };
    auto j = json::parse(s);
    data = j["dato"];
    if(data == "false"){
        exit(0);
    };
}

/* int Client::client()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    puerto = 5000;

    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(puerto);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}
*/