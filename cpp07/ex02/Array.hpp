#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T> class Array {
private:
  T *_elem;
  size_t _size;

public:
  Array() : _elem(NULL), _size(0) {}

  Array(size_t n) : _elem(new T[n]), _size(n) {}

  Array(const Array &other) : _elem(NULL), _size(0) {
    if (other._size > 0) {
      _elem = new T[other._size];
      _size = other._size;
      for (size_t i = 0; i < _size; ++i) {
        _elem[i] = other._elem[i];
      }
    }
  }

  ~Array() { delete[] _elem; }

  Array &operator=(const Array &other) {
    if (this != &other) {
      delete[] _elem;

      _elem = NULL;
      _size = 0;

      if (other._size > 0) {
        _elem = new T[other._size];
        _size = other._size;
        for (size_t i = 0; i < _size; ++i) {
          _elem[i] = other._elem[i];
        }
      }
    }
    return *this;
  }

  T &operator[](size_t i) {
    if (i >= _size)
      throw std::out_of_range("Array index out of range");
    return _elem[i];
  }

  const T &operator[](size_t i) const {
    if (i >= _size)
      throw std::out_of_range("Array index out of range");
    return _elem[i];
  }

  size_t size() const { return _size; }
};

#endif
