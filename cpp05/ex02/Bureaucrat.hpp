#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);

	const std::string &getName() const;
	int getGrade() const;
	void upGrade();
	void downGrade();
	void signForm(Form &f);//

private:
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(const std::string &message);
		~GradeTooHighException() throw();
		virtual const char *what() const _NOEXCEPT;
	private:
		std::string _message;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		~GradeTooLowException() throw();
		GradeTooLowException(const std::string &message);
		virtual const char *what() const _NOEXCEPT;
	private:
		std::string _message;
	};

	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
