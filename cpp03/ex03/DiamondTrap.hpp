#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap,
                    public ScavTrap {
public:
    DiamondTrap();
    DiamondTrap(std::string const &name);
    DiamondTrap(DiamondTrap const &other);
    DiamondTrap &operator=(DiamondTrap const &other);
    virtual ~DiamondTrap();
    void attack(std::string const &target);
    std::string getName() const;
    unsigned int getHitpoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    void WhoAmI();

private:
    std::string _Name;
};

#endif
