#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
	DiamondTrap d("diamond");

	d.WhoAmI();
	std::cout << "Hitpoints: " << d.getHitpoints() << std::endl;
	std::cout << "EnergyPoints: " << d.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << d.getAttackDamage() << std::endl;
	d.ScavTrap::attack("enemy");
}
