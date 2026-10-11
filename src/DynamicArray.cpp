#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(size_t len) : size(len){
    data = new int[len]();
}

DynamicArray::~DynamicArray(){
    delete[] data;
    data = nullptr;
}

DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size){
    data = new int[size];
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

void DynamicArray::print(){
    std::cout << "[";
    for(size_t i = 0; i < size; i++){
        std::cout << data[i];
        if(i != size-1) std::cout << ", ";
    }
    std::cout << "]\n";
}

void DynamicArray::set(size_t index, int value){
    if(index > size || static_cast<int>(index) < 0){
        throw std::out_of_range("Index out of bounds");
    }
    if(value < -100 || value > 100){
        throw std::range_error("Value must be in range [-100, 100]");
    }
    data[index] = value;
}

int DynamicArray::get(size_t index){
    if(index > size || static_cast<int>(index) < 0){
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

void DynamicArray::push_back(int value){
    if(value < -100 || value > 100){
        throw std::range_error("Value must be in range [-100, 100]");
    }
    size++;
    int* new_data = new int[size]();
    for(size_t i = 0; i < size-1; i++){
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;

    data[size-1] = value;
}