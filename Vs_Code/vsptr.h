//
// Created by grero on 6/1/2020.
//

#ifndef VS_CODE_VSPTR_H
#define VS_CODE_VSPTR_H
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
public:
    // constructor
    Vsptr(): ptr(new T) {

        cont ++;
    }
    // New
    // crea el Vsptr
    static Vsptr<T> New(){
        Vsptr<T> *myPtr = new Vsptr<T>;
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
};
#endif //VS_CODE_VSPTR_H
