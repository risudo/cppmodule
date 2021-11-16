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
    }
    return *this;
}
