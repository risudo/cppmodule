#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << name << "'s constructor" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << "'s destructor" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
