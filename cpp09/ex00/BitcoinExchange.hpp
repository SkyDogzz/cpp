#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <bits/stdc++.h>

#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

#include "Date.hpp"

class BitcoinExchange {
public:
	std::multimap<Date, float> _data;
	std::multimap<Date, float> _input;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void  parseData(void);
	void  parseInput(const char* filename);
	float findInData(std::pair<Date, float> input);
	class CouldntOpenFile : public std::exception {
		const char* what() const throw();
	};
};

#endif
