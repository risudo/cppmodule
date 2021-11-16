#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);
	std::string	getType() const;
	void	makeSound() const;

protected:
	std::string	type;

};

#endif
