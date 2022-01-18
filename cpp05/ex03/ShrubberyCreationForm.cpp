#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", signGrade, execGrade, std::string("")) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : Form("ShrubberyCreationForm", signGrade, execGrade, target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : Form(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &other) {
    (void)other;
    return *this;
}

void ShrubberyCreationForm::action() const {
    std::ofstream ofs(std::string(getTarget() + "_shrubbery"));
    if (ofs.fail()) {
        std::cerr << "error" << std::endl;
        return;
    }
    ofs << "  　 _(⌒⌒⌒)､     \n"
        << " 　(　⌒　⌒　)､   \n"
        << " （ ⌒　 　 ⌒　)､ \n"
        << "( (ヽ|lilli|/)　)\n"
        << "（_ヽ|illii|/_､) \n"
        << "　　 |lilli|     \n"
        << "　　 |illii|     \n"
        << "     /ハハハヽ   \n";
    ofs.close();
}
