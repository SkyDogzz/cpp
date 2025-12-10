#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
  std::cout << "=== Test 1: Default constructor (empty array) ===" << std::endl;
  Array<int> empty;
  std::cout << "empty.size() = " << empty.size() << std::endl;
  try {
    std::cout << "Trying to access empty[0]..." << std::endl;
    std::cout << empty[0] << std::endl; // should throw
  } catch (const std::exception &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== Test 2: Array of int with size n ===" << std::endl;
  unsigned int n = 5;
  Array<int> numbers(n);
  std::cout << "numbers.size() = " << numbers.size() << std::endl;

  std::cout << "Filling numbers..." << std::endl;
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    numbers[i] = static_cast<int>(i * 10);
  }

  std::cout << "numbers content: ";
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "\n=== Test 3: Copy constructor (deep copy) ===" << std::endl;
  Array<int> copy(numbers);
  std::cout << "Modifying copy[0]..." << std::endl;
  copy[0] = 999;

  std::cout << "Original numbers: ";
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Copy numbers:     ";
  for (unsigned int i = 0; i < copy.size(); ++i) {
    std::cout << copy[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "\n=== Test 4: Assignment operator (deep copy) ===" << std::endl;
  Array<std::string> strings(3);
  strings[0] = "Hello";
  strings[1] = "Array";
  strings[2] = "World";

  Array<std::string> other;
  std::cout << "Before assignment, other.size() = " << other.size()
            << std::endl;
  other = strings;
  std::cout << "After assignment, other.size() = " << other.size() << std::endl;

  std::cout << "Modifying other[1]..." << std::endl;
  other[1] = "Different";

  std::cout << "strings: ";
  for (unsigned int i = 0; i < strings.size(); ++i) {
    std::cout << "[" << strings[i] << "] ";
  }
  std::cout << std::endl;

  std::cout << "other:   ";
  for (unsigned int i = 0; i < other.size(); ++i) {
    std::cout << "[" << other[i] << "] ";
  }
  std::cout << std::endl;

  std::cout << "\n=== Test 5: Out-of-bounds access ===" << std::endl;
  try {
    std::cout << "Trying numbers[n] (index == size)..." << std::endl;
    std::cout << numbers[n] << std::endl; // should throw
  } catch (const std::exception &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "Trying numbers[-1] via cast..." << std::endl;
    std::cout << numbers[static_cast<unsigned int>(-1)]
              << std::endl; // should also throw
  } catch (const std::exception &e) {
    std::cout << "Caught exception: " << e.what() << std::endl;
  }

  std::cout << "\n=== All tests done 😈 ===" << std::endl;
  return 0;
}
