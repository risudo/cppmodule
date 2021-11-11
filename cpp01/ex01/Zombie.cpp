#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie():
	_name("")
{
	std::cout << "constructor" << std::endl;
}

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << name << " constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " destructor called" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}
