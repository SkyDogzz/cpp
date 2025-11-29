#include "WrongCat.hpp"

WrongCat::WrongCat() {}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  _type = other._type;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

WrongCat::~WrongCat() {}
