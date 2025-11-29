#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() { _type = "Cat"; }

Cat::Cat(const Cat &other) : Animal(other) { _type = other._type; }

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Cat::~Cat() {}

void Cat::makeSound(void) const { std::cout << "Meowww" << std::endl; }
