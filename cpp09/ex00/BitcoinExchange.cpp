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

struct IsSpace {
	bool operator()(char c) const { return std::isspace(static_cast<unsigned char>(c)) != 0; }
};

inline std::string& ltrim(std::string& s) {
	std::string::iterator it = s.begin();
	while (it != s.end() && IsSpace()(*it))
		++it;
	s.erase(s.begin(), it);
	return s;
}

inline std::string& rtrim(std::string& s) {
	if (s.empty())
		return s;

	std::string::iterator it = s.end();
	do {
		--it;
		if (!IsSpace()(*it)) {
			++it;
			s.erase(it, s.end());
			return s;
		}
	} while (it != s.begin());

	// all spaces
	s.clear();
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

		std::string::size_type bar = line.find('|');
		if (bar == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateT = line.substr(0, bar);
		std::string valueT = line.substr(bar + 1);

		trim(dateT);
		trim(valueT);

		float v = static_cast<float>(std::atof(valueT.c_str()));
		if (v < 0) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		} else if (v > 1000) {
			std::cerr << "Error: too loarge number (1000 max)" << std::endl;
			continue;
		}
		std::pair<Date, float> input(Date(dateT), v);
		std::cout << dateT << " => " << v << " = " << findInData(input) << std::endl;
	}
}

const char* BitcoinExchange::CouldntOpenFile::what() const throw() {
	return "couldnt open file";
}
