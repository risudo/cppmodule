#include <iostream>
#include <sstream>
#include <string>

#include "Converter.hpp"

void printConvert(std::string str) {
    Converter conv(str);

    if (conv.init() == -1) {
        std::cout << "char: imposible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    conv.printConverted();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "bad argument" << std::endl;
        return 1;
    }
    printConvert(argv[1]);
    return 0;
}

//TODO: 指数表記めんどい問題
