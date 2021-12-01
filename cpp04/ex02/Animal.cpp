#include "Animal.hpp"
#include <iostream>

Animal::Animal():
	type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
    *this = other;
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
		type = other.getType();
    }
    return *this;
}

std::string	Animal::getType() const
{
	return type;
}
