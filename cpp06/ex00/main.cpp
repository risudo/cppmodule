#include <iostream>
#include <sstream>
#include <string>

enum e_type
{
	CANNOT_CONVERT,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

void print_char(char const &c, bool const &impossible)
{
	std::cout << "char: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
	} else if (!(c >= ' ' && c <= '~')) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'"<< static_cast<char>(c) << "'" << std::endl;
	}
}

int getType(std::string const &str, bool &impossible)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		impossible = true;
		return FLOAT;
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		impossible = true;
		return DOUBLE;
	}

	bool dot = false;

	for (std::size_t i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == '.' && dot == false)
		{
			dot = true;
			continue ;
		}
		if (!(std::isdigit(str[i]) || str[i] == 'e' || str[i] == '+' || str[i] == '-'))
		{
			return CANNOT_CONVERT;
		}
	}
	if (str[str.length() - 1] == 'f') {
		return FLOAT;
	} else if (!std::isdigit(str[str.length() - 1])) {
		return CANNOT_CONVERT;
	} else if (dot == true) {
		return DOUBLE;
	}
	try {
		int i = std::stoi(str);
		if (i >= -127 && i < 128)
		{
			return CHAR;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return CANNOT_CONVERT;
	}
	return INT;
}

void print_int(int const &i, bool const &impossible)
{
	if (impossible) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << i << std::endl;
	}
}

void convert(std::string str)
{
	bool impossible = false;
	int type = getType(str, impossible);

	if (type == CANNOT_CONVERT)
	{
		std::cout << "cannot convert" << std::endl;
		return ;
	}
	if (type == CHAR)
	{
		try {
			char c = static_cast<char>(std::stoi(str));

			print_char(c, impossible);
			print_int(static_cast<int>(c), impossible);
			std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (type == INT)
	{
		try {
			int i = std::stoi(str);

			print_char(static_cast<char>(i), impossible);
			print_int(static_cast<int>(i), impossible);
			std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (type == FLOAT)
	{
		try {
			float f = std::stof(str);

			print_char(static_cast<int>(f), impossible);
			print_int(static_cast<int>(f), impossible);
			if (f - static_cast<int>(f) == static_cast<float>(0)) {
				std::cout << "float: " << f << ".0f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
			} else {
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (type == DOUBLE)
	{
		try {
			double d = std::stod(str);

			print_char(static_cast<int>(d), impossible); //
			print_int(static_cast<int>(d), impossible);
			if (d - static_cast<int>(d) == static_cast<float>(0)) {
				std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
			} else {
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			}
			std::cout << "double: " << d << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "bad argument" << std::endl;
		return (0);
	} else {
		convert(argv[1]);
	}
}
