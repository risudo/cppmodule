#include "Fixed.hpp"

#include "iostream"

Fixed::Fixed() : _rowBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    _rowBits = fixed.getRawBits();
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &r) {
    std::cout << "Assignation operator called" << std::endl;
    _rowBits = r.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _rowBits = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (_rowBits);
}
