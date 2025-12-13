#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include "Date.hpp"
#include <bits/stdc++.h>
#include <exception>
#include <iostream>

class BitcoinExchange {
private:
  std::multiset<std::string, double> _data;
  std::multiset<std::string, double> _input;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void parseInput(const char *filename);

  class CouldntOpenFileException : public std::exception {
  public:
    const char *what() const throw();
  };
};

#endif
