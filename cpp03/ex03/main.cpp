#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
	DiamondTrap d("diamond");

	d.WhoAmI();
	d.ScavTrap::attack("enemy");
}
