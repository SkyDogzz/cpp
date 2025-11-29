#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() {
  _type = "Dog";
  _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
  _type = other._type;
  _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
  if (this != &other) {
    _type = other._type;
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  return *this;
}

Dog::~Dog() { delete _brain; }

void Dog::makeSound(void) const {
  std::cout << "Dog sound (we preffer cats)" << std::endl;
}
