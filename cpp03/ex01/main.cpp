#include "ScavTrap.hpp"

int main(void) {
    ScavTrap a("a");

    a.attack("b");
    a.takeDamege(60);
    a.takeDamege(60);
    a.beRepaired(10);

    a.guardGate();
}
