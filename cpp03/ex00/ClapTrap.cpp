#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : _name(name), _energyPoints(10), _hitPoints(10), _attackDamage(0) {
  if (VERBOSE)
    std::cout << "Constructor for ClapTrap " << _name << "(" << this
              << ") called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _energyPoints(other._energyPoints),
      _hitPoints(other._hitPoints), _attackDamage(other._attackDamage) {
  if (VERBOSE)
    std::cout << "Copy constructor for ClapTrap " << other._name << "(" << this
              << ") called" << std::endl;
}

ClapTrap::~ClapTrap() {
  if (VERBOSE)
    std::cout << "Destructor for ClapTrap " << _name << "(" << this
              << ") called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  if (VERBOSE)
    std::cout << "Assignment operator for ClapTrap " << other._name << "("
              << this << ") called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _energyPoints = other._energyPoints;
    _hitPoints = other._hitPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (_energyPoints == 0) {
    std::cout << "ClapTrap " << _name << "(" << this
              << ") can't attack with 0 energy" << std::endl;
    return;
  } else if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "(" << this
              << ") can't attack while dead" << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << _name << "(" << this << ") attack " << target << " by "
            << _attackDamage << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "(" << this << ") is already dead"
              << std::endl;
    return;
  } else {
    if (_hitPoints <= amount) {
      std::cout << "ClapTrap " << _name << "(" << this << ") took "
                << _hitPoints << " damage" << std::endl;
      _hitPoints = 0;
      std::cout << "ClapTrap " << _name << "(" << this << ") is dead"
                << std::endl;
    } else {
      std::cout << "ClapTrap " << _name << "(" << this << ") took " << amount
                << " damage" << std::endl;
      _hitPoints -= amount;
      std::cout << "ClapTrap " << _name << "(" << this
                << ") now have: " << _hitPoints << "hp" << std::endl;
    }
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0) {
    std::cout << "ClapTrap " << _name << "(" << this
              << ") can't repair himself with 0 energy" << std::endl;
    return;
  } else if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << "(" << this
              << ") can't repair himself while dead" << std::endl;
    return;
  }
  _energyPoints--;
  _hitPoints += amount;
  std::cout << "ClapTrap " << _name << "(" << this << ") repaired himself for "
            << amount << " hp. It now have " << _hitPoints << std::endl;
}
