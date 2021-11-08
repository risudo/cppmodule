#include <iostream>
#include <string>
#include "Contact.hpp"

void	add_contact(Contact *contact, int idx)
{
	const std::string fields[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
	};
	std::string line[5];

	std::cout << "Type new contact's infomation." << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i] << " : " << std::flush;
		getline(std::cin, line[i]);
		if (!std::cin)
			return ;
	}
	contact[idx - 1].set_data(line, idx);
}

void	ask_index(const Contact *contact)
{
	std::cout << "Please select index." << std::endl
	<< "> " << std::flush;

	std::string index;
	getline(std::cin, index);
	if (!std::cin)
		return ;

	if (index.length() == 1 && std::isdigit(index[0]))
	{
		int	idx = std::stoi(index);
		if (idx != 0 && contact[idx - 1].get_index() != -1)
		{
			contact[idx - 1].put_data();
			return ;
		}
	}
	ask_index(contact);
}

int	main(void)
{
	Contact		contact[8];
	int			idx;
	std::string	cmd;

	idx = 1;
	while (1)
	{
		std::cout << "Please type command (ADD, SEARCH or EXIT)" << std::endl
		<< "> " << std::flush;

		getline(std::cin, cmd);

		if (!std::cin || cmd == "EXIT") {
			exit(0);
		} else if (cmd == "ADD") {
			add_contact(contact, idx);
			idx++;
		} else if (cmd == "SEARCH") {
			print_contact(contact);
			ask_index(contact);
		} else if (cmd != "") {
			std::cout << "command not found" << std::endl;
		}
		if (idx == 9)
			idx = 1;
	}
	return (0);
}
