#include "DynamicArray.h"
#include <iostream>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    DynamicArray<int> numbers(3);
    numbers.set(0, 10);
    numbers.set(1, -20);
    numbers.set(2, 30);

    std::cout << "Массив: " << numbers << "\n";

    numbers[0] = 50;
    std::cout << "numbers[0] = " << numbers[0] << "\n";

    DynamicArray<int> copy(numbers);
    std::cout << "Массивы равны: " << (numbers == copy) << "\n";
    std::cout << "Массивы не равны: " << (numbers != copy) << "\n";

    DynamicArray<int> second(3);
    second.set(0, 1);
    second.set(1, 2);
    second.set(2, 3);

    numbers += second;
    numbers -= 5;
    std::cout << "После арифметики: " << numbers << "\n";

    std::cout << "Перебор массива: ";
    for (const auto& x : numbers)
        std::cout << x << " ";

    std::cout << "\n";

    for (auto& x : numbers) x = 10;

    std::cout << "После изменения: " << numbers << "\n";

    DynamicArray<std::string> words(2);
    words.set(0, "Hello");
    words.set(1, "world");
    std::cout << "Строки: " << words << "\n";

    DynamicArray<double> a(2);
    DynamicArray<double> b(2);

    a.set(0, 1.0);
    a.set(1, 2.0);
    b.set(0, 4.0);
    b.set(1, 6.0);

    std::cout << "Расстояние: " << a.distance(b) << "\n";
    return 0;
}