#include <iostream>

template<typename T>
void write(T a)
{
	std::cout << a << std::endl;
}


template<typename T>
void iter(T *arr, std::size_t len, void (*func)(T))
{
	for (std::size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}
