#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string name) : _name(name) {
  for (int i = 0; i < INVENTORY_SIZE; i++)
    _inventory[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name) {
  std::cout << "Copy constructor character called" << std::endl;
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (other._inventory[i])
      _inventory[i] = other._inventory[i]->clone();
    else
      _inventory[i] = NULL;
  }
}

Character &Character::operator=(const Character &other) {
  std::cout << "Asignement operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    // delete current inventory first
    for (int i = 0; i < INVENTORY_SIZE; i++) {
      delete _inventory[i];
      if (other._inventory[i])
        _inventory[i] = other._inventory[i]->clone();
      else
        _inventory[i] = NULL;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    delete _inventory[i];
  }
}

std::string const &Character::getName(void) const { return _name; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < INVENTORY_SIZE; i++) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      return;
    }
  }
  std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= INVENTORY_SIZE) {
    return;
  }
  _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < INVENTORY_SIZE) {
    if (_inventory[idx] == NULL) {
      std::cout << "Inventory " << idx << " empty" << std::endl;
    } else {
      _inventory[idx]->use(target);
    }
  } else
    std::cout << "Invalid invetory id" << std::endl;
}
