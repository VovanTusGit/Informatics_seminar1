#include "DynamicArray.h"
#include <iostream>

template <class T>
DynamicArray<T>::DynamicArray(size_t len) : size(len){
    data = new T[len]();
}

template <class T>
DynamicArray<T>::~DynamicArray(){
    delete[] data;
    data = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : size(other.size){
    data = new T[size];
    for(size_t i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

template <class T>
void DynamicArray<T>::print(){
    std::cout << "[";
    for(size_t i = 0; i < size; i++){
        std::cout << data[i];
        if(i != size-1) std::cout << ", ";
    }
    std::cout << "]\n";
}

template <class T>
void DynamicArray<T>::set(size_t index, T value){
    if(index >= size || static_cast<int>(index) < 0){
        throw std::out_of_range("Index out of bounds");
    }
    if constexpr(std::is_integral_v<T>){
        if(value < -100 || value > 100){
            throw std::invalid_argument("Value must be in range[-100,100]");
        }
    }
    data[index] = value;
}

template <class T>
T DynamicArray<T>::get(size_t index){
    if(index > size || static_cast<int>(index) < 0){
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <class T>
void DynamicArray<T>::push_back(T value){
    if(value < -100 || value > 100){
        throw std::invalid_argument("Value must be in range[-100,100]");
    }
    size++;
    T* new_data = new T[size];
    for(size_t i = 0; i < size-1; i++){
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;

    data[size-1] = value;
}

template <class T>
void DynamicArray<T>::add(const DynamicArray& other){
    size_t min_size = (size < other.size) ? size : other.size;

    for(size_t i = 0; i < min_size; i++){
        data[i] += other.data[i];
    }
}

template <class T>
void DynamicArray<T>::sub(const DynamicArray& other){
    size_t min_size = (size < other.size) ? size : other.size;

    for(size_t i = 0; i < min_size; i++){
        data[i] -= other.data[i];
    }
}

template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<float>;