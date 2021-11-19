#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Form *Intern::makeForm(std::string const &form, std::string const &target)
{
	std::string form_list[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	Form *(Intern::*f[3])(std::string const&) const = {
		&Intern::getPresidentialPardonForm,
		&Intern::getRobotomyRequestForm,
		&Intern::getShrubberyCreationForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (form == form_list[i])
		{
			return (this->*f[i])(target);
		}
	}
	std::cout << "The form doesn't match anything" << std::endl;
	return NULL;
}

Form *Intern::getPresidentialPardonForm(std::string const &target) const
{
	return new PresidentialPardonForm(target);
}

Form *Intern::getRobotomyRequestForm(std::string const &target) const
{
	return new RobotomyRequestForm(target);
}

Form *Intern::getShrubberyCreationForm(std::string const &target) const
{
	return new ShrubberyCreationForm(target);
}

