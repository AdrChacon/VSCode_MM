#include <iostream>
#include "vsptr.h"
using namespace std;
// main
int main() {
    Vsptr<int> myPtr = Vsptr<int>::New();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
