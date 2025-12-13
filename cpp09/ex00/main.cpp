#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  BitcoinExchange exchange;

  try {
    exchange.parseInput(argv[1]);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Date date = Date("2113-12-12");
    Date date2 = Date("2112-12-12");

    std::cout << (date > date2) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  (void)argc;
}
