#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void incrementAndPut(T a) {
    a += 1;
    std::cout << a << std::endl;
}

template <typename T>
void putElement(T const &a) {
    std::cout << a << std::endl;
}

template <typename T>
void iter(const T arr[], std::size_t len, void (*func)(T const &)) {
    for (std::size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T>
void iter(T arr[], std::size_t len, void (*func)(T &)) {
    for (std::size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

#endif  // ITER_HPP
