#include <iostream>
#include <string>

#include "Array.hpp"
#include "test.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[39m"

/*
void end() __attribute__((destructor));

void end() {
    std::cout << GREEN << "\n---- leaks test ----" << RESET << std::endl;
    system("leaks -q a.out");
}
*/

int main() {
    {
        std::cout << GREEN << "---- int test ----" << RESET << std::endl;
        unsigned int size = 4;
        int contents[] = {0, 1, 2, 3};
        Array<int> intArr(size);
        test(intArr, contents);
    }
    {
        std::cout << GREEN << "\n---- string test ----" << RESET << std::endl;
        unsigned int size = 3;
        char contents[] = {'a', 'x', '1'};
        Array<char> stringArray(size);
        test(stringArray, contents);
    }
}

