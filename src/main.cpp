#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray arr(5);
    arr.set(0, 10);
    arr.set(1, -50);
    arr.print();

    return 0;
}
