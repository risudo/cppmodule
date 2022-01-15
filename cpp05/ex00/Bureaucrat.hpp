#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <string>

class Bureaucrat {
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

    static const int maxGrade;
    static const int minGrade;

private:
    class GradeTooHighException : public std::out_of_range {
    public:
        GradeTooHighException(const std::string &msg);
    };

    class GradeTooLowException : public std::out_of_range {
    public:
        GradeTooLowException(const std::string &msg);
    };

    const std::string _name;  // const?
    int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
