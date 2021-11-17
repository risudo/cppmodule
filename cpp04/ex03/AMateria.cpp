#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
{
	//std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(std::string const &type):
	_type(type)
{
	//std::cout << "AMateria constructor" << std::endl;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
    *this = other;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	if (this != &other)
	{
		_type = other.getType();
	}
	return *this;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	if (_type == "ice") {
		std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
	} else if (_type == "cure") {
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	} else {
		std::cout << "" << std::endl;
	}
}
