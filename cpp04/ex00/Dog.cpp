#include "Dog.hpp"

Dog::Dog() { _type = "Dog"; }

Dog::Dog(const Dog &other) : Animal(other) { _type = other._type; }

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Dog::~Dog() {}

void Dog::makeSound(void) const {
  std::cout << "Dog sound (we preffer cats)" << std::endl;
}
