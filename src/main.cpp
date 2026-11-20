#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <utility>

void show(DynamicArray<int> arr) {
    std::cout << "В функции: " << arr << "\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    DynamicArray<int> first(3);
    first[0] = 10;
    first[1] = 20;
    first[2] = 30;

    std::cout << "=== Копирование ===\n";
    show(first);
    std::cout << "Исходный массив: " << first << "\n";

    DynamicArray<int> second(3);
    second[0] = 40;
    second[1] = 50;
    second[2] = 60;

    std::cout << "\n=== Перемещение ===\n";
    show(std::move(second));
    std::cout << "Исходный массив: " << second << "\n";

    DynamicArray<int> third(2);
    third = first;

    std::cout << "\n=== Копирующее присваивание ===\n";
    std::cout << third << "\n";

    DynamicArray<int> fourth(2);
    fourth = std::move(first);

    std::cout << "\n=== Move-присваивание ===\n";
    std::cout << "Новый массив: " << fourth << "\n";
    std::cout << "Старый массив: " << first << "\n";

    return 0;
}