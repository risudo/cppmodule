#include <iostream>
#include "iter.hpp"
#include <string>

int main()
{
	{
		std::cout << "--- test1 ---" << std::endl;
		char arr[] = {'a', 'b', 'c', 'd'};
		iter(arr, 3, &write);
	}

	{
		std::cout << "\n--- test2 ---" << std::endl;
		int arr[] = {1, 2, 3, 4, 5, 6};
		iter(arr, 6, &write);
	}

	{
		std::cout << "\n--- test3 ---" << std::endl;
		std::string arr[] = {"hgoe", "fuga"};
		iter(arr, 5, &write);
	}
}

