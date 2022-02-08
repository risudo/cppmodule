#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    ~Array();
    Array &operator=(Array const &other);
    unsigned int size() const;
    T &operator[](unsigned int n);

private:
    T *arr_;
    unsigned int size_;
};

template <typename T>
Array<T>::Array() : arr_(new T[0]), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(Array const &other) : arr_(NULL) {
    *this = other;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr_;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
    if (this != &other) {
        size_ = other.size();
        delete[] arr_;
        arr_ = new T[size_];

        for (unsigned int i = 0; i < size_; i++) {
            arr_[i] = other.arr_[i];
        }
    }
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

template <typename T>
T &Array<T>::operator[](unsigned int n) {
    if (n >= size_) {
        throw std::exception();
    }
    return (arr_[n]);
}

#endif
