#include "DynamicArray.h"
#include <iostream>

int main(){
    std::cout << "=== Задание 1 ===\n";
    DynamicArray arr(5);
    arr.print();
    arr.set(0, 1);
    std::cout << "\n";
    arr.print();
}