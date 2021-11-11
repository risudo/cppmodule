#include <string>

class Karen
{
public:
	Karen();
	void complain(std::string level);

private:
	void (Karen::*f[4])();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};
