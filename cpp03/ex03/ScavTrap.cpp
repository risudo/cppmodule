#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap default constructor called" << std::endl;
    setName("");
    _Hitpoints = defaultHitpoints;
    _EnergyPoints = defaultEnergyPoints;
    _AttackDamage = defaultAttackDamage;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
    setName(name);
    _Hitpoints = defaultHitpoints;
    _EnergyPoints = defaultEnergyPoints;
    _AttackDamage = defaultAttackDamage;
}

ScavTrap::ScavTrap(ScavTrap const &other) { *this = other; }

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << getName() << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    if (this != &other) {
        setName(other.getName());
        _Hitpoints = other._Hitpoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

void ScavTrap::attack(std::string const &target) {
    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << _AttackDamage << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " has enterred in Gate Keeper mode"
              << std::endl;
}
