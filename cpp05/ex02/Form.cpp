#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::out_of_range(msg) {}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::out_of_range(msg) {}

Form::IsNotSigned::IsNotSigned()
    : std::runtime_error("The form is not signed") {}

Form::Form()
    : _name(""),
      _target(""),
      _grade_to_sign(1),
      _grade_to_execute(1),
      _is_signed(false) {}

Form::Form(std::string const &name, int grade_to_sign, int grade_to_execute,
           std::string const &target)
    : _name(name),
      _target(target),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute),
      _is_signed(false) {
    if (_grade_to_sign < maxGrade || _grade_to_execute < maxGrade) {
        throw GradeTooHighException("<constructor> Grade too high");
    }
    if (_grade_to_sign > minGrade || _grade_to_execute > minGrade) {
        throw GradeTooLowException("<constructor> Grade too low");
    }
}

Form::~Form() {}

Form::Form(Form const &other)
    : _name(other.getName()),
      _grade_to_sign(other.getGradeToSign()),
      _grade_to_execute(other.getGradeToExecute()) {
    if (_grade_to_sign < maxGrade || _grade_to_execute < maxGrade) {
        throw GradeTooHighException("<constructor> Grade too high");
    }
    if (_grade_to_sign > minGrade || _grade_to_execute > minGrade) {
        throw GradeTooLowException("<constructor> Grade too low");
    }
    *this = other;
}

Form &Form::operator=(Form const &other) {
    if (this != &other) {
        _is_signed = other.getIsSigned();
    }
    return *this;
}

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _grade_to_sign) {
        throw GradeTooLowException("Grade is too low");
    }
    _is_signed = true;
}

std::string const Form::getName() const { return _name; }

std::string Form::getTarget() const { return _target; }

bool Form::getIsSigned() const { return _is_signed; }

int Form::getGradeToSign() const { return _grade_to_sign; }

int Form::getGradeToExecute() const { return _grade_to_execute; }

void Form::execute(Bureaucrat const &executor) const {
    if (_is_signed == false) {
        throw IsNotSigned();
    }
    if (executor.getGrade() > _grade_to_execute) {
        throw GradeTooLowException("<execute> grade is too low");
    }
    action();
}

std::ostream &operator<<(std::ostream &out, Form &f) {
    out << "<Form name: " << f.getName() << ">"
        << "\n            target: " << f.getTarget()
        << "\n     grade to sign: " << f.getGradeToSign()
        << "\n  grade to execute: " << f.getGradeToExecute()
        << "\n             sined: ";
    if (f.getIsSigned()) {
        out << "true";
    } else {
        out << "false";
    }
    return out;
}
