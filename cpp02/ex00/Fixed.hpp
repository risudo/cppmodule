#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &r);
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _rowBits;
    const static int _offset = 8;
};

#endif
