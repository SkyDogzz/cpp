#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <iostream>
#include <string>

enum LiteralType {
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_PSEUDO_FLOAT,
  TYPE_PSEUDO_DOUBLE,
  TYPE_INVALID
};

class ScalarConverter {
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  static void convert(std::string const &literal);
};

#endif
