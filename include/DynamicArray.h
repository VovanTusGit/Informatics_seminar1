#pragma once

#include <cstddef>
#include <type_traits>
#include <stdexcept>
#include <typeinfo>
#include <cmath>
#include <iostream>

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

    double distance(const DynamicArray& other) const;

    friend std::ostream& operator<<(std::ostream& out, const DynamicArray<T>& arr){
        out << "[";
        for (std::size_t i = 0; i < arr.size; i++) {
            out << arr.data[i];
            if (i != arr.size - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

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
    std::cout << *this << "\n";
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
    if constexpr(std::is_integral_v<T>){
        if(value < -100 || value > 100){
            throw std::invalid_argument("Value must be in range[-100,100]");
        }
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

template <class T>
double DynamicArray<T>::distance(const DynamicArray& other) const{
    if constexpr (std::is_arithmetic_v<T>) {
        if(size != other.size) {
            throw std::invalid_argument("Arrays must have the same size");
        }

        double sum = 0.0;
        for(std::size_t i = 0; i < size; i++) {
            double difference = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += difference * difference;
        }
        return std::sqrt(sum);
    }else{
        throw std::bad_typeid();
    }
}