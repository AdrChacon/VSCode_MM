//
// Created by grero on 6/1/2020.
//

#ifndef VS_CODE_VSPTR_H
#define VS_CODE_VSPTR_H

#include "Client.h"

using namespace std;
/**
 *  clase template
 *  crea un puntero de tipo template
 */
template <class T>
class Vsptr{
private:
    T *ptr = new T;  ///< Almacena el valor del puntero
    int cont; ///< Contador de referencias
    std::string id;  ///< ID del puntero
    Client socket{"1234","","5000"};
public:
    
    /**
     * Constructor de Vsptr
     */
    Vsptr(): ptr(new T) {

        cont ++;
    }
    /**
     * Destructor de Vsptr
     */
    ~Vsptr(){
        if(--cont == 0){
            delete ptr;
        }
    }
    /**
     *  Sobrecarga el operador & para obtener
     *  el dato contenido
     * @return El dato
     */
    T operator&(){

        std::string valor = socket.peticion(this->id);
        return std::stoi(valor);
    };
    /**
     * Sobrecarga el operador = para asignar un nuevo
     * valor cuando se pasa un valor concreto como parametro.
     * @param valor Nuevo valor
     */
    void operator=(const T valor){
        socket.asignador(std::to_string(valor),this->id);
        *ptr = valor;

    };
    /**
     * Sobrecarga el operador * cuando el puntero es deferenciado
     */
    T &operator*(){
        return *ptr;
    };
    /**
     * Sobrecarga el operador = cuando se le pasa valor de puntero
     * @param *valor 
     */
    void operator=( T *valor){
        if (--cont == 0){
            delete ptr;
        }
        this->set_ptr(valor);
        cont++;
    };
    //asigna valor de un puntero a otro
    /**
     * Sobrecarga el operador = para asignarle el valor de un puntero a otro
     * @param &VS Puntero
     */
    Vsptr<T> &operator=(Vsptr<T> &VS){
        if (--cont == 0){
            delete ptr;
        }
        socket.asignador(std::to_string (*VS.ptr),this->id);
        this->ptr = VS.ptr;
        cont++;
        return *this;
    };
    /**
     * Inicializa un nuevo puntero de tipo T
     * @return Vsptr<T> Puntero
     */
    static Vsptr<T> New(){
        Vsptr<T> *myPtr = new Vsptr<T>;
        myPtr ->set_id(myPtr ->socket.inicializador());
        return *myPtr;
    };
    /**
     * Retorna el valor del puntero
     * @return T Valor
     */
    T get_ptr(){
        return  *ptr;
    };
    /**
     * Establece el valor del puntero
     * @param *punt Valor
     */
    void set_ptr(T *punt){
        Vsptr::ptr = punt;

    };
    /**
     * Retorna el ID
     * @return id
     */
    std::string get_id(){
        return  id;
    };
    /**
     * Establece el valor del ID
     * @param data Nuevo valor
     */
    void set_id(std::string data){
        Vsptr::id = data;

    };
};


#endif //VS_CODE_VSPTR_H
