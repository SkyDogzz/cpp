#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  if (VERBOSE)
    std::cout << "Constructor for ScavTrap " << _name << "(" << this
              << ") called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  if (VERBOSE)
    std::cout << "Copy constructor for ScavTrap " << _name << "(" << this
              << ") called" << std::endl;
  *this = other;
}

ScavTrap::~ScavTrap() {
  if (VERBOSE)
    std::cout << "Destructor for ScavTrap " << _name << "(" << this
              << ") called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  _name = other._name;
  _hitPoints = other._hitPoints;
  _energyPoints = other._energyPoints;
  _attackDamage = other._attackDamage;
  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (_energyPoints == 0) {
    std::cout << "ScavTrap " << _name << "(" << this
              << ") can't attack with 0 energy" << std::endl;
    return;
  } else if (_hitPoints == 0) {
    std::cout << "ScavTrap " << _name << "(" << this
              << ") can't attack while dead" << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ScavTrap " << _name << "(" << this << ") attack " << target
            << " by " << _attackDamage << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << "(" << this << ") is now in guard mode"
            << std::endl;
}
