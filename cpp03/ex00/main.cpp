#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    {
        ClapTrap a("a");

        std::cout << "EnergyPoints: " << a.getEnergyPoints()
                  << std::endl;  // will be 10
        a.attack("enemy"); // will cause 0 damage
        a.takeDamege(7);
        a.takeDamege(7);  // will take 3 damage
        a.takeDamege(7);  // will take 0 damage
        a.beRepaired(5);
        a.takeDamege(6);  // will take 5 damage
    }
    {
        ClapTrap nn;
        nn.attack("enemy");  // ClapTrap name is NONAME
    }
}
