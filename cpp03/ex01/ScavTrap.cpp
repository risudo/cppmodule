#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
    _Name = "NONAME";
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap " << _Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    _Name = name;
    _Hitpoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
    std::cout << "ScavTrap " << _Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) { *this = other; }

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _Name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    if (this != &other) {
        _Name = other._Name;
        _Hitpoints = other._Hitpoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing "
              << _AttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _Name << " has enterred in Gate Keeper mode"
              << std::endl;
}
