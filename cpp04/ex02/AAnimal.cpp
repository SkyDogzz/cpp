#include "AAnimal.hpp"

AAnimal::AAnimal() {}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

AAnimal::~AAnimal() {}

const std::string &AAnimal::getType(void) const { return _type; }

void AAnimal::makeSound(void) const {
  std::cout << "Generic sound goes brrrr" << std::endl;
}
