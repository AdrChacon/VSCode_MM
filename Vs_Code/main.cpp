#include <iostream>
#include "vsptr.h"
#include "Client.h"
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;
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

    json j1 = {{"vr",23}};
    std::cout << j1["vr"] << std::endl;
    auto j3 =  json::parse("{ \"happy\": true, \"pi\": 3.141 }");
    std:: string j13 = j1.dump();
    auto j4 = json::parse(j13);
    std::cout << j4["vr"]<< std::endl;

    return 0;
}
