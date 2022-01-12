#include <iostream>

#include "DiamondTrap.hpp"

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
    {
        std::cout << GREEN << "--- FragTrap test --- " << RESET << std::endl;
        FragTrap a("flag");

        std::cout << "EnergyPoints: " << a.getEnergyPoints()
                  << std::endl;  // will be 100
        a.attack("enemy");       // will cause 30 damage
        a.takeDamege(90);        // will take 90 damage
        a.takeDamege(20);        // will take 10 damage
        a.beRepaired(30);
        a.highFivesGuys();
    }
    {
        std::cout << GREEN << "--- DiamondTrap test --- " << RESET << std::endl;
        DiamondTrap d("diamond");

        std::cout << "EnergyPoints: " << d.getEnergyPoints()
                  << std::endl;  // will be 100
        d.WhoAmI();
        d.attack("enemy");  // will cause 30 damage && call ScavTrap attack
        d.takeDamege(80);   // will take 80 damage
        d.takeDamege(50);   // will take 20 damage
        d.beRepaired(30);
    }
}
