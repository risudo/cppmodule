#include <iostream>

#include "test.hpp"
#include "whatever.hpp"

int main(void) {
    {
        int a = 1;
        int b = 2;
        test(a, b);
    }
    {
        std::cout << "-------------------------------" << std::endl;
        std::string a = "chaine1";
        std::string b = "chaine2";
        test(a, b);
    }
    {
        std::cout << "-------------------------------" << std::endl;
        const char e = 'a';
        const char f = 'b';
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
        std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
    }
    return 0;
}
