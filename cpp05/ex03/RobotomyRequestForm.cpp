#include "RobotomyRequestForm.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm():
	Form("RobotomyRequestForm", signGrade, execGrade, "")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	Form("RobotomyRequestForm", signGrade, execGrade, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	Form("RobotomyRequestForm", signGrade, execGrade, other.getTarget())
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
	}
	return *this;
}

void RobotomyRequestForm::action() const
{
	std::cout << "WHEEEEE" << std::endl;

	std::srand(time(NULL));
	if (rand() % 2) {
		std::cout << "<"<< getTarget() << "> has been robotomized successfully" << std::endl;
	} else {
		std::cout << "Robotization failed" << std::endl;
	}
}
