#include "span.hpp"

#include <algorithm>
#include <iostream>

span::span(unsigned int N) : size_(N) {}

span::~span() {}

span::span(span const &other) { *this = other; }

span &span::operator=(span const &other) {
    if (this != &other) {
    }
    return *this;
}

void span::addNumber(int n) {
    if (values_.size() == size_) {
        throw CannotAdd();
    }
    values_.push_back(n);
    //ソート？
    std::sort(values_.begin(), values_.end());
}

int span::shotestSpan() const {
    if (values_.size() <= 1) {
        throw CannotSpan();
    }
    unsigned int span = values_[1] - values_[0];
    for (unsigned int i = 1; i < values_.size(); i++) {
        if (static_cast<unsigned int>(values_[i] - values_[i - 1]) < span) {
            span = values_[i] - values_[i - 1];
        }
    }
    return span;
}

int span::longestSpan() const {
    if (values_.size() <= 1) {
        throw CannotSpan();
    }
    unsigned int span = values_.back() - values_.front();
    return span;
}

void span::printValue() const {
    for (std::size_t i = 0; i < values_.size(); i++) {
        std::cout << "value[" << i << "]: " << values_[i] << std::endl;
    }
}

// define exeption class
span::CannotAdd::CannotAdd(std::string const &msg) : std::runtime_error(msg) {}

span::CannotSpan::CannotSpan(std::string const &msg)
    : std::runtime_error(msg) {}
