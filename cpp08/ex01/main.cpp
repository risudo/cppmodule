#include <iostream>

#include "span.hpp"

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
// shotestSpanのテスト
// - 負の値だけ
// - 正の値だけ
// - 負の値と正の値
// - 10000個のvalue
// - int_minからint_maxまでのspan
//

void exeptionTest() {
    try {
        span span(1);
        span.addNumber(1);
        span.addNumber(3);
        std::cout << "add test NG" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        span span(5);
        span.longestSpan();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        span span(5);
        span.shotestSpan();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main() {
	exeptionTest();
    try {
        span span(3);
        span.printValue();
        span.addNumber(-1);
        span.addNumber(-2);
        span.addNumber(-100);
        span.printValue();
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shotestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
