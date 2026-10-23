#pragma once

#include <cstddef>
#include <type_traits>

template <class T>

class DynamicArray {
private:
    T* data;
    size_t size;
public:
    DynamicArray(size_t len);
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);

    void print();
    void set(size_t index, T value);
    T get(size_t index);
    void push_back(T value);

    void add(const DynamicArray& other);
    void sub(const DynamicArray& other);
};
