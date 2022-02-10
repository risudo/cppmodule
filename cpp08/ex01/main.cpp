#include <iostream>

#include "span.hpp"

#define GREEN "\033[32m"
#define CIAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[39m"

void exeptionTest() {
    std::cout << GREEN << "--- exeptionTest ---" << RESET << std::endl;
    try {
        std::cout << CIAN << "- trying addNumber 2 times size 1 --" << RESET
                  << std::endl;
        span span(1);
        span.addNumber(1);
        span.addNumber(3);
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying longestSpan before addNumber -" << RESET
                  << std::endl;
        span span(5);
        span.longestSpan();
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying longestSpan after addNumber once -"
                  << RESET << std::endl;
        span span(5);
        span.addNumber(3);
        span.longestSpan();
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying shortestSpan before addNumber -" << RESET
                  << std::endl;
        span span(5);
        span.shortestSpan();
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << CIAN << "- trying shortestSpan after addNumber once -"
                  << RESET << std::endl;
        span span(5);
        span.addNumber(3);
        span.shortestSpan();
        std::cout << RED << "test NG" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void printSpanInfo(span &span) {
    std::cout << "max strage size: " << span.getMaxStrageSize() << std::endl;
    std::cout << "strage size    : " << span.getStrageSize() << std::endl;
    std::cout << "longestSpan    : " << span.longestSpan() << std::endl;
    std::cout << "shortestSpan   : " << span.shortestSpan() << std::endl;
}

void simpleTest(unsigned int size, int start) {
    try {
        span span(size);
        for (unsigned int i = 0; i < size; i++) {
            span.addNumber(start);
            ++start;
        }
        span.printStrageValues();
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void simpleTests() {
    std::cout << GREEN << "--- simpleTest  ---" << RESET << std::endl;
    std::cout << CIAN << "- positive values -" << RESET << std::endl;
    simpleTest(5, 0);
    std::cout << CIAN << "- negatgive values -" << RESET << std::endl;
    simpleTest(5, -10);
    std::cout << CIAN << "- positive and negatgive values -" << RESET
              << std::endl;
    simpleTest(10, -5);
}

void largeSizeTest() {
    std::cout << GREEN << "--- largeSizeTest ---" << RESET << std::endl;
    try {
        unsigned int size = 10000;
        std::vector<int> intVec(size);
        intVec[10] = -100;
        intVec[1000] = 500;
        span span(size);
        span.addNumber(intVec.begin(), intVec.end());
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void maxRangeTest() {
    largeSizeTest();
    std::cout << GREEN << "--- maxRangeTest ---" << RESET << std::endl;
    try {
        span span(2);
        span.addNumber(INT_MIN);
        span.addNumber(INT_MAX);
        span.printStrageValues();
        printSpanInfo(span);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
    exeptionTest();
    simpleTests();
    maxRangeTest();
}

// 例外テスト
// - サイズ以上のadd
// - spanできない
//   - 数字がない
//   - 数字が1つ
// longestSpanのテスト
// - 負の値だけ
// - 正の値だけ
// - 負の値と正の値
// - 10000個のvalue
// - int_minからint_maxまでのspan
// shortestSpanのテスト
// - 負の値だけ
// - 正の値だけ
// - 負の値と正の値
// - 10000個のvalue
// - int_minからint_maxまでのspan
//

