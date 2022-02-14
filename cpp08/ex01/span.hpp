#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class Span {
public:
    Span(unsigned int N = 0);
    ~Span();
    Span(Span const &other);
    Span &operator=(Span const &other);
    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin,
                   std::vector<int>::iterator last);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    void printStrageValues() const;
    unsigned int getMaxStrageSize() const;
    unsigned int getStrageSize() const;

private:
    unsigned int maxStrageSize_;
    std::vector<int> strage_;

    class CannotAdd : public std::runtime_error {
    public:
        CannotAdd(std::string const &msg = "cannot add");
    };
    class CannotSpan : public std::runtime_error {
    public:
        CannotSpan(std::string const &msg = "cannot span");
    };
};

#endif  // SPAN_HPP
