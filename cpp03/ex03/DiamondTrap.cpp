#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {
    _Name = "";
    FragTrap::setName("_clap_name");
}

DiamondTrap::DiamondTrap(std::string const &name) {
    std::cout << "DiamondTrap " << "constructor called" << std::endl;
    setName(name + "_clap_name");
    _Name = name;
	_Hitpoints = FragTrap::_Hitpoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << "destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) { *this = other; }

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    if (this != &other) {
        _Name = other._Name;
        FragTrap::setName(other.FragTrap::getName());
    }
    return *this;
}

void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

std::string DiamondTrap::getName() const { return _Name; }

void DiamondTrap::WhoAmI(){
    std::cout << "Name:" << _Name << std::endl;
    std::cout << "ClapTrap Name: " << ClapTrap::getName() << std::endl;
}
