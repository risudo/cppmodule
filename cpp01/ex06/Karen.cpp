#include "Karen.hpp"
#include <iostream>

Karen::Karen()
{
	f[0] = &Karen::do_nothing;
	f[1] = &Karen::debug;
	f[2] = &Karen::info;
	f[3] = &Karen::warning;
	f[4] = &Karen::error;
}

void Karen::debug(void)
{
	std::cout << \
	"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. \
I just love it!" \
	<< std::endl;
}

void Karen::info(void)
{
	std::cout << \
	"I cannot believe adding extra bacon cost more money. You don’t put enough! \
If you did I would not have to ask for it!" \
	<< std::endl;
}

void Karen::warning(void)
{
	std::cout << \
	"I think I deserve to have some extra bacon for free. \
I’ve been coming here for years and you just started working here last month." \
	<< std::endl;
}

void Karen::error(void)
{
	std::cout << \
"This is unacceptable, I want to speak to the manager now." \
	<< std::endl;
}

void	Karen::do_nothing(void)
{
	;
}

void Karen::complain(std::string level)
{
	int idx = 0;

	idx += (level == "DEBUG") * 1;
	idx += (level == "INFO") * 2;
	idx += (level == "WARNING") * 3;
	idx += (level == "ERROR") * 4;
	(this->*f[idx])();
}
