#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
public:
	Contact();
	Contact(std::string *line);
	void	set_data(std::string *line, int index);
	int		get_index() const;
	void	put_data() const;
	void	put_short_data() const;

private:
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

void print_contact(const Contact *contact);

#endif
