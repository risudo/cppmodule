#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

class Form {
public:
    Form();
    Form(std::string const &name, int grade_to_sign, int grade_to_execute,
         std::string const &target);
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

    static const int maxGrade = 1;
    static const int minGrade = 150;

private:
    class GradeTooHighException : public std::out_of_range {
    public:
        GradeTooHighException(const std::string &msg);
    };

    class GradeTooLowException : public std::out_of_range {
    public:
        GradeTooLowException(const std::string &msg);
    };
	
	class IsNotSigned : public std::runtime_error {
		public: IsNotSigned();
	};

    std::string const _name;
    std::string const _target;
    int const _grade_to_sign;
    int const _grade_to_execute;
    bool _is_signed;
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif
