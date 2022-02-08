#include <iostream>
#include <string>

#include "iter.hpp"

int main() {
    {
        std::cout << "\n--- int ---" << std::endl;
        int arr[] = {1, 2, 3, 4};
        std::size_t size = 4;
        iter(arr, size, &putElement);
        iter(arr, size, &incrementAndPut);
    }
    {
        std::cout << "\n--- string ---" << std::endl;
        const std::string arr[] = {"hoge", "hogeee"};
        const std::size_t size = 2;
        iter(arr, size, &putElement);
    }
}
