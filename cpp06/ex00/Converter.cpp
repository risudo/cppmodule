#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(std::string str) {
	_str = str;
}

Converter::~Converter() {}

Converter::Converter(Converter const &other) { *this = other; }

Converter &Converter::operator=(Converter const &other) {
    if (this != &other) {
    }
    return *this;
}

void Converter::convert() {
/*
	type = getType(_str)

	if (type == CHAR) {

	} else if (type == INT) {

	} else if 
*/
}
