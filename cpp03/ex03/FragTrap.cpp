#include "FragTrap.hpp"

#include <iostream>

const unsigned int FragTrap::defaultHitpoints = 100;
const unsigned int FragTrap::defaultEnergyPoints = 100;
const unsigned int FragTrap::defaultAttackDamage = 30;

FragTrap::FragTrap() {
    std::cout << "FlagTrap default constructor called" << std::endl;
    setName("");
    _Hitpoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
}

FragTrap::FragTrap(std::string const &name) {
    std::cout << "FlagTrap "
              << "constructor called" << std::endl;
    setName(name);
    _Hitpoints = 100;
    _EnergyPoints = 100;
    _AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &other) { *this = other; }

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    if (this != &other) {
        setName(other.getName());
        _Hitpoints = other._Hitpoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

void FragTrap::attack(std::string const &target) {
    std::cout << "FlagTrap " << getName() << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!"
              << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "positive high five request" << std::endl;
}
