#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string &s) {
  size_t b = s.find_first_not_of(" \t");
  if (b == std::string::npos)
    return "";
  size_t e = s.find_last_not_of(" \t");
  return s.substr(b, e - b + 1);
}

static bool isValidDate(const std::string &s) {
  try {
    Date tmp(s);
  } catch (...) {
    return false;
  }
  return true;
}

void BitcoinExchange::parseData(void) {
  std::ifstream input("data.csv");
  if (!input.is_open())
    throw BitcoinExchange::CouldntOpenFileException();

  std::string line;
  while (std::getline(input, line)) {
    size_t comma = line.find(',');
    if (comma == std::string::npos)
      continue;

    std::string left = trim(line.substr(0, comma));
    std::string right = trim(line.substr(comma + 1));

    if (!isValidDate(left))
      continue;

    char *end = 0;
    double val = std::strtod(right.c_str(), &end);
    if (end == right.c_str() || *end != '\0')
      continue;

    _data.insert(std::make_pair(Date(left), static_cast<float>(val)));
  }
}

void BitcoinExchange::parseInput(const char *filename) {
  if (!filename)
    throw BitcoinExchange::CouldntOpenFileException();

  std::ifstream input(filename);
  if (!input.is_open())
    throw BitcoinExchange::CouldntOpenFileException();

  std::string line;

  while (std::getline(input, line)) {
    if (line.empty())
      continue;

    size_t pipe = line.find('|');
    if (pipe == std::string::npos ||
        line.find('|', pipe + 1) != std::string::npos)
      std::cerr << "Error: bad input => " << line << std::endl;

    std::string left = trim(line.substr(0, pipe));
    std::string right = trim(line.substr(pipe + 1));

    if (left.empty() || right.empty())
      std::cerr << "Bad input " << std::endl;

    Date date(left);

    char *end = 0;
    double val = std::strtod(right.c_str(), &end);
    if (end == right.c_str() || *end != '\0')
      std::cerr << "Bad input " << std::endl;

    float amount = static_cast<float>(val);
    _input.insert(std::make_pair(date, amount));
  }
}

const char *BitcoinExchange::CouldntOpenFileException::what() const throw() {
  return "Could not open file.";
}

const char *BitcoinExchange::BadInput::what() const throw() {
  return "Bad input";
}
