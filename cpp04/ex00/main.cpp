#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n--- wrong version test ---\n" << std::endl;

	const WrongAnimal *wmeta = new WrongAnimal();
	const WrongAnimal *wi = new WrongCat();

	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will output the cat sound!
	wmeta->makeSound();
	
	delete wmeta;
	delete wi;
}
