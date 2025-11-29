#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  ~WrongCat();

  void makeSound(void) const;
};

#endif
