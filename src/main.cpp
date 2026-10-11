#include "DynamicArray.h"
#include <iostream>

int main(){
    std::cout << "=== Задание 1 ===\n";
    DynamicArray arr(5);
    arr.print();
    arr.set(0, 1);
    arr.print();

    std::cout << "\n=== Задание 2 ===\n";
    DynamicArray b(arr);
    b.set(1, 2);
    arr.print();
    b.print();

    std::cout << "\n=== Задание 3 ===\n";
    b.push_back(6);
    b.print();
}