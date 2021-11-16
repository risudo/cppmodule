#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	std::string	getType() const;
	virtual void	makeSound() const = 0;

protected:
	std::string	type;

};

#endif
