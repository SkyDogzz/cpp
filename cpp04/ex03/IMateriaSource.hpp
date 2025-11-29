#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "AMateria.hpp"

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
