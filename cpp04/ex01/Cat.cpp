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
	brain = new Brain();
	*this = other;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		*brain = *(other.brain);
		type = other.type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
