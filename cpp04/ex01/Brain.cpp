#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

Brain::Brain(Brain const &other)
{
    *this = other;
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
