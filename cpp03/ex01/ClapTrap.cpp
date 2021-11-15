#include "ClapTrap.hpp"
#include "iostream"

ClapTrap::ClapTrap():
	Name(""), Hitpoints(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << Name << " Constructor called" << std::endl;
}

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
	Name = r.Name;
	Hitpoints = r.Hitpoints;
	Energy_points = r.Energy_points;
	Attack_damage = r.Attack_damage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << Name << " attacks " << target
		<< ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amount)
{
	std::cout << Name << " takes ";

	if (Hitpoints < amount)
	{
		std::cout << Hitpoints << " damage!" << std::endl;
		Hitpoints = 0;
	} else {
		std::cout << amount << " damage!" << std::endl;
		Hitpoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << Name << " is repaired " << amount << " points"<< std::endl;
	Hitpoints += amount;
}