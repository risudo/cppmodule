#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    _Name = "";
    FragTrap::setName("_clap_name");
}

DiamondTrap::DiamondTrap(std::string const &name) {
    _Name = name;
    FragTrap::setName(name + "_clap_name");
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
