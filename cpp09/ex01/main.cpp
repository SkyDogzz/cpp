#include <cstdlib>

#include "RPN.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " expression" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		RPN expr(argv[1]);

		int result = expr.resolve();
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
