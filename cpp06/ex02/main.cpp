#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
    std::srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        Base *p = generate();
        std::cout << "reference identify" << std::endl;
        identify(p);
        std::cout << "pointer identify" << std::endl;
        identify(*p);
        std::cout << std::endl;
    }
    Base *p = NULL;
    identify(p);
}
