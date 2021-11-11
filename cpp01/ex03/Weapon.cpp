#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

const std::string &Weapon::getType()
{
	const std::string &ret = this->_type;
	return (ret);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
