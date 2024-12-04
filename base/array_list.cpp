// array_list.cpp

/*
    The implement of ArrayList.

    created on 2024/12/4 by yezq.
*/

#include "array_list.hpp"
#include <utility>
#include <iostream>


template <typename T>
mpvm::ArrayList<T>::ArrayList(int n) {
    _length = n;
    _size   = 0;
    _array  = new T[n];
}

template <typename T>
void mpvm::ArrayList<T>::add(const T& t) {
    if (_size >= _length)
        expand();

    _array[_size++] = t;
}

template <typename T>
void mpvm::ArrayList<T>::insert(int index, const T& t) {
    add(nullptr);

    for(int i = _size; i > index; i--) 
        _array[i] = _array[i - 1];

    _array[index] = t;
}

template <typename T>
void mpvm::ArrayList<T>::expand() {
    T* new_array = new T[_length << 1];

    for (int i = 0; i < _length; i++) 
        new_array[i] = std::move(_array[i]);

    delete[] _array;

    _array = new_array;

    _length <<= 1;
    std::cout << "expand an array to " << _length << ", size is " << _size << std::endl;
}

template <typename T>
int mpvm::ArrayList<T>::size() const {
    return _size;
}

template <typename T>
int mpvm::ArrayList<T>::length() const {
    return _length;
}

template <typename T>
T mpvm::ArrayList<T>::get(int index) const {
    return _array[index];
}

template<typename T>
void mpvm::ArrayList<T>::set(int index, const T& t) {
    if (_size <= index) 
        _size = index + 1;

    while (_size > _length)
        expand();

    _array[index] = t;
}

template <typename T>
T mpvm::ArrayList<T>::pop() {
    return _array[--_size];
}