#include <cstdlib>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Error couldnt open file" << std::endl;
		return EXIT_FAILURE;
	}
	BitcoinExchange exchanger;
	exchanger.parseData();

	// Date data = exchanger._data.begin()->first;

	// std::multimap<Date, float>::iterator it = exchanger._data.begin();
	// while (it != exchanger._data.end()) {
	//	std::cout << it->first << " " << it->second << std::endl;
	//	it++;
	// }

	try {
		exchanger.parseInput(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
