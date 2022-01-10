#include "Converter.hpp"

#include <cfloat>
#include <climits>
#include <sstream>

Converter::Converter() {}

Converter::Converter(std::string str) {
    _str = str;
    _c.value = 0;
    _c.imposible = false;
    _i.value = 0;
    _i.impossible = false;
    _f.value = 0.0f;
    _f.impossible = false;
    _d.value = 0.0;
    _d.impossible = false;
}

Converter::~Converter() {}

Converter::Converter(Converter const &other) { *this = other; }

Converter &Converter::operator=(Converter const &other) {
    if (this != &other) {
    }
    return *this;
}

e_type Converter::getType() const { return _type; }

void Converter::detectType() {
    if (_str == "-inff" || _str == "+inff" || _str == "nanf") {
        _type = FLOAT;
        return;
    }
    if (_str == "-inf" || _str == "+inf" || _str == "nan") {
        _type = DOUBLE;
        return;
    }
    if (_str.length() == 1 && std::isprint(_str[0]) && !std::isdigit(_str[0])) {
        _type = CHAR;
        return;
    }
    if (_str[_str.length() - 1] == 'f') {
        _type = FLOAT;
        return;
    }

    bool dot = false;
    for (std::size_t i = 0; i < _str.length() - 1; i++) {
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

void Converter::acquireChar() {
    _c.value = _str[0];
    _c.imposible = false;
}

void Converter::acquireInt() {
    bool minus = false;
    for (std::size_t i = 0; i < _str.length() - 1; i++) {
        if (minus == false && _str[i] == '-') {
            minus = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            _i.impossible = true;
            return;
        }
    }
    std::stringstream s(_str);
    s >> _i.value;
    if (!s) {
        _i.impossible = true;
    }
    /* if (tmp > static_cast<double>(INT_MAX) || */
    /*     tmp < static_cast<double>(INT_MIN)) { */
    /*     _i.impossible = true; */
    /*     return; */
    /* } */
    /* s >> _i.value; */
}

void Converter::acquireFloat() {
    bool dot = false;
    bool minus = false;
    for (std::size_t i = 0; i < _str.length() - 1; i++) {
        if (minus == false && _str[i] == '-') {
            minus = true;
            continue;
        }
        if (dot == false && _str[i] == '.') {
            dot = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            _f.impossible = true;
        }
    }
    std::stringstream s(_str);
    s >> _f.value;
    if (!s) {
        _i.impossible = true;
    }
}

void Converter::acquireDouble() {
    bool dot = false;
    bool minus = false;
    for (std::size_t i = 0; i < _str.length() - 1; i++) {
        if (minus == false && _str[i] == '-') {
            minus = true;
            continue;
        }
        if (dot == false && _str[i] == '.') {
            dot = true;
            continue;
        }
        if (!std::isdigit(_str[i])) {
            _d.impossible = true;
        }
    }
    std::stringstream s(_str);
    s >> _d.value;
    if (!s) {
        _i.impossible = true;
    }
}

int Converter::init() {
    detectType();
    bool impossible = false;

    if (_type == CHAR) {
        acquireChar();
    } else if (_type == INT) {
        acquireInt();
        impossible = _i.impossible;
    } else if (_type == FLOAT) {
        acquireFloat();
        impossible = _f.impossible;
    } else if (_type == DOUBLE) {
        acquireDouble();
        impossible = _d.impossible;
    }
    if (impossible == true) {
        return -1;
    }
    return 0;
}
