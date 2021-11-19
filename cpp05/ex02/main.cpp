#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	std::cout <<"----- test1 ShrubberyCreationForm-----" << std::endl;
	try {
		ShrubberyCreationForm sformA("sformA");
		Bureaucrat a("a", 130);
		a.signForm(sformA);
		a.executeForm(sformA);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test2 -----" << std::endl;
	try {
		ShrubberyCreationForm sformB("a");
		Bureaucrat b("b", 140);
		b.signForm(sformB);
		b.executeForm(sformB);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test3 Robotization -----" << std::endl;
	try {
		RobotomyRequestForm rformA("rformA");
		Bureaucrat c("c", 40);
		c.signForm(rformA);
		c.executeForm(rformA);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test3 PresidentialPardonForm -----" << std::endl;
	try {
		PresidentialPardonForm pformA("pformA");
		Bureaucrat d("e", 5);
		d.signForm(pformA);
		d.executeForm(pformA);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
