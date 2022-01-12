#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() {
    _Name = "";
    FragTrap::setName("_clap_name");
}

DiamondTrap::DiamondTrap(std::string const &name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
    setName(name + "_clap_name");
    _Name = name;
    _Hitpoints = FragTrap::defaultHitpoints;
    _EnergyPoints = FragTrap::defaultEnergyPoints;
    _AttackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap "
              << "destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) { *this = other; }

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    if (this != &other) {
        _Name = other._Name;
        FragTrap::setName(other.FragTrap::getName());
        _Hitpoints = other._Hitpoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

std::string DiamondTrap::getName() const { return _Name; }

unsigned int DiamondTrap::getHitpoints() const { return _Hitpoints; }

unsigned int DiamondTrap::getEnergyPoints() const { return _EnergyPoints; }

unsigned int DiamondTrap::getAttackDamage() const { return _AttackDamage; }

void DiamondTrap::WhoAmI() {
    std::cout << "< Name >         : " << _Name << std::endl;
    std::cout << "< ClapTrap Name >: " << ClapTrap::getName() << std::endl;
}
