#include <iostream>
#include "MPointer.h"
#include "MPointerGC.h"
#include "DoublyLinkedList.h"
#include "Sorters.h"

int main()
{
    std::cout << "oh no, proyecto time" << std::endl;
    MPointerGC::getInstance()->initializeGC(10);
    DoublyLinkedList<int> dll;

    MPointer<int> myPtr = MPointer<int>::New();
    *myPtr = 50;
    myPtr.printPtr();
    dll.append(myPtr);

    MPointer<int> myPtr2 = MPointer<int>::New();
    myPtr2 = myPtr;
    myPtr2.printPtr();
    dll.append(myPtr2);

    {
        MPointer<int> myPtr3 = MPointer<int>::New();
        *myPtr3 = 20;
        myPtr3.printPtr();
        dll.append(myPtr3);
    }

    MPointer<int> myPtr4 = MPointer<int>::New();
    *myPtr4 = 10;
    myPtr4.printPtr();
    dll.append(myPtr4);

    MPointer<int> myPtr5 = MPointer<int>::New();
    myPtr5 = myPtr4;
    myPtr5.printPtr();
    dll.append(myPtr5);

    MPointer<int> myPtr6 = MPointer<int>::New();
    myPtr6 = myPtr4;
    myPtr6.printPtr();
    dll.append(myPtr6);

    MPointer<int> myPtr7 = MPointer<int>::New();
    *myPtr7 = 2;
    myPtr7.printPtr();
    dll.append(myPtr7);

    //Sorters<int>::QuickSort(dll);
    //Sorters<int>::BubbleSort(dll);
    //Sorters<int>::InsertionSort(dll);

    std::this_thread::sleep_for(std::chrono::seconds(15));
    return 0;
}
