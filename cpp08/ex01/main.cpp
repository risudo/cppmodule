#include <iostream>

#include "span.hpp"

#define GREEN "\033[32m"
#define CIAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[39m"

void exceptionTest() {
    std::cout << GREEN << "--- exceptionTest ---" << RESET << std::endl;
    try {
        std::cout << CIAN << "- trying addNumber 2 times size 1 --" << RESET
                  << std::endl;
        Span span(1);
        span.addNumber(1);
        span.addNumber(3);  // cannot add
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying longestSpan before addNumber -" << RESET
                  << std::endl;
        Span span(5);
        span.longestSpan();  // cannot span
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying longestSpan after addNumber once -"
                  << RESET << std::endl;
        Span span(5);
        span.addNumber(3);
        span.longestSpan();  // cannot span
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying shortestSpan before addNumber -" << RESET
                  << std::endl;
        Span span(5);
        span.shortestSpan();  // cannot span
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying shortestSpan after addNumber once -"
                  << RESET << std::endl;
        Span span(5);
        span.addNumber(3);
        span.shortestSpan();  // cannot span
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void printSpanInfo(Span &span) {
    std::cout << "max strage size: " << span.getMaxStorageSize() << std::endl;
    std::cout << "strage size    : " << span.getStorageSize() << std::endl;
    std::cout << "longestSpan    : " << span.longestSpan() << std::endl;
    std::cout << "shortestSpan   : " << span.shortestSpan() << std::endl;
}

void simpleTest(unsigned int size, int start) {
    try {
        Span span(size);
        for (unsigned int i = 0; i < size; i++) {
            span.addNumber(start);
            ++start;
        }
        span.printStorageValues();
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void simpleTests() {
    std::cout << GREEN << "\n--- simpleTest  ---" << RESET << std::endl;
    std::cout << CIAN << "- positive values -" << RESET << std::endl;
    simpleTest(5, 0);
    std::cout << CIAN << "- negatgive values -" << RESET << std::endl;
    simpleTest(5, -10);
    std::cout << CIAN << "- positive and negatgive values -" << RESET
              << std::endl;
    simpleTest(10, -5);
}

void largeSizeTest() {
    std::cout << GREEN << "\n--- largeSizeTest ---" << RESET << std::endl;
    try {
        unsigned int size = 1000000;
        std::vector<int> intVec(size);
        intVec[10] = -100;
        intVec[1000] = 500;
        Span span(1000000);
        std::cout << "large size: "
                  << std::distance(intVec.begin(), intVec.end()) << std::endl;
        span.addNumber(intVec.begin(), intVec.end());
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void maxRangeTest() {
    largeSizeTest();
    std::cout << GREEN << "\n--- maxRangeTest ---" << RESET << std::endl;
    try {
        Span span(2);
        span.addNumber(INT_MIN);
        span.addNumber(INT_MAX);
        span.printStorageValues();
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    exceptionTest();
    simpleTests();
    maxRangeTest();
}
