#include <iostream>
#include "MPointer.h"

int main()
{
    std::cout << "oh no, proyecto time" << std::endl;
    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr = 5;
    int valor = &myPtr;
    std::cout << valor << std::endl;

    MPointer<int> myPtr2 = MPointer<int>::New();
    myPtr2 = myPtr;
    int valor2 = &myPtr2;
    std::cout << valor2 << std::endl;

    {
        MPointer<int> myPtr3 = MPointer<int>::New();
        *myPtr3 = 10;
        std::cout << *myPtr3 << std::endl;
    }


    return 0;
}
