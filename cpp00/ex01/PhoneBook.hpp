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
	void	print_contacts_list();
	void	print_short_format(int idx);
	void	ask_index();
	void	print_all_field(int idx);
	void	put_space(unsigned long n);
	void	put_bar(unsigned long len);
	Contact contact[8];
};

#endif
