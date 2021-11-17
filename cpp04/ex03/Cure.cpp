#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
{
	_type = "cure";
	//std::cout << "Cure constructor" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor" << std::endl;
}

Cure::Cure(Cure const &other):
	AMateria("cure")
{
	*this = other;
}

Cure &Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		_type = "cure";
	}
	return *this;
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
