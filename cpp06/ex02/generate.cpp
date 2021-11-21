#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(time(NULL));
	int rand = std::rand() % 3;
	
	if (rand == 0) {
		std::cout << "return A" << std::endl;
		return new A();
	} else if (rand == 1) {
		std::cout << "return B" << std::endl;
		return new B();
	} else {
		std::cout << "return C" << std::endl;
		return new C();
	}
}

