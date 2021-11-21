#include <iostream>
#include <sstream>
#include <string>
#include <cfloat>

enum e_type
{
	CANNOT_CONVERT,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

void put_char(char const &c, bool const &impossible)
{
	std::cout << "char: ";
	if (impossible) {
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(c)) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'"<< static_cast<char>(c) << "'" << std::endl;
	}
}

void put_int(int const &i, bool const &impossible)
{
	if (impossible) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << i << std::endl;
	}
}

void put_float(float const &f, bool const &impossible)
{
	if (impossible)
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (f - static_cast<int>(f) == static_cast<float>(0)) {
		std::cout << "float: " << f << ".0f" << std::endl;
	} else {
		std::cout << "float: " << f << "f" << std::endl;
	}
}

void put_double(double const &d)
{
	if (d - static_cast<int>(d) == static_cast<double>(0)) {
		std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
	} else {
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
}

void print_char_type(char const c, bool const impossible)
{
	put_char(c, impossible);
	put_int(static_cast<int>(c), impossible);
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void print_int_type(int const i, bool const impossible)
{
	if (i > static_cast<int>(CHAR_MAX) || i < static_cast<int>(CHAR_MIN)) {
		put_char(static_cast<char>(i), true);
	} else {
		put_char(static_cast<char>(i), impossible);
	}
	put_int(i, impossible);
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void print_float_type(float const f, bool const impossible)
{
	if (f > static_cast<float>(CHAR_MAX) || f < static_cast<float>(CHAR_MIN)) {
		put_char(static_cast<char>(f), true);
	} else {
		put_char(static_cast<char>(f), impossible);
	}

	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN)) {
		put_int(static_cast<int>(f), true);
	} else {
		put_int(static_cast<int>(f), impossible);
	}
	put_float(f, false);
	put_double(static_cast<double>(f));
}

void print_double_type(double const d, bool const impossible, std::string const &str)
{
	if (d > static_cast<double>(CHAR_MAX) || d < static_cast<double>(CHAR_MIN)) {
		put_char(static_cast<char>(d), true);
	} else {
		put_char(static_cast<char>(d), impossible);
	}

	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN)) {
		put_int(static_cast<int>(d), true);
	} else {
		put_int(static_cast<int>(d), impossible);
	}

	if (str == "+inf" || str == "-inf") {
		put_float(static_cast<float>(d), false);
	} else if (d > static_cast<double>(FLT_MAX) || d < static_cast<double>(FLT_MIN)) {
		put_float(static_cast<float>(d), true);
	} else {
		put_float(static_cast<float>(d), false);
	}
	put_double(d);
}

void print_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
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
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		return CHAR;
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
	return INT;
}

void convert(std::string str)
{
	bool impossible = false;
	int type = getType(str, impossible);

	if (type == CANNOT_CONVERT)
	{
		print_impossible();
		return ;
	}
	if (type == CHAR)
	{
		try {
			char c = str[0];
			print_char_type(c, impossible);
		} catch (std::exception &e) {
			print_impossible();
		}
	}
	if (type == INT)
	{
		try {
			int i = std::stoi(str);
			print_int_type(i, impossible);
		} catch (std::exception &e) {
			print_impossible();
		}
	}
	if (type == FLOAT)
	{
		try {
			float f = std::stof(str);
			print_float_type(f, impossible);
		} catch (std::exception &e) {
			print_impossible();
		}
	}
	if (type == DOUBLE)
	{
		try {
			double d = std::stod(str);
			print_double_type(d, impossible, str);
		} catch (std::exception &e) {
			print_impossible();
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
