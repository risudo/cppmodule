#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &other)
{
	brain = new Brain();
	*this = other;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		*brain = *(other.brain);
		type = other.type;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "bowwow" << std::endl;
}
