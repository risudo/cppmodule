#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a) {
		std::cout << "It is A" << std::endl;
	} else if (b) {
		std::cout << "It is B" << std::endl;
	} else if (c) {
		std::cout << "It is C" << std::endl;
	}
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "It is A" << std::endl;
		static_cast<void>(a);
	} catch (std::bad_cast) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "It is B" << std::endl;
		static_cast<void>(b);
	} catch (std::bad_cast) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "It is C" << std::endl;
		static_cast<void>(c);
	} catch (std::bad_cast) {}
}
