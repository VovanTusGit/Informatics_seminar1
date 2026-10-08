#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray(size_t n) : size(n), new_size(n){
    if (size == 0) {
        data = nullptr;
        return;
    }
    data = new int[new_size]();
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

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), new_size(other.new_size) {
    if(size == 0){
        data = nullptr;
        return;
    }
    data = new int[new_size];
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

bool DynamicArray::push_back(int value){
    if(value < -100 || value > 100){
        std::cerr << "Error: Value " << value << " is out of range [-100, 100]" << std::endl;
        return false;
    }

    if(size >= new_size){
        size_t final_size = (new_size) ? 1 : new_size * 2;

        int* new_data = new int[final_size];

        for(size_t i = 0; i < size; i++){
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        new_size = final_size;
    }

    data[size] = value;
    ++size;

    return true;
}

void DynamicArray::add(const DynamicArray& other){
    for(size_t i = 0; i < size; i++) {
        int val = (i < other.size) ? other.data[i] : 0;
        data[i] += val;
    }
}

void DynamicArray::sub(const DynamicArray& other){
    for(size_t i = 0; i < size; i++) {
        int val = (i < other.size) ? other.data[i] : 0;
        data[i] -= val;
    }
}
