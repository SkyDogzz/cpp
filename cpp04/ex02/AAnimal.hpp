#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <iostream>
#include <string>

class AAnimal {
public:
  AAnimal();
  AAnimal(const AAnimal &other);
  virtual ~AAnimal() = 0;
  AAnimal &operator=(const AAnimal &other);

protected:
  std::string _type;

public:
  const std::string &getType(void) const;
  virtual void makeSound(void) const;
};

#endif
