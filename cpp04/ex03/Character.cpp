#include "Character.hpp"
#include <iostream>

Character::Character():
	_name("")
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(std::string name):
	_name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
		}
	}
}

Character::Character(Character const &other)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	*this = other;
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
			{
				delete _inventory[i];
			}
			if (other._inventory[i] != NULL) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
		}
		_name = other._name;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
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

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		return ;
	}
	if (_inventory[idx] != NULL)
	{
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
	{
		return ;
	}
	_inventory[idx]->use(target);
}
