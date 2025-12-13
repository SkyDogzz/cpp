#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span {
private:
  unsigned int _maxStorage;
  unsigned int _actIndex;
  std::vector<int> _storage;

public:
  Span(unsigned int maxStorage);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int number);
  template <typename T> void addNumber(const T &begin, const T &end) {
    for (T it = begin; it != end; ++it) {
      if (_actIndex >= _maxStorage)
        throw SpanFullException();
      _storage.push_back(*it);
      _actIndex++;
    }
  }
  unsigned int shortestSpan(void);
  unsigned int longestSpan(void);

  class SpanFullException : public std::exception {
  public:
    const char *what() const throw();
  };

  class NotEnoughNumbersException : public std::exception {
    const char *what() const throw();
  };
};

#endif
