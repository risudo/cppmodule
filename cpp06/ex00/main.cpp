#include <iostream>
#include <string>

#include "Converter.hpp"

void printConvert(std::string str) {
    Converter conv(str);

    if (conv.init() == -1) {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: impossibel" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    s_char c = conv.toChar();
    if (c.imposible == true) {
        std::cout << "char: imposible" << std::endl;
    } else {
        std::cout << "char: " << c.value << std::endl;
    }

    s_int i = conv.toInt();
    if (i.impossible == true) {
        std::cout << "int: impossibel" << std::endl;
    } else {
        std::cout << "int: " << i.value << std::endl;
    }

    s_float f = conv.toFloat();
    if (f.impossible == true) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << f.value << std::endl;
    }

    s_double d = conv.toDouble();
    if (d.impossible == true) {
        std::cout << "double: impossible" << std::endl;
    } else {
        std::cout << "double: " << d.value << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "bad argument" << std::endl;
        return 1;
    }
    printConvert(argv[1]);
    return 0;
}
