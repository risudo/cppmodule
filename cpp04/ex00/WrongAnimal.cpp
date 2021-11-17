#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal():
	type("WrongAnimal")
{
	std::cout << "WrongAniaml constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		type = other.getType();
	}
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}
