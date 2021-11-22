#include <iostream>
#include "iter.hpp"

int main()
{
	char arr1[] = {'a', 'b', 'c', 'd'};
	int arr2[] = {1, 2, 3, 4, 5, 6};

	std::cout << "--- test1 ---" << std::endl;
	iter(arr1, 3, &write);

	std::cout << "\n--- test2 ---" << std::endl;
	iter(arr2, 5, &write);
}

