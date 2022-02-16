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

    std::cout << std::endl;
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

    testEasyfind(intSet, 0);     // will not find
    testEasyfind(intSet, -100);  // will find
}

int main() {
    vecterTest();
    setTest();
}
