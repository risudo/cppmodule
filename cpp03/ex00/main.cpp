#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("a");
	ClapTrap b("b");

	a.attack("b");
	b.takeDamege(10);
}
