#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#ifndef VERBOSE
#define VERBOSE 1
#endif

#define INVENTORY_SIZE 4

class AMateria;
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[INVENTORY_SIZE];

public:
  Character(const std::string name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  ~Character();

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
