#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() {
    _Name = "NONAME";
    _Hitpoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
    std::cout << "Flag Trap " << _Name << "constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) {
    _Name = name;
    _Hitpoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
    std::cout << "Flag Trap " << _Name << "constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) { *this = other; }

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _Name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    if (this != &other) {
        _Name = other._Name;
        _Hitpoints = other._Hitpoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

void FragTrap::attack(std::string const &target) {
    std::cout << "FlagTrap " << _Name << " attacks " << target << ", causing "
              << _AttackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " request positive high five" << std::endl;
}
