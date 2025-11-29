#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &other) {
  for (unsigned int i = 0; i < BRAIN_SIZE; i++)
    _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
  if (this != &other) {
    for (unsigned int i = 0; i < BRAIN_SIZE; i++)
      _ideas[i] = other._ideas[i];
  }
  return *this;
}

Brain::~Brain() {}
