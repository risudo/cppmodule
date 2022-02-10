#include <iostream>
#include <set>
#include <vector>

#include "easyfind.hpp"
#include "testEasyfind.hpp"

int main() {
    std::vector<int> intVec;
    std::size_t size = 10;

    for (std::size_t i = 1; i < size; i++) {
        intVec.push_back(i);
    }
    for (std::size_t i = 0; i < intVec.size(); i++) {
        std::cout << "vec[" << i << "]: " << intVec[i] << std::endl;
    }
    testEasyfind(intVec, 3);
    testEasyfind(intVec, 9);
    testEasyfind(intVec, 10);
}
