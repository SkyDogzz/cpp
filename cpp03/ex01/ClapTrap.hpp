#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <iostream>
#include <string>

class ClapTrap {
protected:
  std::string _name;
  unsigned int _energyPoints;
  unsigned int _hitPoints;
  unsigned int _attackDamage;

public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
