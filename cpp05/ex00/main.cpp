#include <iostream>

#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
    try {
        std::cout << GREEN << "--- grade 0 ---" << RESET << std::endl;
        Bureaucrat a("a", 0);
        std::cout << a << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 151 ---" << RESET << std::endl;
        Bureaucrat b("b", 151);
        std::cout << b << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 1, upGrade---" << RESET << std::endl;
        Bureaucrat c("c", 1);
        std::cout << c << std::endl;
        c.upGrade();
        std::cout << c << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 150, downGrade ---" << RESET
                  << std::endl;
        Bureaucrat e("e", 150);
        std::cout << e << std::endl;
        e.downGrade();
        std::cout << e << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 2, upGrade ---" << RESET << std::endl;
        Bureaucrat d("d", 2);
        std::cout << d << std::endl;
        d.upGrade();
        std::cout << d << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 149, downGrade ---" << RESET
                  << std::endl;
        Bureaucrat e("e", 149);
        std::cout << e << std::endl;
        e.downGrade();
        std::cout << e << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
