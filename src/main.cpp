#include "DynamicArray.h"
#include <iostream>

int main(){
    std::cout << "=== Задание 1 ===\n";
    DynamicArray<double> arr(5);
    arr.set(0, 50);
    arr.set(1, -20);
    arr.print();
    try{
        arr.set(0, 101);
    }catch(const std::invalid_argument& err){
        std::cerr << "Ошибка: " << err.what() << "\n";
    }

    try{
        arr.set(100, 1);
    }catch(const std::out_of_range& err){
        std::cerr << "Ошибка: " << err.what() << "\n";
    }

    arr.print();

    std::cout << "\n=== Задание 2 ===\n";
    DynamicArray<double> b(arr);
    try{
        DynamicArray<int> c(10000000000000);
    }catch(const std::bad_alloc& err){
        std::cerr << "Ошибка: " << err.what() << "\n";
    }
    b.print();
    arr.print();

    std::cout << "\n=== Задание 3 ===\n";
    try{
        b.push_back(150);
    }catch(const std::invalid_argument& err){
        std::cerr << "Ошибка: " << err.what() << "\n";
    }
    b.print();

    std::cout << "\n=== Задание 4 ===\n";
    b.sub(arr);
    b.print();
    b.add(arr);
    b.print();
}