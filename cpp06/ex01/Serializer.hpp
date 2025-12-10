
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#define uintptr_t int *

struct Data {
  int id;
  std::string name;
  double value;
};

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(Serializer const &);
  Serializer &operator=(Serializer const &);
  ~Serializer();
};

#endif
