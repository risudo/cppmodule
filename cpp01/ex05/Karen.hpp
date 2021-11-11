#include <string>

class Karen
{
public:
	Karen();
	void	complain(std::string level);

private:
	void	(Karen::*f[5])();
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	do_nothing(void);
};
