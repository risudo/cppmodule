#include "Converter.hpp"

#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>

Converter::Converter() {}

Converter::Converter(std::string str) {
    _str = str;
    _special = false;
    _c = 0;
    _i = 0;
    _f = 0.0f;
    _d = 0.0;
}

Converter::~Converter() {}

Converter::Converter(Converter const &other) { *this = other; }

Converter &Converter::operator=(Converter const &other) {
    if (this != &other) {
        _str = other._str;
        _special = other._special;
        _c = other._c;
        _i = other._i;
        _f = other._f;
        _d = other._d;
    }
    return *this;
}

e_type Converter::getType() const { return _type; }

void Converter::detectType() {
    if (_str == "-inff" || _str == "+inff" || _str == "nanf") {
        _type = FLOAT;
        _special = true;
        return;
    }
    if (_str == "-inf" || _str == "+inf" || _str == "nan") {
        _type = DOUBLE;
        _special = true;
        return;
    }
    if (_str.size() == 1 && std::isprint(_str[0]) && !std::isdigit(_str[0])) {
        _type = CHAR;
        return;
    }
    if (_str[_str.size() - 1] == 'f') {
        _type = FLOAT;
        return;
    }

    bool dot = false;
    for (std::size_t i = 0; i < _str.size() - 1; i++) {
        if (_str[i] == '.') {
            dot = true;
            break;
        }
    }
    if (dot == false) {
        _type = INT;
        return;
    }
    _type = DOUBLE;
}

void Converter::acquireChar() { _c = _str[0]; }

int Converter::acquireInt() {
    bool sign = false;
    for (std::size_t i = 0; i < _str.size() - 1; i++) {
        if (sign == false && (_str[i] == '-' || _str[i] == '+')) {
            sign = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            return -1;
        }
    }
    std::istringstream s(_str);
    if (!(s >> _i)) {
        return -1;
    }
    return 0;
}

int Converter::acquireFloat() {
    int sign = 0;
    bool dot = false;
    if (_special || _str[0] == '+' || _str[0] == '-') {
        sign = 1;
    } else if (!std::isdigit(static_cast<int>(_str[0]))) {
        return -1;
    }
    for (std::size_t i = 0 + sign; i < _str.size() - 1; i++) {
        if (_special == true) {
            break;
        }
        if (dot == false && _str[i] == '.') {
            dot = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            return -1;
        }
    }
    _str.erase(_str.size() - 1);
    std::istringstream s(_str);
    if (!(s >> _f)) {
        return -1;
    }
    return 0;
}

int Converter::acquireDouble() {
    int sign = 0;
    bool dot = false;
    if (_special || _str[0] == '+' || _str[0] == '-') {
        sign = 1;
    } else if (!std::isdigit(static_cast<int>(_str[0]))) {
        return -1;
    }
    for (std::size_t i = 0 + sign; i < _str.size() - 1; i++) {
        if (_special == true) {
            break;
        }
        if (dot == false && _str[i] == '.') {
            dot = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            return -1;
        }
    }
    std::stringstream s(_str);
    if (!(s >> _d)) {
        return -1;
    }
    return 0;
}

int Converter::init() {
    detectType();

    switch (_type) {
        case CHAR:
            acquireChar();
            break;
        case INT:
            return acquireInt();
        case FLOAT:
            return acquireFloat();
        case DOUBLE:
            return acquireDouble();
    }
    return 0;
}

static bool isInRange(double const &value, double const &min,
                      double const &max) {
    return (value <= max && value >= min);
}

void putFloat(float const &value, std::string const &type) {
    if (value - static_cast<int>(value) == static_cast<float>(0)) {
        std::cout << type << std::fixed << std::setprecision(0) << value
                  << ".0f" << std::endl;
    } else {
        std::cout << type << value << "f" << std::endl;
    }
}

void putDouble(double const &value, std::string const &type) {
    if (value - static_cast<int>(value) == static_cast<double>(0)) {
        std::cout << type << std::fixed << std::setprecision(0) << value << ".0"
                  << std::endl;
    } else {
        std::cout << type << value << std::endl;
    }
}

void Converter::intCase(std::string const type[]) {
    if (!isInRange(static_cast<double>(_i), static_cast<double>(CHAR_MIN),
                   static_cast<double>(CHAR_MAX))) {
        std::cout << type[CHAR] << "impossible" << std::endl;
    } else if (!std::isprint(_i)) {
        std::cout << type[CHAR] << "Non displayable" << std::endl;
    } else {
        std::cout << type[CHAR] << "'" << static_cast<char>(_i) << "'"
                  << std::endl;
    }

    std::cout << type[INT] << _i << std::endl;
    putFloat(static_cast<float>(_i), type[FLOAT]);
    putDouble(static_cast<double>(_i), type[DOUBLE]);
}

void Converter::floatCase(std::string const type[]) {
    if (!isInRange(static_cast<double>(_f), static_cast<double>(CHAR_MIN),
                   static_cast<double>(CHAR_MAX))) {
        std::cout << type[CHAR] << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(_f))) {
        std::cout << type[CHAR] << "Non displayable" << std::endl;
    } else {
        std::cout << type[CHAR] << "'" << static_cast<char>(_f) << "'"
                  << std::endl;
    }

    if (!isInRange(static_cast<double>(_f), static_cast<double>(INT_MIN),
                   static_cast<double>(INT_MAX))) {
        std::cout << type[INT] << "impossible" << std::endl;
    } else {
        std::cout << type[INT] << static_cast<int>(_f) << std::endl;
    }

    putFloat(_f, type[FLOAT]);
    putDouble(static_cast<double>(_f), type[FLOAT]);
}

void Converter::doubleCase(std::string const type[]) {
    if (!isInRange(_d, static_cast<double>(CHAR_MIN),
                   static_cast<double>(CHAR_MAX))) {
        std::cout << type[CHAR] << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(_d))) {
        std::cout << type[CHAR] << "Non displayable" << std::endl;
    } else {
        std::cout << type[CHAR] << "'" << static_cast<char>(_d) << "'"
                  << std::endl;
    }

    if (!isInRange(_d, static_cast<double>(INT_MIN),
                   static_cast<double>(INT_MAX))) {
        std::cout << type[INT] << "impossible" << std::endl;
    } else {
        std::cout << type[INT] << static_cast<int>(_d) << std::endl;
    }

    if (!_special && (!isInRange(_d, static_cast<double>(FLT_MAX * -1),
                                 static_cast<double>(FLT_MAX)) ||
                      _d < static_cast<double>(FLT_MIN) ||
                      _d > static_cast<double>(FLT_MIN * -1))) {
        std::cout << type[FLOAT] << "impossible" << std::endl;
    } else {
        putFloat(static_cast<float>(_d), type[FLOAT]);
    }
    putDouble(_d, type[DOUBLE]);
}

void Converter::printConverted() {
    const std::string type[] = {"char: ", "int: ", "float: ", "double: "};

    switch (_type) {
        case CHAR:
            std::cout << type[CHAR] << "'" << _c << "'" << std::endl;
            std::cout << type[INT] << static_cast<int>(_c) << std::endl;
            putFloat(static_cast<float>(_c), type[FLOAT]);
            putDouble(static_cast<double>(_c), type[DOUBLE]);
            break;
        case INT:
            intCase(type);
            break;
        case FLOAT:
            floatCase(type);
            break;
        case DOUBLE:
            doubleCase(type);
            break;
    }
}
