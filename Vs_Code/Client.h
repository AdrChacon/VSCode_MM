//
// Created by grero on 6/5/2020.
//

#ifndef VS_CODE_CLIENT_H
#define VS_CODE_CLIENT_H


#include <string>
/**
 * Inicia la clase cliente
 */ 
class Client {
    public:

    std::string inicializador();
    int asignador(std::string x,std::string y);
    std::string peticion(std::string x);
    Client(std::string pswd, std::string ip_dir, std::string port);
};


#endif //VS_CODE_CLIENT_H
