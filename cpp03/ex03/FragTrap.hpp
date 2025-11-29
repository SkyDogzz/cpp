#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
private:
public:
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &other);

  void highFivesGuys(void);
};

#endif
