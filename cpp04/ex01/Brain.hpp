#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
public:
    Brain();
    virtual ~Brain();
    Brain(Brain const &other);
    Brain &operator=(Brain const &other);

private:
	std::string	ideas[100];
};

#endif
