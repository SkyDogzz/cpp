#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "===== Correct Polymorphism =====" << std::endl;
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << std::endl;
  std::cout << i->getType() << std::endl;

  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  std::cout << "\n===== Wrong Polymorphism =====" << std::endl;
  const WrongAnimal *wrong = new WrongAnimal();
  const WrongAnimal *wc = new WrongCat();

  wrong->makeSound();
  wc->makeSound();

  delete wrong;
  delete wc;
  return 0;
}
