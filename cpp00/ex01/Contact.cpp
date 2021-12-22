#include "Contact.hpp"
#include <iomanip>

Contact::Contact():
	index(-1)
{
}

std::string	Contact::get_first_name() const
{
	return (first_name);
}

std::string	Contact::get_last_name() const
{
	return (last_name);
}

std::string	Contact::get_nickname() const
{
	return (nickname);
}

std::string	Contact::get_phone_number() const
{
	return (phone_number);
}

std::string	Contact::get_darkest_secret() const
{
	return (darkest_secret);
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
