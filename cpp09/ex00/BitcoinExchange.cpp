#include "BitcoinExchange.hpp"

#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	return *this;
	(void)other;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseData(void) {
	std::ifstream infile("data.csv");
	if (!infile.is_open())
		return;

	std::string line;
	while (std::getline(infile, line)) {
		if (line == "date,exchange_rate")
			continue;
		char* date = strtok(const_cast<char*>(line.data()), ",");
		char* value = strtok(NULL, ",");
		_data.insert(std::make_pair(Date(date), atof(value)));
	}
}
