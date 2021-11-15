#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	virtual ~ClapTrap();

	void	attack(std::string const &target);
	void	takeDamege(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap	&operator=(const ClapTrap &r);

protected:
	std::string		Name;
	unsigned int	Hitpoints;
	unsigned int	Energy_points;
	unsigned int	Attack_damage;

};

#endif