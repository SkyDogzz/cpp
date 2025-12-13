#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  std::cout << "===== SPAN TESTS =====" << std::endl;

  try {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest : " << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << "\n--- BIG TEST (10,000 numbers) ---" << std::endl;

  try {
    int numbers = 10000;
    Span big(numbers);
    std::vector<int> values;

    std::srand(std::time(NULL));
    for (int i = 0; i < numbers; ++i)
      values.push_back(std::rand());

    big.addNumber(values.begin(), values.end());

    std::cout << "Shortest: " << big.shortestSpan() << std::endl;
    std::cout << "Longest : " << big.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cout << "Big test error: " << e.what() << std::endl;
  }

  std::cout << "\n--- Exception tests ---" << std::endl;

  try {
    Span fail(1);
    fail.addNumber(42);
    fail.addNumber(21);
  } catch (std::exception &e) {
    std::cout << "Expected overflow: " << e.what() << std::endl;
  }

  try {
    Span empty(2);
    empty.shortestSpan();
  } catch (std::exception &e) {
    std::cout << "Expected span error: " << e.what() << std::endl;
  }

  return 0;
}
