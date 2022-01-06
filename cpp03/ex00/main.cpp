#include "ClapTrap.hpp"

int main(void) {
    ClapTrap a("a");

    a.attack("b");
    a.takeDamege(7);
    a.takeDamege(7);
    a.takeDamege(7);

    a.beRepaired(5);

    a.takeDamege(6);
}
