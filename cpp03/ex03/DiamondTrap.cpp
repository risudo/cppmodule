#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    _Name = "";
    FragTrap::setName("_clap_name");
}

DiamondTrap::DiamondTrap(std::string const &name) {
    _Name = name;
    setName(name + "_clap_name");
	_Hitpoints = FragTrap::_Hitpoints;
	_EnergyPoints = ScavTrap::_EnergyPoints;
	_AttackDamage = FragTrap::_AttackDamage;
}

DiamondTrap::~DiamondTrap() {}

DiamondTrap::DiamondTrap(DiamondTrap const &other) { *this = other; }

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    if (this != &other) {
        _Name = other._Name;
        FragTrap::setName(other.FragTrap::getName());
    }
    return *this;
}
