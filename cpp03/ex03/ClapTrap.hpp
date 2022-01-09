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
    std::string getName() const;

protected:
    void setName(const std::string &name);
    unsigned int _Hitpoints;
    unsigned int _EnergyPoints;
    unsigned int _AttackDamage;

private:
    std::string _Name;
};

#endif
