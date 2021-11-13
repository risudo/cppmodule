#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed 		a;
	Fixed const	b( Fixed(5.05f) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << "max: " << Fixed::max(a, b) << std::endl;

	std::cout << "min: "<< Fixed::min(a, b) << std::endl;
	Fixed c(5.05f);
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "c is     " << c << std::endl;
	std::cout << "a is     " << a << std::endl;
	std::cout << "c - a is " << c - a << std::endl;
	std::cout << "a * c is " << a * c << std::endl;
	std::cout << "a * -2 is " << a * Fixed(-2) << std::endl;
	std::cout << "c / a is " << c / a << std::endl;
	return 0;
}
