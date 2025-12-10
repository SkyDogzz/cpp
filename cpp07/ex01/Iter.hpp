#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T array[], const unsigned int &size, void (&f)(T &x)) {
  for (unsigned int i = 0; i < size; i++)
    f(array[i]);
}

template <typename T>
void iter(T *array, std::size_t const length, void (*f)(T &)) {
  if (!array || !f)
    return;
  for (std::size_t i = 0; i < length; ++i)
    f(array[i]);
}

template <typename T>
void iter(T const *array, std::size_t const length, void (*f)(T const &)) {
  if (!array || !f)
    return;
  for (std::size_t i = 0; i < length; ++i)
    f(array[i]);
}

#endif
