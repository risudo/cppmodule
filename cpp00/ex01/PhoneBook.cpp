#include "PhoneBook.hpp"

#include <iomanip>

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void put_nchar(unsigned long n, std::string c) {
    for (unsigned long i = 0; i < n; i++) {
        std::cout << c;
    }
}

unsigned long ft_max(unsigned long *l, int num) {
    if (l == NULL) return 0;
    unsigned long max = l[0];

    for (int i = 1; i < num; i++) {
        if (l[i] > max) max = l[i];
    }
    return max;
}

void PhoneBook::print_all_field(int idx) {
    std::string first_name = contact[idx].get_first_name();
    std::string last_name = contact[idx].get_last_name();
    std::string nickname = contact[idx].get_nickname();
    std::string phone_number = contact[idx].get_phone_number();
    std::string darkest_secret = contact[idx].get_darkest_secret();

    unsigned long len[] = {
        first_name.length(),
        nickname.length(),
        phone_number.length(),
        darkest_secret.length(),
    };
    unsigned long max_len = ft_max(len, 4);
    std::cout << "╭";
    put_nchar(max_len + 18, "─");
    std::cout << "╮\n"
              << "│ first name     : " << first_name;
    put_nchar(max_len - first_name.length(), " ");
    std::cout << "│\n"
              << "│ last name      : " << last_name;
    put_nchar(max_len - last_name.length(), " ");
    std::cout << "│\n"
              << "│ nick name      : " << nickname;
    put_nchar(max_len - nickname.length(), " ");
    std::cout << "│\n"
              << "│ phone number   : " << phone_number;
    put_nchar(max_len - phone_number.length(), " ");
    std::cout << "│\n"
              << "│ darkest secret : " << darkest_secret;
    put_nchar(max_len - darkest_secret.length(), " ");
    std::cout << "│\n"
              << "╰";
    put_nchar(max_len + 18, "─");
    std::cout << "╯" << std::endl;
}

void PhoneBook::ask_index() {
    if (contact[0].get_index() == -1) {
        return;
    }

    std::cout << "Please select index.\n> " << std::flush;
    std::string index;
    getline(std::cin, index);
    if (!std::cin) {
        std::exit(0);
    }

    if (index.length() == 1 && std::isdigit(index[0])) {
        int idx = static_cast<int>(index[0] - '0');
        if (idx > 0 && idx < 9 && contact[idx - 1].get_index() != -1) {
            print_all_field(idx - 1);
            return;
        }
    }
    ask_index();
}

void PhoneBook::print_short_format(int idx) {
    std::string short_name[3] = {contact[idx].get_first_name(),
                                 contact[idx].get_last_name(),
                                 contact[idx].get_nickname()};

    for (int i = 0; i < 3; i++) {
        if (short_name[i].length() >= 11) {
            short_name[i].insert(short_name[i].begin() + 9, '.');
            short_name[i].erase(short_name[i].begin() + 10,
                                short_name[i].end());
        }
    }
    std::cout << "│" << std::setw(10) << contact[idx].get_index();
    std::cout << "|" << std::setw(10) << short_name[0];
    std::cout << "|" << std::setw(10) << short_name[1];
    std::cout << "|" << std::setw(10) << short_name[2];
    std::cout << "│" << std::endl;
}

void PhoneBook::print_contacts_list() {
    std::cout << " ";
    put_nchar(10 * 4 + 3, "─");
    std::cout << std::endl;
    std::cout << "│" << std::setw(10) << "index   ";
    std::cout << "|" << std::setw(10) << "first name";
    std::cout << "|" << std::setw(10) << "last name";
    std::cout << "|" << std::setw(10) << "nickname ";
    std::cout << "│\n ";
    put_nchar(10 * 4 + 3, "─");
    std::cout << std::endl;

    for (int i = 0; i < 8; i++) {
        if (contact[i].get_index() != -1) {
            print_short_format(contact[i].get_index() - 1);
            std::cout << " ";
            put_nchar(10 * 4 + 3, "─");
            std::cout << std::endl;
        }
    }
}

void PhoneBook::add_contact(int idx) {
    const std::string fields[5] = {"first name", "last name", "nickname",
                                   "phone number", "darkest secret"};
    std::string line[5];

    std::cout << "Type new contact's infomation." << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << fields[i] << " : " << std::flush;
        getline(std::cin, line[i]);
        if (!std::cin) std::exit(0);
    }
    contact[idx - 1].set_data(line, idx);
}

void PhoneBook::run() {
    int idx = 1;
    std::string cmd;

    while (1) {
        std::cout << "Please type command (ADD, SEARCH or EXIT)\n> "
                  << std::flush;
        getline(std::cin, cmd);

        if (!std::cin || cmd == "EXIT") {
            std::exit(0);
        } else if (cmd == "ADD") {
            add_contact(idx);
            idx++;
        } else if (cmd == "SEARCH") {
            print_contacts_list();
            ask_index();
        } else if (cmd != "") {
            std::cout << "command not found" << std::endl;
        }
        if (idx == 9) idx = 1;
    }
}
