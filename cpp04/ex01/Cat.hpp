#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(Cat const &other);
	Cat &operator=(Cat const &other);
	std::string	getType() const;
	void	makeSound() const;

private:
	Brain	*brain;
};

#endif
