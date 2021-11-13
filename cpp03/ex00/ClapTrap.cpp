#include "ClapTrap.hpp"
#include "iostream"

ClapTrap::ClapTrap(std::string name):
	Name(name), Hitpoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << Name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &r)
{
	this->Name = r.Name;
	this->Hitpoints = r.Hitpoints;
	this->Energy_points = r.Energy_points;
	this->Attack_damage = r.Attack_damage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << Name << " attacks " << target
		<< ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amount)
{
	std::cout << "ClapTrap " << Name << " takes " << amount << " damage!" << std::endl;
	Hitpoints -= amount;
}

void	beRepaired(unsigned int amount)
{
	std::cout << "" << std::endl;
}
