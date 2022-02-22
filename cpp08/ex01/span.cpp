#include "span.hpp"

#include <algorithm>
#include <iostream>

Span::Span(unsigned int N) : maxStorageSize_(N) {}

Span::~Span() {}

Span::Span(Span const &other) { *this = other; }

Span &Span::operator=(Span const &other) {
    if (this != &other) {
        maxStorageSize_ = other.maxStorageSize_;
        storage_ = other.storage_;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (storage_.size() == maxStorageSize_) {
        throw CannotAdd();
    }
    storage_.push_back(n);
    std::sort(storage_.begin(), storage_.end());
}

void Span::addNumber(std::vector<int>::iterator first,
                     std::vector<int>::iterator last) {
    if (std::distance(first, last) + storage_.size() > maxStorageSize_) {
        throw CannotAdd();
    }
    std::copy(first, last, std::back_inserter(storage_));
    std::sort(storage_.begin(), storage_.end());
}

unsigned int Span::shortestSpan() const {
    if (storage_.size() <= 1) {
        throw CannotSpan();
    }
	const std::vector<int> &sorted = storage_;
    unsigned int shortest_span = UINT_MAX;
    for (unsigned int i = 0; i + 1 < sorted.size(); i++) {
        int now = sorted[i];
        int next = sorted[i + 1];
        unsigned int latest_span = static_cast<unsigned int>(next - now);
        if (latest_span < shortest_span) {
            shortest_span = latest_span;
        }
    }
    return shortest_span;
}

unsigned int Span::longestSpan() const {
    if (storage_.size() <= 1) {
        throw CannotSpan();
    }
    unsigned int span = storage_.back() - storage_.front();
    return span;
}

void Span::printStorageValues() const {
    std::cout << "{ ";
    for (unsigned int i = 0; i < storage_.size(); i++) {
        std::cout << storage_[i];
        if (i != storage_.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}

unsigned int Span::getMaxStorageSize() const { return maxStorageSize_; }

unsigned int Span::getStorageSize() const { return storage_.size(); }

// exeption class
Span::CannotAdd::CannotAdd(std::string const &msg) : std::runtime_error(msg) {}

Span::CannotSpan::CannotSpan(std::string const &msg)
    : std::runtime_error(msg) {}
