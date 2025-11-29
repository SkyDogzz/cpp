#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound(void) const {
  std::cout << "Wrong animal base sound" << std::endl;
}
