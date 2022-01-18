#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
    RobotomyRequestForm(std::string const &target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &other);

    static const int signGrade = 72;
    static const int execGrade = 45;

private:
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    RobotomyRequestForm();
    void action() const;
};

#endif
