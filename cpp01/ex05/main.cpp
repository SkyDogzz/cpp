#include "Harl.hpp"

#include <cstddef>
#include <iostream>
#include <string>

static void runFullTestSuite() {
	const std::string tests[] = {"DEBUG", "Info", "warning", "ERROR", "unknown"};
	Harl harl;

	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
		std::cout << "\n>>> Complaining at level: " << tests[i] << std::endl;
		harl.complain(tests[i]);
	}
}

int main() {
	std::cout << "=== Harl 2.0 complaint suite ===" << std::endl;
	runFullTestSuite();
	std::cout << "\nAll complaints issued." << std::endl;
	return 0;
}
