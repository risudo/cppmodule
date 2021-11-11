#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *zombie = newZombie("hoge");

	zombie->announce();
	delete zombie;
	randomChump("piyo");
	std::cout << "return" << std::endl;
	return (0);
}
