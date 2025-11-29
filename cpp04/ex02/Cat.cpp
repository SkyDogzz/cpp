#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
  _type = "Cat";
  _brain = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other) {
  _type = other._type;
  _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other) {
  if (this != &other) {
    _type = other._type;
    delete _brain;
    _brain = new Brain(*other._brain);
  }
  return *this;
}

Cat::~Cat() { delete _brain; }

void Cat::makeSound(void) const { std::cout << "Meowww" << std::endl; }
