#ifndef CURE_HPP
#define CURE_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  ~Cure();

  Cure *clone() const;
  void use(ICharacter &target);
};

#endif
