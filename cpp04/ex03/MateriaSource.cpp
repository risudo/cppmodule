#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource constructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
		}
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i] != NULL) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
		{
			return ;
		}
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
		{
			return _inventory[i]->clone();
		}
	}
	return 0;
}
