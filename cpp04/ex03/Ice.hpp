#ifndef ICE_HPP
#define ICE_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  ~Ice();

  Ice *clone() const;
  void use(ICharacter &target);
};

#endif
