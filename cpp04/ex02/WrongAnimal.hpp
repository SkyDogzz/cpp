#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <iostream>
#include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  ~WrongAnimal();
  WrongAnimal &operator=(const WrongAnimal &other);

protected:
  std::string _type;

public:
  const std::string &getType(void) const;
  void makeSound(void) const;
};

#endif
