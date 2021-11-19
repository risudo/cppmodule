#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(std::string const &name, int grade_to_sign, int grade_to_execute, std::string const &target);
	Form(Form const &other);
	virtual ~Form();
	Form &operator=(Form const &other);

	std::string const getName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void action() const = 0;

private:
	class GradeTooHighException : public std::exception
	{
	public:
		~GradeTooHighException() _NOEXCEPT;
		GradeTooHighException(const std::string &message);
		virtual const char *what() const _NOEXCEPT;
	private:
		std::string _message;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		~GradeTooLowException() _NOEXCEPT;
		GradeTooLowException(const std::string &message);
		virtual const char *what() const _NOEXCEPT;
	private:
		std::string _message;
	};

	std::string const _name;
	std::string const _target;
	int const _grade_to_sign;
	int const _grade_to_execute;
	bool _is_signed;
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif
