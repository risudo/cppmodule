#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

void	test1()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	test2()
{
	std::cout << "\n---test2---\n" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter *me = new Character("me");
	ICharacter *bob = new Character("bob");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main()
{
	test1();
	test2();
	system("leaks a.out");
}
