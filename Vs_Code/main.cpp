#include <iostream>
#include "vsptr.h"
#include "Client.h"
using namespace std;
// main
int main() {
    Vsptr<int> myPtr = Vsptr<int>::New();
    Vsptr<int> myPtr2 = Vsptr<int>::New();
    Vsptr<int> myPtr3 = Vsptr<int>::New();
    *myPtr = 47;
    myPtr3 = 32;
    myPtr2 = myPtr;
    int valor = &myPtr;
    std ::cout << "El valor de myPtr(*myPtr = 47;):" <<std ::endl;
    std ::cout << &myPtr <<std ::endl;
    std::cout << "El valor es ( int valor = &myPtr):" << std::endl;
    std::cout << valor << std::endl;
    std ::cout << "El valor de myPtr3(myPtr3 = 32;):" <<std ::endl;
    std::cout << &myPtr3 << std::endl;
    std ::cout << "El valor de myPtr2(myPtr2 = myPtr;):" <<std ::endl;
    std::cout << &myPtr2<< std::endl;

    Client socket;
    socket.client();


    return 0;
}
