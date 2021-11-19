#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(std::string const &name, int grade_to_sign, int grade_to_execute);
	Form(Form const &other);
	~Form();
	Form &operator=(Form const &other);

	std::string const getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);

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
	int const _grade_to_sign;
	int const _grade_to_execute;
	bool _is_signed;
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif
