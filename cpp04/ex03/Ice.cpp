#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
{
	_type = "ice";
	//std::cout << "Ice constructor" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor" << std::endl;
}

Ice::Ice(Ice const &other)
{
    *this = other;
}

Ice &Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		_type = "ice";
	}
	return *this;
}

AMateria	*Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}
