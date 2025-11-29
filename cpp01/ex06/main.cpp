#include "Harl.hpp"

#include <cctype>
#include <iostream>
#include <string>

static std::string toUpper(std::string value) {
	for (std::string::size_type i = 0; i < value.size(); ++i) {
		value[i] = static_cast<char>(std::toupper(value[i]));
	}
	return value;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter <log level>" << std::endl;
		return 1;
	}

	static const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string levelInput = toUpper(argv[1]);
	int index = -1;

	for (int i = 0; i < 4; ++i) {
		if (levelInput == levels[i]) {
			index = i;
			break;
		}
	}

	Harl harl;
	switch (index) {
		case 0:
			harl.complain(levels[0]);
			/* fallthrough */
		case 1:
			harl.complain(levels[1]);
			/* fallthrough */
		case 2:
			harl.complain(levels[2]);
			/* fallthrough */
		case 3:
			harl.complain(levels[3]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return 0;
}
