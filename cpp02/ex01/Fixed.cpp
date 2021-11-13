#include "Fixed.hpp"
#include "iostream"
#include <cmath>

Fixed::Fixed():
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = fixed.getRawBits();
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value * (1 << bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	
	union {float f; int i; } a;
	a.f = value;
	/* std::cout << "1 << 8      : " << std::bitset<32>(1 << bits) << std::endl; */
	/* std::cout << "value       : "; */
	/* for (int i = 31; i >= 0; i--) */
	/* { */
	/* 	std::cout << ((a.i >> i) & 1); */
	/* } */
	/* std::cout << std::endl; */
	/* std::cout << "value*(1<<8): " << std::bitset<32>(value * (1 << bits)) << std::endl; */

	_value = roundf(value * (1 << bits));

}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& r)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &r)
		this->_value = r.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << bits));
}

int	Fixed::toInt(void) const
{
	return ((int)_value / (1 << bits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

