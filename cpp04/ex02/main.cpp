#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	Animal *a[8];
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << std::endl;
		a[i] = new Dog();
	}
	for (int i = 4; i < 8; i++)
	{
		std::cout << i << std::endl;
		a[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		delete a[i];
	}
	//system("leaks a.out");
}
