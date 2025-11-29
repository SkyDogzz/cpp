#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i)
    _learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; i++)
    _learned[i] = other._learned[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    for (int i = 0; i < 4; ++i) {
      delete _learned[i];
      _learned[i] = other._learned[i] ? other._learned[i]->clone() : NULL;
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    delete _learned[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (_learned[i] == NULL) {
      _learned[i] = m->clone();
      return;
    }
  }
  std::cout << "Cant learn more materia" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; i++) {
    if (_learned[i]->getType() == type) {
      return _learned[i]->clone();
    }
  }
  return 0;
}
