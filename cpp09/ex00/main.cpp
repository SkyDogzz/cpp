#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  BitcoinExchange exchange;

  try {
    exchange.parseInput(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  (void)argc;
}
