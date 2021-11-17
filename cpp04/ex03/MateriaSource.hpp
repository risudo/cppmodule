#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	void		learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);

private:
	AMateria	*_inventory[4];
};

#endif
