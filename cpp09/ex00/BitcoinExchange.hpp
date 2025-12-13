#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include "Date.hpp"
#include <bits/stdc++.h>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>

class BitcoinExchange {
private:
  std::multimap<Date, float> _data;
  std::multimap<Date, float> _input;

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

  class BadInput : public std::exception {
  public:
    const char *what() const throw();
  };
};

#endif
