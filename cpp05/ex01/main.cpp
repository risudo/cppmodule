#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout <<"----- test1 -----" << std::endl;
	try {
		Form formA("formA", 40, 30);
		std::cout << formA << std::endl;
		Bureaucrat a("a", 35);
		std::cout << a << std::endl;
		a.signForm(formA);
		std::cout << formA << std::endl;
		a.signForm(formA);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test2 -----" << std::endl;
	try {
		Form formB("formB", 151, 1);
		std::cout << formB << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test3 -----" << std::endl;
	try {
		Form formC("formC" , 10, 30);
		std::cout << formC << std::endl;
		Bureaucrat b("b", 20);
		std::cout << b << std::endl;
		b.signForm(formC);
		std::cout << formC << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
