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
    static const unsigned int defaultHitpoints = 100;
    static const unsigned int defaultEnergyPoints = 100;
    static const unsigned int defaultAttackDamage = 30;
};

#endif
