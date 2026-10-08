#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray arr1(5);
    arr1.set(0, 10);
    arr1.set(1, -50);

    DynamicArray arr2 = arr1;

    arr2.set(0, 67);
    
    std::cout << "arr1: ";
    arr1.print();

    std::cout << "\narr2: ";
    arr2.print();
    return 0;
}
