#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message):
	_message(message)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message):
	_message(message)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return _message.c_str();
}

Bureaucrat::Bureaucrat():
	_grade(1)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name)
{
	if (grade > 150)
	{
		throw GradeTooLowException("<constructor> too low");
	}
	if (grade < 1)
	{
		throw GradeTooHighException("<constructor> too high");
	}
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		_grade = other.getGrade();
	}
	return *this;
}

const std::string	&Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::upGrade()
{
	if (_grade == 1)
	{
		throw GradeTooHighException("<upGrade> too high");
	}
	_grade++;
}

void Bureaucrat::downGrade()
{
	if (_grade == 150)
	{
		throw GradeTooLowException("<downGrade> too low");
	}
	_grade--;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << "<" << b.getName() << ">";
	out << " grade: " << b.getGrade();
	return out;
}
