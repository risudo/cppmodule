#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(time(NULL));
	int rand = std::rand() % 3;
	
	if (rand == 0) {
		return new A();
	} else if (rand == 1) {
		return new B();
	} else {
		return new C();
	}
}

