#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int maxStorage) : _maxStorage(maxStorage), _actIndex(0) {}

Span::Span(const Span &other) {
  _maxStorage = other._maxStorage;
  for (unsigned int i = 0; i < other._actIndex; i++)
    _storage.push_back(other._storage[i]);
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _maxStorage = other._maxStorage;
    _actIndex = 0;
    for (unsigned int i = 0; i < other._actIndex; i++)
      _storage[i] = other._storage[i];
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (_actIndex >= _maxStorage) {
    throw Span::SpanFullException();
  }
  _storage.push_back(number);
  _actIndex++;
}

unsigned int Span::shortestSpan(void) {
  if (_actIndex <= 1)
    throw Span::NotEnoughNumbersException();
  std::sort(_storage.begin(), _storage.end());
  int min = INT_MAX;
  for (unsigned int i = 0; i < _actIndex - 1; i++)
    if (static_cast<long>(_storage[i + 1]) - static_cast<long>(_storage[i]) <
        static_cast<long>(min))
      min = _storage[i + 1] - _storage[i];
  return min;
}

unsigned int Span::longestSpan(void) {
  if (_actIndex <= 1)
    throw Span::NotEnoughNumbersException();
  std::sort(_storage.begin(), _storage.end());
  return static_cast<int>(static_cast<long>(_storage[_actIndex - 1] -
                                            static_cast<long>(_storage[0])));
}

const char *Span::SpanFullException::what() const throw() {
  return "Span already full exception";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
  return "Span only contains 0 or 1 number";
}
