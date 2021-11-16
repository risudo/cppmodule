#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &other)
{
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		Brain	*p = new Brain();

		*p = *other.brain;
		delete brain;
		brain = p;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}

void	Cat::printBrainPtr() const
{
	std::cout << "brain ptr: " << &brain << std::endl;
}
