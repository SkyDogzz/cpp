#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <iostream>
#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal &other);
  virtual ~Animal();
  Animal &operator=(const Animal &other);

protected:
  std::string _type;

public:
  const std::string &getType(void) const;
  virtual void makeSound(void) const;
};

#endif
