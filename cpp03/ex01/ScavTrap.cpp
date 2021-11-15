#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	Name = "";
	Hitpoints = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap " << Name << " constructor called" << std::endl;
	Name = name;
	Hitpoints = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name <<  " destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
    *this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    if (this != &other)
    {
		Name = other.Name;
		Hitpoints = other.Hitpoints;
		Energy_points = other.Energy_points;
		Attack_damage = other.Attack_damage;
    }
    return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << "has enterred in Gate Keeper mode" << std::endl;
}