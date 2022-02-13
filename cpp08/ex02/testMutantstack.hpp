#include <iostream>

#include "mutantstack.hpp"

#define YELLO "\033[33m"
#define RESET "\033[39m"

template <typename T>
void printMutantStack(MutantStack<T> &mstack) {
    typename MutantStack<T>::iterator it = mstack.begin();
    typename MutantStack<T>::iterator ite = mstack.end();

    std::cout << "MutantStack: { ";
    for (; it != ite; it++) {
        std::cout << *it;
        if (it + 1 != ite) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

template <class T>
void printTop(T &stack) {
    std::cout << "top  : " << stack.top() << std::endl;
}

template <class T, typename U>
void printPush(T &stack, U value) {
    std::cout << "push   " << value << std::endl;
    stack.push(value);
}

template <class T>
void printSize(T &stack) {
    std::cout << "size : " << stack.size() << std::endl;
}

template <class T>
void printEmpty(T &stack) {
    std::cout << "empty: " << stack.empty() << std::endl;
}

template <typename T>
void printPop(T &stack) {
    std::cout << "pop" << std::endl;
    stack.pop();
}

template <class T>
void testIntStack(T &stack) {
    printEmpty(stack);
    printPush(stack, 5);
    printPush(stack, -100);
    printEmpty(stack);
    printSize(stack);
    printTop(stack);
    printPop(stack);
    printTop(stack);
    std::cout << YELLO << "- asignation operator test -" << RESET << std::endl;
    T copy;
    copy = stack;
    printTop(copy);
    if (copy == stack) {
        std::cout << "copy == stack" << std::endl;
    } else {
        std::cout << "copy != stack" << std::endl;
    }
}
