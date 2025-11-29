#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
  std::string _name;

public:
  DiamondTrap(const std::string name);
  DiamondTrap(const DiamondTrap &other);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &other);

  void attack(const std::string &target) { ScavTrap::attack(target); }

  void beRepaired(unsigned int amount) { ClapTrap::beRepaired(amount); }

  void whoAmI(void);
};

#endif
