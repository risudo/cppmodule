#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
	Form("PresidentialPardonForm", signGrade, execGrade, "")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	Form("PresidentialPardonForm", signGrade, execGrade, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
{
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	(void)other;
    return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << "<" << getTarget() << "> "<< "has been pardoned by Zafod Beeblebrox" << std::endl;
}
