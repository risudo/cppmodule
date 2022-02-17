#include <iostream>
#include <stack>
#include <string>

#include "mutantstack.hpp"
#include "testMutantstack.hpp"

#define GREEN "\033[32m"
#define CIAN "\033[36m"
#define RED "\033[31m"
#define RESET "\033[39m"

void simpleTest() {
    std::cout << GREEN << "--- simpleTest ---" << RESET << std::endl;
    MutantStack<int> mstack;
    printPush(mstack, 5);
    printPush(mstack, 17);
    printPush(mstack, -1);
    printMutantStack(mstack);
    printSize(mstack);
    printTop(mstack);
    printPop(mstack);
    printMutantStack(mstack);
    printSize(mstack);
}

// test method as stack
void testStack() {
    std::cout << GREEN << "\n--- testStack ---" << RESET << std::endl;
    std::stack<int> intstack;
    MutantStack<int> intmstack;

    std::cout << CIAN << "-- stack --" << RESET << std::endl;
    testIntStack(intstack);
    std::cout << CIAN << "-- mutant stack --" << RESET << std::endl;
    testIntStack(intmstack);
}

void testIterator() {
    std::cout << GREEN << "\n--- testIterator ---" << RESET << std::endl;
    MutantStack<std::string> mstack;
    mstack.push("hoge");
    mstack.push("aaaa");
    mstack.push("bb");
    printMutantStack(mstack);

    MutantStack<std::string>::iterator it = mstack.begin();
    MutantStack<std::string>::iterator ite = mstack.end();
    testMoveIterator(it, ite);

    std::cout << CIAN << "-- assignation test --" << RESET << std::endl;
    std::cout << "*it : " << *it << std::endl;
    *it = "after asigning";
    std::cout << "*it : " << *it << std::endl;
}

void testReverseIterator() {
    std::cout << GREEN << "\n---  testReverseIterator ---" << RESET
              << std::endl;
    MutantStack<int> mstack;
    mstack.push(3);
    mstack.push(-100);
    mstack.push(20);
    printMutantStack(mstack);

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    testMoveIterator(rit, rite);

    std::cout << CIAN << "-- assignation test --" << RESET << std::endl;
    std::cout << "*rit : " << *rit << std::endl;
    *rit = 9999;
    std::cout << "*rit : " << *rit << std::endl;
}

void testConstIterator() {
    std::cout << GREEN << "\n---  testConstIterator ---" << RESET << std::endl;
    MutantStack<double> mstack;
    mstack.push(1.2);
    mstack.push(0.1);
    mstack.push(-0.5);
    printMutantStack(mstack);

    MutantStack<double>::const_iterator cit = mstack.begin();
    MutantStack<double>::const_iterator cite = mstack.end();
    testMoveIterator(cit, cite);
    // *cit = 0.33; //cannot asign
}

void testConstReverseIterator() {
    std::cout << GREEN << "\n--- testConstReverseIterator ---" << RESET
              << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(100);
    mstack.push(1000);
    printMutantStack(mstack);

    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    testMoveIterator(crit, crite);
    // *crit = 0.33; //cannot asign
}

int main() {
    simpleTest();
    testStack();
    testIterator();
    testReverseIterator();
    testConstIterator();
    return 0;
}
