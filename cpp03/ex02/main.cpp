#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    FragTrap a("a");

    a.attack("b");
    a.takeDamege(90);
    a.takeDamege(20);
    a.highFivesGuys();
}
