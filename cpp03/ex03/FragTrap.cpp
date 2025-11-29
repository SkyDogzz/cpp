#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  if (VERBOSE)
    std::cout << "Constructor for FragTrap " << _name << "(" << this
              << ") called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  if (VERBOSE)
    std::cout << "Copy constructor for FragTrap " << _name << "(" << this
              << ") called" << std::endl;
  *this = other;
}

FragTrap::~FragTrap() {
  if (VERBOSE)
    std::cout << "Destructor for FragTrap " << _name << "(" << this
              << ") called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << "(" << this
            << ") iniated a high five. Will anyone respond ?" << std::endl;
}
