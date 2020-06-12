//
// Created by grero on 6/1/2020.
//

#ifndef VS_CODE_VSPTR_H
#define VS_CODE_VSPTR_H

#include "Client.h"

using namespace std;
// clase template
// crea un puntero de tipo template
template <class T>
class Vsptr{
private:
    // almacena valor del puntero
    T *ptr = new T;
    // contador de referencias
    int cont;
    std::string id;
    Client socket{"1234","","5000"};
public:
    // constructor
    Vsptr(): ptr(new T) {

        cont ++;
    }
    // destructor
    ~Vsptr(){
        if(--cont == 0){
            delete ptr;
        }
    }
    // clase operator&
    // sobrecarga de &
    T operator&(){

        std::string valor = socket.peticion(this->id);
        return std::stoi(valor);
    };
    // clase operator=
    // sobrecarga de = (valor concreto)
    void operator=(const T valor){
        socket.asignador(std::to_string(valor),this->id);
        *ptr = valor;

    };
    // clase &operator*
    // sobrecarga de * (cuando el puntero esta derefenciado)
    T &operator*(){
        return *ptr;
    };
    // clase operator=
    // sobrecarga de = (cuando se le pasa valor de puntero)
    void operator=( T *valor){
        if (--cont == 0){
            delete ptr;
        }
        this->set_ptr(valor);
        cont++;
    };
    //asigna valor de un puntero a otro
    Vsptr<T> &operator=(Vsptr<T> &VS){
        if (--cont == 0){
            delete ptr;
        }
        socket.asignador(std::to_string (*VS.ptr),this->id);
        this->ptr = VS.ptr;
        cont++;
        return *this;
    };
    // New
    // crea el Vsptr
    static Vsptr<T> New(){
        Vsptr<T> *myPtr = new Vsptr<T>;
        myPtr ->set_id(myPtr ->socket.inicializador());
        return *myPtr;
    };
    // get_ptr
    // retorna el valor del puntero
    T get_ptr(){
        return  *ptr;
    };
    // set_ptr
    // setea el valor del puntero
    // @param punt<T>: valor a almacenar 
    void set_ptr(T *punt){
        Vsptr::ptr = punt;

    };
    //consigue el id
    std::string get_id(){
        return  id;
    };
    //setea el valor del id
    void set_id(std::string data){
        Vsptr::id = data;

    };
};


#endif //VS_CODE_VSPTR_H
