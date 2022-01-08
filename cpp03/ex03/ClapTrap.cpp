#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap()
    : _Name(""), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0) {
    std::cout << "ClapTrap "
              << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _Name(name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0) {
    std::cout << "ClapTrap " << _Name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) { *this = other; }

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _Name << " Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &r) {
    _Name = r._Name;
    _Hitpoints = r._Hitpoints;
    _EnergyPoints = r._EnergyPoints;
    _AttackDamage = r._AttackDamage;
    return (*this);
}

void ClapTrap::attack(std::string const &target) {
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing "
              << _AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamege(unsigned int amount) {
    std::cout << _Name << " takes ";

    if (_Hitpoints < amount) {
        std::cout << _Hitpoints << " damage!" << std::endl;
        _Hitpoints = 0;
    } else {
        std::cout << amount << " damage!" << std::endl;
        _Hitpoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << _Name << " is repaired " << amount << " points" << std::endl;
    _Hitpoints += amount;
}

std::string ClapTrap::getName() const { return _Name; }

void ClapTrap::setName(const std::string &name) { _Name = name; }
