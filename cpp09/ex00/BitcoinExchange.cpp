#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseInput(const char *filename) {
  if (!filename) {
    throw BitcoinExchange::CouldntOpenFileException();
  }
}

const char *BitcoinExchange::CouldntOpenFileException::what() const throw() {
  return "Could not open file.";
}
