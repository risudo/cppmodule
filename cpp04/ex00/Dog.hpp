#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    virtual ~Dog();
    Dog(Dog const &other);
    Dog	&operator=(Dog const &other);
	std::string	getType() const;
	void	makeSound() const;

private:

};

#endif
