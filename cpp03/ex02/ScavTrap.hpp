#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
public:
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &other);

  void attack(const std::string &target);
  void guardGate();
};

#endif
