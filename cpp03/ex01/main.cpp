#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamege(5);
	b.takeDamege(7);
	b.beRepaired(10);
	b.takeDamege(5);
}
