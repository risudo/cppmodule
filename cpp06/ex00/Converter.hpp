#ifndef Converter_HPP
#define Converter_HPP

#include <string>

enum e_type { CHAR, INT, FLOAT, DOUBLE };

struct s_char {
    char value;
    bool imposible;
};

struct s_int {
    int value;
    bool impossible;
};

struct s_float {
    float value;
    bool impossible;
};

struct s_double {
    double value;
    bool impossible;
};

class Converter {
public:
    Converter();
    Converter(std::string str);
    virtual ~Converter();
    Converter(Converter const &other);
    Converter &operator=(Converter const &other);
    void convert();
	int init();
    s_char toChar();
    s_int toInt();
    s_float toFloat();
    s_double toDouble();

private:
    std::string _str;
    e_type _type;
    s_char _c;
    s_int _i;
    s_float _f;
    s_double _d;
};

#endif
