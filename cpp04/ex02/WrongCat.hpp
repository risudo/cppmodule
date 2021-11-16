#ifndef WRONGCat_HPP
# define WRONGCat_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(WrongCat const &other);
	WrongCat &operator=(WrongCat const &other);
	std::string	getType() const;
	void	makeSound() const;

private:

};

#endif
