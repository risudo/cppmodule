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
	std::string _Name;
    void WhoAmI();
};

#endif
