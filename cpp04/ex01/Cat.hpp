#ifndef CAT_HPP
#define CAT_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *_brain;

public:
  Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  ~Cat();

  void makeSound(void) const;
};

#endif
