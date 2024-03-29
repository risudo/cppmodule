#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &other);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap const &other);

    void attack(std::string const &target);
    void guardGate();
protected:
    static const unsigned int defaultHitpoints = 100;
    static const unsigned int defaultEnergyPoints = 50;
    static const unsigned int defaultAttackDamage = 20;
};

#endif
