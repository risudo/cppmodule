class	Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator=(const Fixed& r);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_value;
	const static int	bits = 8;
};
