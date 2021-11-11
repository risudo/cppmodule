#include "Zombie.hpp"
#include <cstdlib>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	const int	n = 5;
	Zombie *zombiehorde = zombieHorde(n, "rio");
	
	for (int i = 0; i < n; i++)
	{
		zombiehorde[i].announce();
	}
	delete [] zombiehorde;
}
