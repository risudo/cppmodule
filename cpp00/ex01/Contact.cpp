#include "Contact.hpp"
#include <iomanip>

Contact::Contact():
	index(-1)
{
}

Contact::Contact(std::string *line):
	first_name(line[0]), last_name(line[1]), nickname(line[2]),\
	phone_number(line[3]), darkest_secret(line[4])
{
}

int	Contact::get_index() const
{
	return (index);
}

void	Contact::set_data(std::string *line, int index)
{
	this->index = index;
	this->first_name = line[0];
	this->last_name = line[1];
	this->nickname = line[2];
	this->phone_number = line[3];
	this->darkest_secret = line[4];
}

void	Contact::put_data() const
{
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

void	Contact::put_short_data() const
{
	std::string	short_name[3] = {
		first_name,
		last_name,
		nickname
	};

	for (int i = 0; i < 3; i++)
	{
		if (short_name[i].length() >= 11)
		{
			short_name[i].insert(short_name[i].begin() + 9, '.');
			short_name[i].erase(short_name[i].begin() + 10, short_name[i].end());
		}
	}
	std::cout << "│" << std::setw(10) << index
		<< "|" << std::setw(10) << short_name[0]
		<< "|" << std::setw(10) << short_name[1]
		<< "|" << std::setw(10) << short_name[2]
		<< "│" << std::endl;
}
