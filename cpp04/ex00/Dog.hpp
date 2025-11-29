#ifndef DOG_HPP
#define DOG_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  ~Dog();

  void makeSound(void) const;
};

#endif
