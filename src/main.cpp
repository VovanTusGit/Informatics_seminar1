#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "=== Проверка целочисленного массива ===\n";

    DynamicArray<int> numbers(3);
    numbers.set(0, 10);
    numbers.set(1, -20);
    numbers.set(2, 30);
    std::cout << "Массив: " << numbers << "\n";

    try {
        numbers.set(0, 150);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "Ошибка значения: " << err.what() << "\n";
    }

    std::cout << "\n=== Оператор << ===\n";

    DynamicArray<double> first(3);
    first.set(0, 1.0);
    first.set(1, 2.0);
    first.set(2, 3.0);

    DynamicArray<double> second(3);
    second.set(0, 4.0);
    second.set(1, 5.0);
    second.set(2, 6.0);

    std::cout << "Первый массив: " << first << "\n";
    std::cout << "Второй массив: " << second << "\n";

    std::cout << "\n=== Евклидово расстояние ===\n";
    try {
        std::cout << "Расстояние: " << first.distance(second) << "\n";
    }
    catch (const std::invalid_argument& err) {
        std::cout << "Ошибка размера: " << err.what() << "\n";
    }

    std::cout << "\n=== Массивы разного размера ===\n";
    DynamicArray<double> third(2);
    try {
        std::cout << first.distance(third) << "\n";
    }
    catch (const std::invalid_argument& err) {
        std::cout << "Ошибка размера: " << err.what() << "\n";
    }

    std::cout << "\n=== Проверка нечислового типа ===\n";
    DynamicArray<std::string> words(2);
    words.set(0, "Hello");
    words.set(1, "world");
    std::cout << "Массив строк: " << words << "\n";

    try {
        std::cout << words.distance(words) << "\n";
    }
    catch (const std::bad_typeid&) {
        std::cout << "Ошибка: расстояние можно вычислять только для числовых массивов\n";
    }

    std::cout << "\n=== Проверка push_back ===\n";
    numbers.push_back(40);
    std::cout << "После добавления элемента: " << numbers << "\n";

    return 0;
}