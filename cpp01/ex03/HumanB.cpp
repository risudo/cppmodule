#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name):
	_weapon(NULL), _name(name)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " does not have weapon" << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	}
}
