#include "Iter.hpp"
#include <iostream>
#include <string>

// Generic print function (const ref ✅)
template <typename T> void printElement(T const &value) {
  std::cout << value << " ";
}

// Function that modifies an int (non-const ref ✅)
void increment(int &value) { ++value; }

// Function that uppercases a std::string (non-const ref ✅)
void toUpper(std::string &str) {
  for (std::size_t i = 0; i < str.size(); ++i) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = static_cast<char>(str[i] - 'a' + 'A');
  }
}

// A small custom type to be fancy 😌
struct Awesome {
  int _n;
  Awesome(int n = 42) : _n(n) {}
  int get() const { return _n; }
};

std::ostream &operator<<(std::ostream &os, Awesome const &obj) {
  os << obj.get();
  return os;
}

int main() {
  {
    std::cout << "=== Test 1: int array, print ===" << std::endl;
    int tab[] = {0, 1, 2, 3, 4};
    std::size_t len = sizeof(tab) / sizeof(tab[0]);

    std::cout << "Original: ";
    iter(tab, len, printElement<int>);
    std::cout << std::endl;

    std::cout << "After increment: ";
    iter(tab, len, increment);
    iter(tab, len, printElement<int>);
    std::cout << std::endl << std::endl;
  }

  {
    std::cout << "=== Test 2: std::string array, const + non-const ==="
              << std::endl;
    std::string words[] = {"hello", "darkness", "my", "friend"};
    std::size_t len = sizeof(words) / sizeof(words[0]);

    std::cout << "Original: ";
    iter(words, len, printElement<std::string>);
    std::cout << std::endl;

    iter(words, len, toUpper);

    std::cout << "Uppercased: ";
    iter(words, len, printElement<std::string>);
    std::cout << std::endl << std::endl;
  }

  {
    std::cout << "=== Test 3: const array ===" << std::endl;
    const double nums[] = {3.14, 2.71, 1.41, 0.577};
    std::size_t len = sizeof(nums) / sizeof(nums[0]);

    // This should work if you handle const T* in your iter
    std::cout << "Const double array: ";
    iter(nums, len, printElement<double>);
    std::cout << std::endl << std::endl;
  }

  {
    std::cout << "=== Test 4: custom type (Awesome) ===" << std::endl;
    Awesome arr[] = {Awesome(1), Awesome(2), Awesome(3), Awesome(1337)};
    std::size_t len = sizeof(arr) / sizeof(arr[0]);

    iter(arr, len, printElement<Awesome>);
    std::cout << std::endl << std::endl;
  }

  {
    std::cout << "=== Test 5: templated function pointer syntax ==="
              << std::endl;
    int tab[] = {10, 20, 30};
    std::size_t len = sizeof(tab) / sizeof(tab[0]);

    // Explicit template argument for the function, like in many subject
    // examples
    iter(tab, len, &printElement<int>);
    std::cout << std::endl;
  }

  return 0;
}
