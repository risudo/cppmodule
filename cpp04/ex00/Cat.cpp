#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
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
		type = other.type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
