#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <string>
class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(AMateria const &other);
	virtual AMateria	&operator=(AMateria const &other);
	std::string const	&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string _type;
};

#endif
