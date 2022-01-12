#include <iostream>

#include "ScavTrap.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int main(void) {
    {
        std::cout << GREEN << "--- ClapTrap test --- " << RESET << std::endl;
        ClapTrap a("clap");

        std::cout << "EnergyPoints: " << a.getEnergyPoints()
                  << std::endl;  // will be 10
        a.attack("enemy");       // will cause 0 damage
        a.takeDamege(7);         // will take 7 damage
        a.takeDamege(7);         // will take 3 damage
        a.takeDamege(7);         // will take 0 damage
        a.beRepaired(5);
        a.takeDamege(6);  // will take 5 damage
    }
    {
        std::cout << GREEN << "--- ScavTrap test --- " << RESET << std::endl;
        ScavTrap a("scav");

        std::cout << "EnergyPoints: " << a.getEnergyPoints()
                  << std::endl;  // will be 50
        a.attack("enemy");       // will cause 20 damage
        a.takeDamege(60);        // will take 60 damage
        a.takeDamege(60);        // will take 40 damage
        a.beRepaired(10);

        a.guardGate();
    }
}
