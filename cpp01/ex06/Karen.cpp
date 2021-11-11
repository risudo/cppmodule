#include "Karen.hpp"
#include <iostream>

Karen::Karen()
{
	f[0] = &Karen::debug;
	f[1] = &Karen::info;
	f[2] = &Karen::warning;
	f[3] = &Karen::error;
}

void Karen::debug(void)
{
	std::cout << \
	"[ DEBUG ]\n\
I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I just love it!" \
	<< std::endl;
}

void Karen::info(void)
{
	std::cout << \
	"[ INFO ] \n\
I cannot believe adding extra bacon cost more money. You don’t put enough! \
If you did I would not have to ask for it!" \
	<< std::endl;
}

void Karen::warning(void)
{
	std::cout << \
	"[ WARNING ] \n\
I think I deserve to have some extra bacon for free. \
I’ve been coming here for years and you just started working here last month." \
	<< std::endl;
}

void Karen::error(void)
{
	std::cout << \
	"[ ERROR ]\n\
This is unacceptable, I want to speak to the manager now." \
	<< std::endl;
}

void Karen::complain(std::string level)
{
	int idx = 0;

	idx += (level == "DEBUG") * 1;
	idx += (level == "INFO") * 2;
	idx += (level == "WARNING") * 3;
	idx += (level == "ERROR") * 4;
	if (idx >= 1)
	{
		(this->*f[idx - 1])();
	}
	else if (level.length() > 0)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
