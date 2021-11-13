#include <ostream>

class	Fixed
{
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(int n);
	Fixed(float n);
	~Fixed();
	Fixed& operator=(const Fixed& r);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_value;
	const static int	bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
