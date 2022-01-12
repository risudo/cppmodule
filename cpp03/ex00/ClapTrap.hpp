#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &claptrap);
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap &r);

    void attack(std::string const &target);
    void takeDamege(unsigned int amount);
    void beRepaired(unsigned int amount);
	unsigned int getEnergyPoints() const;

private:
    std::string _Name;
    unsigned int _Hitpoints;
    unsigned int _EnergyPoints;
    unsigned int _AttackDamage;
};

#endif
