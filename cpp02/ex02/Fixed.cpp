#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _rowBits(0) {}

Fixed::Fixed(const Fixed &fixed) { _rowBits = fixed.getRawBits(); }

Fixed::Fixed(const int value) { _rowBits = value * (1 << _offset); }

Fixed::Fixed(const float value) { _rowBits = roundf(value * (1 << _offset)); }

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &r) {
    _rowBits = r.getRawBits();
    return (*this);
}

void Fixed::setRawBits(int const raw) { _rowBits = raw; }

int Fixed::getRawBits(void) const { return (_rowBits); }

float Fixed::toFloat(void) const {
    return (static_cast<float>(_rowBits) / (1 << _offset));
}

int Fixed::toInt(void) const { return (_rowBits / (1 << _offset)); }

bool Fixed::operator>(Fixed const &fixed) const {
    return (_rowBits > fixed.getRawBits());
}

bool Fixed::operator<(Fixed const &fixed) const {
    return (_rowBits < fixed.getRawBits());
}

bool Fixed::operator>=(Fixed const &fixed) const {
    return (_rowBits >= fixed.getRawBits());
}

bool Fixed::operator<=(Fixed const &fixed) const {
    return (_rowBits <= fixed.getRawBits());
}

bool Fixed::operator==(Fixed const &fixed) const {
    return (_rowBits == fixed.getRawBits());
}

bool Fixed::operator!=(Fixed const &fixed) const {
    return (_rowBits != fixed.getRawBits());
}

Fixed Fixed::operator+(Fixed const &fixed) const {
    Fixed ret;

    ret.setRawBits(_rowBits + fixed.getRawBits());
    return (ret);
}

Fixed Fixed::operator-(Fixed const &fixed) const {
    Fixed ret;

    ret.setRawBits(_rowBits - fixed.getRawBits());
    return (ret);
}

Fixed Fixed::operator*(Fixed const &fixed) const {
    long left = _rowBits;
    long right = fixed.getRawBits();
    Fixed ret;

    ret.setRawBits(static_cast<int>(left * right / (1 << _offset)));
    return (ret);
}

Fixed Fixed::operator/(Fixed const &fixed) const {
    Fixed ret;

    if (fixed.getRawBits() == 0) {
        std::cout << "division by 0" << std::endl;
        return ret;
    }
    long left = _rowBits;
    ret.setRawBits(static_cast<int>(left * (1 << _offset) / fixed.getRawBits()));
    return (ret);
}

// post-increment
Fixed Fixed::operator++(int) {
    Fixed old(*this);

    _rowBits++;
    return (old);
}

// pre-increment
Fixed &Fixed::operator++() {
    ++_rowBits;
    return (*this);
}

// post-decriment
Fixed Fixed::operator--(int) {
    Fixed old(*this);

    _rowBits--;
    return (old);
}

// pre-decriment
Fixed &Fixed::operator--() {
    --_rowBits;
    return (*this);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    else
        return (b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return (os);
}
