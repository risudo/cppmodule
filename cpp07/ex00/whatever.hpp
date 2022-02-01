#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
const T& max(const T& a, const T& b) {
    if (a < b) {
        return b;
    }
    return a;
}

template <typename T>
const T& min(const T& a, const T& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
#endif  // WHATEVER_HPP
