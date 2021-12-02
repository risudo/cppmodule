#include "ClapTrap.hpp"
#include "iostream"

ClapTrap::ClapTrap():
	_Name(""), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap" << _Name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _Name):
	_Name(_Name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << _Name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _Name << " Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &r)
{
	this->_Name = r._Name;
	this->_Hitpoints = r._Hitpoints;
	this->_EnergyPoints = r._EnergyPoints;
	this->_AttackDamage = r._AttackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _Name << " attacks " << target
		<< ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amount)
{
	std::cout << "ClapTrap " << _Name << " takes ";

	if (_Hitpoints < amount) {
		std::cout << _Hitpoints << " damage!" << std::endl;
		_Hitpoints = 0;
	} else {
		std::cout << amount << " damage!" << std::endl;
		_Hitpoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _Name << " is repaired " << amount << " points"<< std::endl;
	_Hitpoints += amount;
}
