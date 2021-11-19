#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	Form("ShrubberyCreationForm", signGrade, execGrade, std::string(""))
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form("ShrubberyCreationForm", signGrade, execGrade, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	Form(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::string ofname(getTarget() + "_shrubbery");

	std::ofstream ofs(ofname);
	if (ofs.fail())
	{
		std::cerr << "error" << std::endl;
		return ;
	}
	ofs << "  　 _(⌒⌒⌒)､     \n";
	ofs << " 　(　⌒　⌒　)､   \n";
	ofs << " （ ⌒　 　 ⌒　)､ \n";
	ofs << "( (ヽ|lilli|/)　)\n";
	ofs << "（_ヽ|illii|/_､) \n";
	ofs << "　　 |lilli|     \n";
	ofs << "　　 |illii|     \n";
	ofs << "     /ハハハヽ   \n";
	ofs.close();
}
