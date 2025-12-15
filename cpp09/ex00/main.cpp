#include "BitcoinExchange.hpp"

int main(void) {
	BitcoinExchange exchanger;
	exchanger.parseData();

	Date data = exchanger._data.begin()->first;

	std::multimap<Date, float>::iterator it = exchanger._data.begin();
	while (it != exchanger._data.end()) {
		std::cout << it->first << " " << it->second << std::endl;
		it++;
	}
}
