#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
    std::cout << GREEN << "--- grade_to_sign = 151 ---" << RESET << std::endl;
    try {
        Form formA("formA", 151, 1);
        std::cout << formA << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- grade_to_sign = 0 ---" << RESET << std::endl;
    try {
        Form formA("formA", 0, 1);
        std::cout << formA << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- grade_to_execute = 151 ---" << RESET
              << std::endl;
    try {
        Form formA("formA", 1, 151);
        std::cout << formA << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- grade_to_execute = 0 ---" << RESET
              << std::endl;
    try {
        Form formA("formA", 1, 0);
        std::cout << formA << std::endl;  // should not output
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- try to sign twice ---" << RESET << std::endl;
    try {
        Form form("form", 40, 30);
        std::cout << form << std::endl;
        Bureaucrat a("bureaucratA", 35);
        std::cout << a << std::endl;
        a.signForm(form);
        std::cout << form << std::endl;
        a.signForm(form);  // cannot sign
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- cannot sign  ---" << RESET << std::endl;
    try {
        Form formC("formC", 40, 30);
        std::cout << formC << std::endl;
        Bureaucrat b("bureaucratB", 50);
        std::cout << b << std::endl;
        b.signForm(formC);
        std::cout << formC << std::endl;  // signed shold be false
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
