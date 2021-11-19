#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

int	main()
{
	std::cout <<"----- test1 -----" << std::endl;
	try {
		ShrubberyCreationForm sformB("sformB");
		Bureaucrat a("a", 130);
		sformB.execute(a);
		a.signForm(sformB);
		sformB.execute(a);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test2 -----" << std::endl;
	try {
		ShrubberyCreationForm sformB("a");
		Bureaucrat b("a", 140);
		b.signForm(sformB);
		sformB.execute(b);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test3 -----" << std::endl;
	try {
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
