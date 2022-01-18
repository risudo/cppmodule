#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main() {
    std::cout << GREEN << "--- ShrubberyCreationForm ---" << std::endl;
    std::cout << "- cannot sign- " << RESET << std::endl;
    try {
        ShrubberyCreationForm sformA("home");
        Bureaucrat bureaucrat("bureaucrat", 146);
        std::cout << sformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(sformA);
        bureaucrat.executeForm(sformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "- cannot execute -" << RESET << std::endl;
    try {
        ShrubberyCreationForm sformB("home");
        Bureaucrat bureaucrat("bureaucrat", 140);
        std::cout << sformB << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(sformB);
        bureaucrat.executeForm(sformB);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "- can execute -" << RESET << std::endl;
    try {
        ShrubberyCreationForm sformB("home");
        Bureaucrat bureaucrat("bureaucrat", 100);
        std::cout << sformB << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(sformB);
        bureaucrat.executeForm(sformB);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- RobotomyRequestForm ---" << std::endl;
    std::cout << "- cannot sign -" << RESET << std::endl;
    try {
        RobotomyRequestForm rformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 80);
        std::cout << rformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(rformA);
        bureaucrat.executeForm(rformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "- cannot execute -" << RESET << std::endl;
    try {
        RobotomyRequestForm rformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 50);
        std::cout << rformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(rformA);
        bureaucrat.executeForm(rformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "can execute" << RESET << std::endl;
    try {
        RobotomyRequestForm rformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 40);
        std::cout << rformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(rformA);
        bureaucrat.executeForm(rformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << GREEN << "\n--- PresidentialPardonForm ---" << std::endl;
    std::cout << "- cannot sign -" << RESET << std::endl;
    try {
        PresidentialPardonForm pformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 26);
        std::cout << pformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(pformA);
        bureaucrat.executeForm(pformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "- cannot execute -" << RESET << std::endl;
    try {
        PresidentialPardonForm pformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 6);
        std::cout << pformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(pformA);
        bureaucrat.executeForm(pformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "- can execute -" << RESET << std::endl;
    try {
        PresidentialPardonForm pformA("hoge");
        Bureaucrat bureaucrat("bureaucrat", 5);
        std::cout << pformA << std::endl;
        std::cout << bureaucrat << std::endl;
        bureaucrat.signForm(pformA);
        bureaucrat.executeForm(pformA);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
