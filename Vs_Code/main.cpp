#include <iostream>
#include "vsptr.h"
using namespace std;
// main
int main() {
    Vsptr<int> myPtr = Vsptr<int>::New();
    Vsptr<int> myPtr2 = Vsptr<int>::New();
    *myPtr = 47;
    std ::cout << &myPtr <<std ::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
