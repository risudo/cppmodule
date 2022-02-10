#ifndef EASYFINDTEST_HPP
#define EASYFINDTEST_HPP

#include <iostream>

template <typename T>
void testEasyfind(T intVec, int num) {
    try {
        std::cout << "call easyfind with "
                  << "[[ " << num << " ]]" << std::endl;
        typename T::iterator it = easyfind(intVec, num);
        std::cout << "iterator: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

#endif  // EASYFINDTEST_HPP
