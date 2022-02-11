#ifndef EASYFINDTEST_HPP
#define EASYFINDTEST_HPP

#include <iostream>

template <typename T>
void testEasyfind(T container, int num) {
    try {
        std::cout << "call easyfind with "
                  << "[[ " << num << " ]]" << std::endl;
        typename T::iterator it = easyfind(container, num);
        std::cout << "found the number. iterator: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

#endif  // EASYFINDTEST_HPP
