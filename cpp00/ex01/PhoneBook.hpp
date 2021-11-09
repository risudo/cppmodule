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
	void	print_space(unsigned long n);
	void	print_bar(unsigned long len);
	void	print_simple_contact();
	void	print_short_format(int idx);
	void	print_all_field(int idx);
	void	ask_index();
	Contact contact[8];
};

#endif
