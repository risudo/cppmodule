#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("a");

	a.attack("b");
	a.takeDamege(10);
	a.beRepaired(10);
	a.guardGate();
}
