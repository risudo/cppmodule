#include <iostream>
#include <iomanip>
#include "Data.hpp"

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

int main()
{
	Data data;
	data.num = 42;
	std::cout << "&data   : " << &data << std::endl;
	std::cout << "data.num   : " << data.num << std::endl;

	uintptr_t raw;
	raw = serialize(&data);
	std::cout << "raw     : " << std::hex << std::showbase << raw << std::endl;

	Data *deserial;
	deserial = deserialize(raw);
	std::cout << "deserial: " << std::hex << std::showbase << raw << std::endl;
	std::cout << "deserial.num   : " << std::resetiosflags(std::ios::showbase) << std::resetiosflags(std::ios::hex) << deserial->num << std::endl;
}
