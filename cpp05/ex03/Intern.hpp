#ifndef INTERN_HPP
# define INTERN_HPP
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	virtual ~Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	Form *makeForm(std::string const &form, std::string const &target);

private:
	Form *getPresidentialPardonForm(std::string const &target) const;
	Form *getRobotomyRequestForm(std::string const &target) const;
	Form *getShrubberyCreationForm(std::string const &target) const;
};

#endif
