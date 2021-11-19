#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string &message):
	_message(message)
{
}

Form::GradeTooHighException::~GradeTooHighException() _NOEXCEPT
{
}

const char *Form::GradeTooHighException::what() const _NOEXCEPT
{
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string &message):
	_message(message)
{
}

Form::GradeTooLowException::~GradeTooLowException() _NOEXCEPT
{
}

const char *Form::GradeTooLowException::what() const _NOEXCEPT
{
	return _message.c_str();
}

Form::Form():
	_name(""), _target(""), _grade_to_sign(1), _grade_to_execute(1), _is_signed(false)
{
}

Form::Form(std::string const &name, int grade_to_sign, int grade_to_execute, std::string const &target):
	_name(name), _target(target), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _is_signed(false)
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
	{
		throw GradeTooHighException("<constructor> too high");
	}
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
	{
		throw GradeTooHighException("<constructor> too high");
	}
}

Form::~Form()
{
}

Form::Form(Form const &other):
	_name(""), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute())
{
	if (_grade_to_sign < 1 || _grade_to_execute < 1)
	{
		throw GradeTooHighException("<constructor> too high");
	}
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
	{
		throw GradeTooHighException("<constructor> too high");
	}
	*this = other;
}

Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		_is_signed = other.getIsSigned();
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _grade_to_sign)
	{
		throw GradeTooLowException("<beSigned> too low");
	}
	_is_signed = true;
}

std::string const Form::getName() const
{
	return _name;
}

std::string Form::getTarget() const
{
	return _target;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (_is_signed == false)
	{
		std::cout << _name << " is not signed" << std::endl;
		throw "is not signed";
		std::cout << "throw" << std::endl;
	}
	if (executor.getGrade() > _grade_to_execute)
	{
		throw GradeTooLowException("<execute> grade is too low");
	}
	action();
}

std::ostream &operator<<(std::ostream &out, Form &f)
{
	out << "Form name: " << f.getName() 
		<< "\ngrade to sign: " << f.getGradeToSign()
		<< "\ngrade to execute: " << f.getGradeToExecute()
		<< "\nsined: ";
	if (f.getIsSigned()) {
		out << "true";
	} else {
		out << "false";
	}
	return out;
}
