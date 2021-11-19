#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat a("a", 0);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b("b", 151);
		std::cout << b << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat c("a", 1);
		std::cout << c << std::endl;
		c.upGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat d("d", 150);
		std::cout << d << std::endl;
		d.downGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}
