#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
    ShrubberyCreationForm(std::string const &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &other);

    static const int signGrade = 145;
    static const int execGrade = 137;

private:
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    ShrubberyCreationForm();
    void action() const;
};

#endif
