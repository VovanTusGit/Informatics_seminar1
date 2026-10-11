#pragma once

#include <cstddef>

class DynamicArray {
private:
    int* data;
    size_t size;
public:
    DynamicArray(size_t len);
    ~DynamicArray();

    void print();
    void set(size_t index, int value);
    int get(size_t index);
};