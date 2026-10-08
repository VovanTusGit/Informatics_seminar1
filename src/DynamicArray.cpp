#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray(size_t n) : size(n) {
    if (size == 0) {
        data = nullptr;
        return;
    }
    data = new int[size]();
}

DynamicArray::~DynamicArray() {
    delete[] data;
    data = nullptr;
}

void DynamicArray::print() const {
    std::cout << "[";
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int DynamicArray::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

void DynamicArray::set(size_t index, int value) {
    if(index >= size){
        throw std::out_of_range("Index out of bounds");
    }
    if(value < -100 || value > 100){
        throw std::range_error("Value must be in range [-100, 100]");
    }
    data[index] = value;
}

size_t DynamicArray::getSize() const {
    return size;
}

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size) {
    if(size == 0){
        data = nullptr;
        return;
    }
    data = new int[size];
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}
