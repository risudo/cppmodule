#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _rowBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->_rowBits = fixed.getRawBits();
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rowBits = value * (1 << _offset);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rowBits = roundf(value * (1 << _offset));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &r) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &r)
        this->_rowBits = r.getRawBits();
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

float Fixed::toFloat(void) const {
    return (static_cast<float>(_rowBits) / (1 << _offset));
}

int Fixed::toInt(void) const { return (_rowBits / (1 << _offset)); }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}
