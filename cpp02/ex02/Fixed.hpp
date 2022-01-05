#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(int n);
    Fixed(float n);
    ~Fixed();

    Fixed &operator=(const Fixed &r);

    bool operator>(Fixed const &fixed) const;
    bool operator<(Fixed const &fixed) const;
    bool operator>=(Fixed const &fixed) const;
    bool operator<=(Fixed const &fixed) const;
    bool operator==(Fixed const &fixed) const;
    bool operator!=(Fixed const &fixed) const;

    Fixed operator+(Fixed const &fixed) const;
    Fixed operator-(Fixed const &fixed) const;
    Fixed operator*(Fixed const &fixed) const;
    Fixed operator/(Fixed const &fixed) const;

    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator--();
    Fixed &operator++();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed const &max(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &min(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);

private:
    int _rowBits;
    const static int _offset = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
