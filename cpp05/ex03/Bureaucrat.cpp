#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message):
	_message(message)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{
}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message):
	_message(message)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
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

void Bureaucrat::signForm(Form &f)
{
	if (f.getIsSigned())
	{
		std::cout << "already signed" << std::endl;
		return ;
	}
	if (_grade > f.getGradeToSign())
	{
		std::cout <<"<"<< _name << "> cannot sign " << f.getName() << " because of low grade" << std::endl;
		return ;
	}
	f.beSigned(*this);
	std::cout << "<"<< _name << "> signs " << f.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const &form)
{
	try {
		form.execute(*this);
		std::cout << "aciton was successful" << std::endl;
	} catch (const char *msg) {
		std::cout << msg << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << "<" << b.getName() << ">";
	out << " grade: " << b.getGrade();
	return out;
}

