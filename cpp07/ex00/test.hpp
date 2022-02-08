#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#include "whatever.hpp"

template <typename T>
void test(T &a, T &b) {
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "swap" << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
}

#endif  // TEST_HPP
