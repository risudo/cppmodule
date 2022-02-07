#include <iostream>
#include <string>

#include "iter.hpp"

int main() {
    {
        std::cout << "--- char ---" << std::endl;
        char arr[] = {'a', 'b', 'c', 'd'};
        iter(arr, 3, &write);
    }

    {
        std::cout << "\n--- int ---" << std::endl;
        int arr[] = {1, 2, 3, 4, 5, 6};
        iter(arr, 6, &write);
    }

    {
        std::cout << "\n--- string ---" << std::endl;
        std::string arr[] = {"hgoe", "hogeee"};
        iter(arr, 2, &write);
    }
}
