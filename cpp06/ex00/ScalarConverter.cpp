#include "ScalarConverter.hpp"

#include <cctype>  // isdigit, isprint
#include <cstdlib> // strtod, strtol
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other) {
    // Nothing to copy, class has no state
  }
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

// ---------- Helpers ----------

static bool isPseudoFloat(const std::string &s) {
  return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool isPseudoDouble(const std::string &s) {
  return (s == "nan" || s == "+inf" || s == "-inf");
}

static LiteralType detectType(const std::string &literal) {
  if (literal.empty())
    return TYPE_INVALID;

  // Pseudo-literals first
  if (isPseudoFloat(literal))
    return TYPE_PSEUDO_FLOAT;
  if (isPseudoDouble(literal))
    return TYPE_PSEUDO_DOUBLE;

  // Single character literal (char vs int)
  if (literal.length() == 1) {
    char c = literal[0];
    if (!std::isdigit(static_cast<unsigned char>(c)))
      return TYPE_CHAR; // 'a', '?', ...
    else
      return TYPE_INT; // "0", "4", ...
  }

  // Numeric forms
  std::size_t i = 0;
  bool hasDot = false;
  bool hasF = false;
  bool hasDigit = false;

  // Optional sign
  if (literal[i] == '+' || literal[i] == '-')
    ++i;

  for (; i < literal.length(); ++i) {
    char c = literal[i];

    if (std::isdigit(static_cast<unsigned char>(c))) {
      hasDigit = true;
    } else if (c == '.' && !hasDot && !hasF) {
      hasDot = true;
    } else if (c == 'f' && i == literal.length() - 1 && !hasF) {
      hasF = true;
    } else {
      return TYPE_INVALID;
    }
  }

  if (!hasDigit)
    return TYPE_INVALID;

  if (hasF)
    return TYPE_FLOAT;
  if (hasDot)
    return TYPE_DOUBLE;
  return TYPE_INT;
}

static void printChar(double d, LiteralType type) {
  std::cout << "char: ";
  if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE) {
    std::cout << "impossible" << std::endl;
    return;
  }

  if (d < 0.0 || d > 127.0 || d != d /* NaN */
      || d == std::numeric_limits<double>::infinity() ||
      d == -std::numeric_limits<double>::infinity()) {
    std::cout << "impossible" << std::endl;
    return;
  }

  char c = static_cast<char>(d);
  if (!std::isprint(static_cast<unsigned char>(c))) {
    std::cout << "Non displayable" << std::endl;
    return;
  }
  std::cout << "'" << c << "'" << std::endl;
}

static void printInt(double d, LiteralType type) {
  std::cout << "int: ";
  if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE) {
    std::cout << "impossible" << std::endl;
    return;
  }

  if (d != d /* NaN */
      || d == std::numeric_limits<double>::infinity() ||
      d == -std::numeric_limits<double>::infinity() ||
      d < static_cast<double>(std::numeric_limits<int>::min()) ||
      d > static_cast<double>(std::numeric_limits<int>::max())) {
    std::cout << "impossible" << std::endl;
    return;
  }

  int i = static_cast<int>(d);
  std::cout << i << std::endl;
}

static void printFloat(double d, LiteralType type, const std::string &lit) {
  std::cout << "float: ";

  if (type == TYPE_PSEUDO_FLOAT) {
    if (lit == "nanf")
      std::cout << "nanf" << std::endl;
    else if (lit == "+inff")
      std::cout << "+inff" << std::endl;
    else if (lit == "-inff")
      std::cout << "-inff" << std::endl;
    return;
  }
  if (type == TYPE_PSEUDO_DOUBLE) {
    if (lit == "nan")
      std::cout << "nanf" << std::endl;
    else if (lit == "+inf")
      std::cout << "+inff" << std::endl;
    else if (lit == "-inf")
      std::cout << "-inff" << std::endl;
    return;
  }

  float f = static_cast<float>(d);
  std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d, LiteralType type, const std::string &lit) {
  std::cout << "double: ";

  if (type == TYPE_PSEUDO_FLOAT) {
    if (lit == "nanf")
      std::cout << "nan" << std::endl;
    else if (lit == "+inff")
      std::cout << "+inf" << std::endl;
    else if (lit == "-inff")
      std::cout << "-inf" << std::endl;
    return;
  }
  if (type == TYPE_PSEUDO_DOUBLE) {
    if (lit == "nan" || lit == "+inf" || lit == "-inf") {
      std::cout << lit << std::endl;
      return;
    }
  }

  std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
  LiteralType type = detectType(literal);

  if (type == TYPE_INVALID) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  double d = 0.0;

  if (type == TYPE_CHAR) {
    char c = literal[0];
    d = static_cast<double>(c);
  } else if (type == TYPE_INT) {
    char *end = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    d = static_cast<double>(val);
  } else if (type == TYPE_FLOAT || type == TYPE_DOUBLE) {
    char *end = 0;
    d = std::strtod(literal.c_str(), &end);
  } else if (type == TYPE_PSEUDO_FLOAT || type == TYPE_PSEUDO_DOUBLE) {
    if (literal[0] == '-') {
      d = -std::numeric_limits<double>::infinity();
    } else if (literal[0] == '+') {
      d = std::numeric_limits<double>::infinity();
    } else { // nan / nanf
      d = std::numeric_limits<double>::quiet_NaN();
    }
  }

  printChar(d, type);
  printInt(d, type);
  printFloat(d, type, literal);
  printDouble(d, type, literal);
}
