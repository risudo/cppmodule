#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#include "Array.hpp"

#define GREEN "\033[32m"
#define CIAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[39m"

template <typename T>
void printArray(Array<T> array, std::string name) {
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << name << "[" << i << "]" << std::endl;
        std::cout << array[i] << std::endl;
    }
}

template <typename T>
void printArrayAndCopy(Array<T> array, Array<T> copy) {
    for (unsigned int i = 0; i < array.size(); i++) {
        std::cout << "array"
                  << "[" << i << "]: " << array[i] << ", copy[" << i
                  << "]: " << copy[i] << std::endl;
    }
}

template <typename T>
void test(Array<T> array, T contents[]) {
    try {
        std::cout << CIAN << "-- subscript operator test --" << RESET
                  << std::endl;
        std::cout << "size: " << array.size() << std::endl;
        for (unsigned int i = 0; i < array.size(); i++) {
            array[i] = contents[i];
        }
        printArray(array, "array");

        std::cout << CIAN << "\n-- copy test --" << RESET << std::endl;
        std::cout << "- copy constructor call -" << std::endl;
        Array<T> copy(array);
        copy[0] += 1;
        printArrayAndCopy(array, copy);

        std::cout << "- assignment operator call -" << std::endl;
        Array<T> copy2(100);
        copy2 = array;
        copy2[1] += 1;
        printArrayAndCopy(array, copy2);

        std::cout << CIAN << "\n-- exeption test --" << RESET << std::endl;
        std::cout << "array[" << array.size() << "]" << std::endl;
        std::cout << array[array.size()] << std::endl;  // should not output
        std::cout << RED << "exeption test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << "catch " << e.what() << std::endl;
    }
}

#endif  // TEST_HPP
