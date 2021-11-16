#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
    *this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
    if (this != &other)
    {
    }
    return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "meow" << std::endl;
}
