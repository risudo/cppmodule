#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():
	_value(0)
{
}

Fixed::Fixed(const Fixed &fixed)
{
	_value = fixed.getRawBits();
}

Fixed::Fixed(const int value)
{
	_value = value * (1 << _offset);
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _offset));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed& r)
{
	_value = r.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _offset));
}

int	Fixed::toInt(void) const
{
	return (static_cast<int>(_value) / (1 << _offset));
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (_value > fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (_value < fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (_value >= fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (_value <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (_value == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (_value != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	ret;

	ret.setRawBits(_value + fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	ret;

	ret.setRawBits(_value - fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	long	left = _value;
	long	right = fixed.getRawBits();
	Fixed	ret;

	ret.setRawBits(static_cast<int>(left * right / (1 << _offset)));
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	ret;

	if (fixed.getRawBits() == 0)
	{
		std::cout << "division by 0" << std::endl;
		exit(1);
	}
	ret.setRawBits(_value / fixed.getRawBits() * (1 << _offset));
	return (ret);
}

// post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	_value++;
	return (old);
}

// pre-increment
Fixed	&Fixed::operator++()
{
	++_value;
	return (*this);
}

// post-decriment
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	_value--;
	return (old);
}

// pre-decriment
Fixed	&Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed	const &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed	const &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	 &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
