#include "span.hpp"

#include <algorithm>
#include <iostream>

span::span(unsigned int N) : maxStrageSize_(N) {}

span::~span() {}

span::span(span const &other) { *this = other; }

span &span::operator=(span const &other) {
    if (this != &other) {
        maxStrageSize_ = other.maxStrageSize_;
        strage_ = other.strage_;
    }
    return *this;
}

void span::addNumber(int n) {
    if (strage_.size() == maxStrageSize_) {
        throw CannotAdd();
    }
    strage_.push_back(n);
    std::sort(strage_.begin(), strage_.end());
}

void span::addNumber(std::vector<int>::iterator first,
                     std::vector<int>::iterator last) {
    std::copy(first, last, std::back_inserter(strage_));
    std::sort(strage_.begin(), strage_.end());
}

unsigned int span::shortestSpan() const {
    if (strage_.size() <= 1) {
        throw CannotSpan();
    }
    unsigned int span = strage_[1] - strage_[0];
    for (unsigned int i = 1; i < strage_.size(); i++) {
        if (static_cast<unsigned int>(strage_[i] - strage_[i - 1]) < span) {
            span = strage_[i] - strage_[i - 1];
        }
    }
    return span;
}

unsigned int span::longestSpan() const {
    if (strage_.size() <= 1) {
        throw CannotSpan();
    }
    unsigned int span = strage_.back() - strage_.front();
    return span;
}

void span::printStrageValues() const {
    std::cout << "{ ";
    for (unsigned int i = 0; i < strage_.size(); i++) {
        std::cout << strage_[i];
        if (i != strage_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

unsigned int span::getMaxStrageSize() const { return maxStrageSize_; }

unsigned int span::getStrageSize() const { return strage_.size(); }

// exeption class
span::CannotAdd::CannotAdd(std::string const &msg) : std::runtime_error(msg) {}

span::CannotSpan::CannotSpan(std::string const &msg)
    : std::runtime_error(msg) {}
