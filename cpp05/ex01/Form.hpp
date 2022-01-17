#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
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

    std::string const _name;
    int const _grade_to_sign;
    int const _grade_to_execute;
    bool _is_signed;
};

std::ostream &operator<<(std::ostream &out, Form &f);

#endif
