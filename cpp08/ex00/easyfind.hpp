#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <string>

template <typename T>
typename T::iterator easyfind(T &container, int i) {
    typename T::iterator pos = std::find(container.begin(), container.end(), i);
    if (pos == container.end()) {
        throw std::runtime_error("the number is not found");
    }
    return pos;
}

#endif  // EASYFIND_HPP
