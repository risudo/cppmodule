#include "Contact.hpp"
#include <iomanip>

void	put_short_field()
{
	std::cout << "│" << std::setw(10) << "index   "
	<< "|" << std::setw(10) << "first name"
	<< "|" << std::setw(10) << "last name"
	<< "|" << std::setw(10) << "nickname "
	<< "│" << std::endl;
}

static void	put_separater()
{
	std::cout << " ";
	for (int i = 0; i < 10 * 4 + 3; i++)
	{
		std::cout << "-";
	}
	std::cout << " ";
	std::cout << std::endl;
}

void	print_contact(const Contact *contact)
{
	put_separater();
	put_short_field();
	put_separater();
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].get_index() != -1)
		{
			contact[i].put_short_data();
			put_separater();
		}
	}
}
