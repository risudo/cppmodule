#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	~ClapTrap();

	void	attack(std::string const &target);
	void	takeDamege(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap	&operator=(const ClapTrap &r);

private:
	std::string	Name;
	int			Hitpoints;
	int			Energy_points;
	int			Attack_damage;
};
