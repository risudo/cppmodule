#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::print_all_contact(int idx)
{
	std::cout << "print_all_contact" << std::endl;
	std::string first_name = contact[idx].get_first_name();
	std::string last_name = contact[idx].get_last_name();
	std::string nickname = contact[idx].get_nickname();
	std::string phone_number = contact[idx].get_phone_number();
	std::string darkest_secret = contact[idx].get_darkest_secret();
	
	
	unsigned long	len;
	len = first_name.length();
	if (len < last_name.length())
		len = last_name.length();
	if (len < nickname.length())
		len = nickname.length();
	if (len < phone_number.length())
		len = phone_number.length();
	if (len < darkest_secret.length())
		len = darkest_secret.length();
	
	std::cout << "╭";
	for (unsigned long i = 0; i < len + 18; i++)
	{
		std::cout << "─";
	}
	std::cout << "╮\n" << "│ first name     : " << first_name;
	for (unsigned long i = 0; i < len - first_name.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << "│\n" << "│ last name      : " << last_name;
	for (unsigned long i = 0; i < len - last_name.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << "│\n" <<  "│ nick name      : " << nickname;
	for (unsigned long i = 0; i < len - nickname.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << "│\n" << "│ phone number   : " << phone_number;
	for (unsigned long i = 0; i < len - phone_number.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << "│\n" << "│ darkest secret : " << darkest_secret;
	for (unsigned long i = 0; i < len - darkest_secret.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << "│\n" << "╰";
	for (unsigned long i = 0; i < len + 18; i++)
	{
		std::cout << "─";
	}
	std::cout << "╯" << std::endl;
}

void	PhoneBook::ask_index()
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
			print_all_contact(idx - 1);
			return ;
		}
	}
	ask_index();
}

void	PhoneBook::print_short_format(int idx)
{
	std::string	short_name[3] = {
		contact[idx].get_first_name(),
		contact[idx].get_last_name(),
		contact[idx].get_nickname()
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (short_name[i].length() >= 11)
		{
			short_name[i].insert(short_name[i].begin() + 9, '.');
			short_name[i].erase(short_name[i].begin() + 10, short_name[i].end());
		}
	}
	std::cout << "│" << std::setw(10) << contact[idx].get_index()
		<< "|" << std::setw(10) << short_name[0]
		<< "|" << std::setw(10) << short_name[1]
		<< "|" << std::setw(10) << short_name[2]
		<< "│" << std::endl;
}

void	PhoneBook::print_short_contact()
{
	std::cout << " ";
	for (int i = 0; i < 10 * 4 + 3; i++)
	{
		std::cout << "-";
	}
	std::cout << "\n│" << std::setw(10) << "index   "
	<< "|" << std::setw(10) << "first name"
	<< "|" << std::setw(10) << "last name"
	<< "|" << std::setw(10) << "nickname "
	<< "│" << std::endl;
	std::cout << " ";

	for (int i = 0; i < 10 * 4 + 3; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].get_index() != -1)
		{
			print_short_format(contact[i].get_index() - 1);
			std::cout << " ";
			for (int i = 0; i < 10 * 4 + 3; i++)
			{
				std::cout << "-";
			}
			std::cout << std::endl;
		}
	}
}

void	PhoneBook::add_contact(int idx)
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

void	PhoneBook::run()
{
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
			add_contact(idx);
			idx++;
		} else if (cmd == "SEARCH") {
			print_short_contact();
			ask_index();
		} else if (cmd != "") {
			std::cout << "command not found" << std::endl;
		}
		if (idx == 9)
			idx = 1;
	}
}
