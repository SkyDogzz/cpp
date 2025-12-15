#include "BitcoinExchange.hpp"

#include <fstream>
#include <utility>

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

inline std::string& ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::ptr_fun<int, int>(std::isspace)));
	return s;
}

inline std::string& rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::ptr_fun<int, int>(std::isspace)).base(), s.end());
	return s;
}

inline std::string& trim(std::string& s) {
	return ltrim(rtrim(s));
}

float BitcoinExchange::findInData(std::pair<Date, float> input) {
	float								 value = 0;
	std::multimap<Date, float>::iterator it = _data.begin();
	while (it != _data.end() && it->first < input.first)
		it++;
	value = input.second * it->second;
	std::cout << input.second << "." << it->second << std::endl;
	std::cout << value << std::endl;
	return value;
}

void BitcoinExchange::parseInput(const char* filename) {
	std::ifstream infile(filename);
	if (!infile.is_open())
		throw BitcoinExchange::CouldntOpenFile();

	std::string line;
	while (std::getline(infile, line)) {
		if (line == "date | value")
			continue;
		char*				   date = strtok(const_cast<char*>(line.data()), "|");
		char*				   value = strtok(NULL, ",");
		std::string			   dateT = date;
		std::string			   valueT = value;
		std::pair<Date, float> input = std::make_pair(Date(dateT), atof(valueT.data()));
		std::cout << "|" << dateT << "|" << valueT << "|" << findInData(input) << std::endl;
	}
}

const char* BitcoinExchange::CouldntOpenFile::what() const throw() {
	return "couldnt open file";
}
