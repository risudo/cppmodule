#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	run();

private:
	void	add_contact(int idx);
	void	print_short_contact();
	void	print_short_format(int idx);
	void	print_all_contact(int idx);
	void	ask_index();
	Contact contact[8];
};

#endif
