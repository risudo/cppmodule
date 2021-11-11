#include "Karen.hpp"
#include <iostream>

enum	e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NOTHNIG
};

int	get_level(std::string level)
{
	std::string level_list[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == level_list[i])
		{
			return (i);
		}
	}
	return (NOTHNIG);
}

int main(int argc, char **argv)
{
	Karen karen;

	if (argc != 2)
	{
		std::cout << "invalid argument" << std::endl;
		return (1);
	}
	std::string arg(argv[1]);
	
	if (arg.length() == 0)
		return (0);

	switch (get_level(argv[1]))
	{
		case DEBUG:
			std::cout << "[ DEBUG ]\n";
			karen.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]\n";
			karen.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]\n";
			karen.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]\n";
			karen.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
