#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm : public Form {
public:
    PresidentialPardonForm(std::string const &target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &other);

    static const int signGrade = 25;
    static const int execGrade = 5;

private:
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    PresidentialPardonForm();
    void action() const;
};

#endif
