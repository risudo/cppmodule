#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void run();

private:
    void add_contact(int idx);
    void print_contacts_list();
    void print_short_format(int idx);
    void ask_index();
    void print_all_field(int idx);
    Contact contact[8];
};

#endif
