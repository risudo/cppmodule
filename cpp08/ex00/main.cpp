#include <deque>
#include <iostream>
#include <set>
#include <vector>

#include "easyfind.hpp"
#include "testEasyfind.hpp"

#define GREEN "\033[32m"
#define CIAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[39m"

void vecterTest() {
    std::cout << GREEN << "--- vectorTest --- " << RESET << std::endl;
    std::vector<int> intVec;
    std::size_t size = 10;

    for (std::size_t i = 1; i < size; i++) {
        intVec.push_back(i);
    }

    for (std::size_t i = 0; i < intVec.size(); i++) {
        std::cout << "[" << i << "]: " << intVec[i] << "  ";
    }

    std::cout << std::endl << std::endl;
    testEasyfind(intVec, 0);   // will not find
    testEasyfind(intVec, 1);   // will find
    testEasyfind(intVec, 3);   // will find
    testEasyfind(intVec, 9);   // will find
    testEasyfind(intVec, 10);  // will not find
}

void setTest() {
    std::cout << GREEN << "--- setTest ---" << RESET << std::endl;
    std::set<int> intSet;

    intSet.insert(-100);
    intSet.insert(500);
    intSet.insert(INT_MAX);

    for (std::set<int>::iterator it = intSet.begin(); it != intSet.end();
         it++) {
        std::size_t i = 0;
        std::cout << "[" << i++ << "]: " << *it << "  ";
    }
    std::cout << std::endl << std::endl;
    testEasyfind(intSet, 0);     // will not find
    testEasyfind(intSet, -100);  // will find
}

void dequeTest() {
    std::cout << GREEN << "--- dequeTest ---" << RESET << std::endl;
    std::deque<int> intDeque;

    intDeque.push_back(200);
    intDeque.push_back(1000);
    intDeque.push_back(10000);

    for (std::deque<int>::iterator it = intDeque.begin(); it != intDeque.end();
         it++) {
        std::size_t i = 0;
        std::cout << "[" << i++ << "]: " << *it << "  ";
    }
    std::cout << std::endl << std::endl;
    testEasyfind(intDeque, 1000);  // will find
}

int main() {
    vecterTest();
    setTest();
    dequeTest();
}
