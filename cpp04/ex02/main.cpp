#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define ANIMAL_NUMBERS 11

int main() {
  std::cout << "===== Creating Dogs and Cats =====" << std::endl;
  const AAnimal *j = new Dog();
  const AAnimal *i = new Cat();

  delete j;
  delete i;

  std::cout << "\n===== Array of Animals =====" << std::endl;
  AAnimal *animals[ANIMAL_NUMBERS];
  for (int k = 0; k < ANIMAL_NUMBERS / 2; k++)
    animals[k] = new Dog();
  for (int k = ANIMAL_NUMBERS / 2; k < ANIMAL_NUMBERS; k++)
    animals[k] = new Cat();

  for (int k = 0; k < ANIMAL_NUMBERS; k++) {
    std::cout << animals[k]->getType() << " says: ";
    animals[k]->makeSound();
  }

  for (int k = 0; k < ANIMAL_NUMBERS; k++)
    delete animals[k];

  std::cout << "\n===== Deep Copy Test =====" << std::endl;
  Dog basic;
  {
    Dog tmp = basic;
  }

  return 0;
}
