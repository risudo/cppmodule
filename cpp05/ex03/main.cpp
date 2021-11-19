#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout <<"----- test1 -----" << std::endl;
	try {
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat a("a", 10);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf != NULL)
		{
			a.signForm(*rrf);
			a.executeForm(*rrf);
			delete rrf;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout <<"\n----- test2 -----" << std::endl;
	try {
		Intern someRandomIntern;
		Form *rrf;
		Bureaucrat b("b", 10);

		rrf = someRandomIntern.makeForm("aaaaaaaaaaaaaaaa", "Bender");
		if (rrf != NULL)
		{
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
