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
        std::cout << GREEN << "--- grade 1 ---" << RESET << std::endl;
        Bureaucrat c("a", 1);
        std::cout << c << std::endl;
        c.upGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << GREEN << "--- grade 151 ---" << RESET << std::endl;
        Bureaucrat d("d", 150);
        std::cout << d << std::endl;
        d.downGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
