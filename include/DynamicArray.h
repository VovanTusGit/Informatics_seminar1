#pragma once

#include <cstddef>

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    explicit DynamicArray(size_t n);
    ~DynamicArray();

    void print() const;
    int get(size_t index) const;
    void set(size_t index, int value);

    size_t getSize() const;
};
