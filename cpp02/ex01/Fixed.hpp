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

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _rowBits;
    const static int _offset = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
