#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;

	std::cout << "&str     : " << &str << std::endl;
	std::cout << "str_ptr  : " << str_ptr << std::endl;
	std::cout << "&str_ref : " << &str_ref << std::endl;

	std::cout << "\n*str_ptr : " << *str_ptr << std::endl;
	std::cout << "str_ref : " << str_ref << std::endl;
}

