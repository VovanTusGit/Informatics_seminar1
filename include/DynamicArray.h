#pragma once

#include <cstddef>

class DynamicArray {
private:
    int* data;
    size_t size;
public:
    DynamicArray(size_t len);
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);

    void print();
    void set(size_t index, int value);
    int get(size_t index);
    void push_back(int value);

    void add(const DynamicArray& other);
    void sub(const DynamicArray& other);
};