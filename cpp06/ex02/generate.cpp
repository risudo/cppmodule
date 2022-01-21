#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    int rand = std::rand() % 3;

    if (rand == 0) {
        std::cout << "generate func returns A" << std::endl;
        return new A();
    } else if (rand == 1) {
        std::cout << "generate func returns B" << std::endl;
        return new B();
    } else {
        std::cout << "generate func returns C" << std::endl;
        return new C();
    }
}

