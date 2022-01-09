#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
public:
    FragTrap();
    FragTrap(std::string const &name);
    FragTrap(FragTrap const &other);
    ~FragTrap();
    FragTrap &operator=(FragTrap const &other);

    void attack(std::string const &target);
    void highFivesGuys(void);

protected:
    unsigned int FragTrap_Hitpoints;
    unsigned int FragTrap_EnergyPoints;
    unsigned int FragTrap_AttackDamage;
};

#endif
