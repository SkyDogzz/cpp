#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),
      _name(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 30;
  if (VERBOSE)
    std::cout << "Constructor for DiamondTrap " << _name << "(" << this
              << ") called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
  if (VERBOSE)
    std::cout << "Copy constructor for DiamondTrap " << _name << "(" << this
              << ") called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  if (VERBOSE)
    std::cout << "Destructor for DiamondTrap " << _name << "(" << this
              << ") called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (VERBOSE)
    std::cout << "Assignment operator for DiamondTrap " << other._name << "("
              << this << ") called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap name: " << _name
            << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
