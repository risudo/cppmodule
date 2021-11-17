#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &other)
{
	*this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "bowwow" << std::endl;
}
