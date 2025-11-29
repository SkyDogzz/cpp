#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal &other) : _type(other._type) {}

Animal &Animal::operator=(const Animal &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Animal::~Animal() {}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "Generic sound goes brrrr" << std::endl;
}
