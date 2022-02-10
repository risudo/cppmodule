#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <string>
#include <vector>

class span {
public:
    span(unsigned int N = 0);
    ~span();
    span(span const &other);
    span &operator=(span const &other);
    void addNumber(int n);
	template<class Iterater>
	void addNumber(Iterater begin, Iterater end);//
    int shotestSpan() const;
    int longestSpan() const;
	void printValue() const;

private:
    unsigned int size_;
    std::vector<int> values_;

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
