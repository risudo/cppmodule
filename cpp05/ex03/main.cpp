#include <iostream>

#include "Intern.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
    std::cout << GREEN << "--- robotomy request ---" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        Form* rrf;
        Bureaucrat bureaucrat("bureaucrat", 1);
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf != NULL) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "--- presidential pardon ---" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        Form* rrf;
        Bureaucrat bureaucrat("bureaucrat", 1);
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf != NULL) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "--- shrubbery creation ---" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        Form* rrf;
        Bureaucrat bureaucrat("bureaucrat", 1);
        rrf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (rrf != NULL) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "--- does not match ---" << RESET << std::endl;
    try {
        Intern someRandomIntern;
        Form* rrf;
        Bureaucrat bureaucrat("bureaucrat", 1);
        rrf = someRandomIntern.makeForm("no such form", "Bender");
        if (rrf != NULL) {
            std::cout << *rrf << std::endl;
            bureaucrat.signForm(*rrf);
            bureaucrat.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
