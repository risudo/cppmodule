#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
    virtual ~Dog();
    Dog(Dog const &other);
    Dog	&operator=(Dog const &other);
	std::string	getType() const;
	void	makeSound() const;
	void	printBrainPtr() const;

private:
	Brain	*brain;
};

#endif
