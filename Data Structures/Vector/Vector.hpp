#include "Vector.h"

template<typename T>
Vector<T>::Vector(): data(nullptr), size(0) {}

template<typename T>
explicit Vector<T>::Vector(size_t initialSize): data(new T[initialSize]), size(initialSize), capacity(initialSize) {
    for (int i = 0; i < size; ++i) {
        data[i] = new T(); // default constructor
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other): data(new T[other.size]), size(other.size), capacity(other.capacity) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}