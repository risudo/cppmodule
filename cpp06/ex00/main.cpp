#include <iostream>
#include <sstream>
#include <string>

#include "Converter.hpp"

void printConvert(std::string str) {
		std::cout << "str: " << str << std::endl;
    Converter conv(str);

    if (conv.init() == -1) {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: impossibel" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << str << " type: " << conv.getType() << std::endl;
    return;
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
	std::cout << "\n";
    printConvert("2147483648");
	std::cout << "\n";
    printConvert("aa");
	std::cout << "\n";
    printConvert("+inf");
	std::cout << "\n";
    printConvert("0f");
	std::cout << "\n";
    printConvert("10");
	std::cout << "\n";
    printConvert("10.0");

    return 0;
}
