#include "Bureaucrat.hpp"

#include <iostream>

#include "Form.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::out_of_range(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::out_of_range(msg) {}

Bureaucrat::Bureaucrat() : _name("NONAME"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade > minGrade) {
        throw GradeTooLowException("<constructor> Grade too low");
    }
    if (grade < maxGrade) {
        throw GradeTooHighException("<constructor> Grade too high");
    }
    _grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) { *this = other; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other) {
        _grade = other.getGrade();
    }
    return *this;
}

const std::string &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::upGrade() {
    if (_grade == maxGrade) {
        throw GradeTooHighException("<upGrade> too high");
    }
    _grade--;
}

void Bureaucrat::downGrade() {
    if (_grade == minGrade) {
        throw GradeTooLowException("<downGrade> too low");
    }
    _grade++;
}

void Bureaucrat::signForm(Form &f) {
    if (f.getIsSigned()) {
        std::cout << "already signed" << std::endl;
        return;
    }
    try {
        f.beSigned(*this);
        std::cout << "<" << _name << "> signs " << f.getName() << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "<" << _name << ">"
                  << " cannot sign " << f.getName() << " because " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::executeForm(Form const &form) {
    try {
        form.execute(*this);
        std::cout << "<" << _name << ">"
                  << " executes "
                  << "<" << form.getName() << ">" << std::endl;
    } catch (const char *msg) {
        std::cout << msg << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << "<" << b.getName() << ">"
        << " grade: " << b.getGrade();
    return out;
}
