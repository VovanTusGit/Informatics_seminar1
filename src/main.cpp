#include "dynamicArray.h"
#include <iostream>
#include <windows.h>

int main(){
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "=== Задание 1: Конструктор и обнуление ===\n";
    {
        DynamicArray arr(5);
        arr.set(0, 67);
        arr.print();
        std::cout << "\n";
    }

    std::cout << "\n=== Задание 2: Конструктор копиррования ===\n";
    {
        DynamicArray arr1(3);
        arr1.set(0, 10);
        arr1.set(1, 20);
        arr1.set(2, 30);

        DynamicArray arr2 = arr1;
        arr2.set(0, 67);

        std::cout << "arr1: ";
        arr1.print();

        std::cout << "\narr2: ";
        arr2.print();

        std::cout << "\n";
    }

    std::cout << "\n=== Задание 3: push_back ===\n";
    {
        DynamicArray arr(2);
        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(40);

        bool check = arr.push_back(200);
        std::cout << "push_back(200) вернул " << (check ? "true" : "false") << "\n";

        std::cout << "Итоговый массив: ";
        arr.print();

        std::cout << " (size = " << arr.getSize() << ")\n"; 
    }

    std::cout << "\n=== Задание 4: add / sub ===\n";
    {
        DynamicArray arr1(3);
        arr1.set(0, 10);
        arr1.set(1, 20);
        arr1.set(2, 30);

        DynamicArray arr2(3);
        arr2.set(0, 1);
        arr2.set(1, 2);
        arr2.set(2, 3);

        std::cout << "До сложения (одинаковые): ";
        arr1.print();

        arr1.add(arr2);

        std::cout << "После arr1.add(arr2): ";
        arr1.print();

        // Сложение - первый массив короче
        DynamicArray arr3(2);
        arr3.set(0, 5);
        arr3.set(1, 10);

        DynamicArray arr4(4);
        arr4.set(0, 1);
        arr4.set(1, 2);
        arr4.set(2, 3);
        arr4.set(3, 4);

        std::cout << "\nДо сложения (arr3 короче): ";
        arr3.print();

        arr3.add(arr4);

        std::cout << "После arr3.add(arr4): ";
        arr3.print();
        std::cout << "Размер arr3: " << arr3.getSize() << " (не изменился)\n";

        // Сложение - второй массив короче
        DynamicArray arr5(4);
        arr5.set(0, 10);
        arr5.set(1, 20);
        arr5.set(2, 30);
        arr5.set(3, 40);

        DynamicArray arr6(2);
        arr6.set(0, -5);
        arr6.set(1, -10);

        std::cout << "\nДо сложения (arr5 длиннее): ";
        arr5.print();

        arr5.add(arr6);

        std::cout << "После arr5.add(arr6): ";
        arr5.print();

        // Вычитание 
        DynamicArray arr7(3);
        arr7.set(0, 100);
        arr7.set(1, 50);
        arr7.set(2, 10);

        DynamicArray arr8(2);
        arr8.set(0, 10);
        arr8.set(1, 5);

        std::cout << "\nДо вычитания: ";
        arr7.print();

        arr7.sub(arr8);

        std::cout << "После arr7.sub(arr8): ";
        arr7.print();
    }
    return 0;
}
