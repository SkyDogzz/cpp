#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

static void run_one_test(const std::string &literal) {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Input: \"" << literal << "\"" << std::endl;
  ScalarConverter::convert(literal);
}

static void run_all_tests(void) {
  // Single characters
  run_one_test("a");
  run_one_test("Z");
  run_one_test("0");
  run_one_test(" ");

  // Ints
  run_one_test("0");
  run_one_test("42");
  run_one_test("-42");
  run_one_test("2147483647");   // INT_MAX (if you handle it)
  run_one_test("-2147483648");  // INT_MIN (if you handle it)
  run_one_test("999999999999"); // overflow candidate

  // Doubles
  run_one_test("0.0");
  run_one_test("-4.2");
  run_one_test("4.2");
  run_one_test("42.");
  run_one_test(".42");
  run_one_test("1e1"); // depends how you handle scientific notation

  // Floats
  run_one_test("0.0f");
  run_one_test("-4.2f");
  run_one_test("4.2f");
  run_one_test("42.f");
  run_one_test(".42f");
  run_one_test("1e1f");

  // Pseudo-literals for float
  run_one_test("nanf");
  run_one_test("+inff");
  run_one_test("-inff");

  // Pseudo-literals for double
  run_one_test("nan");
  run_one_test("+inf");
  run_one_test("-inf");

  // Clearly invalid stuff
  run_one_test("abc");
  run_one_test("4.2ff");
  run_one_test("--42");
  run_one_test("++inf");
  run_one_test("");
  run_one_test("   42");
  run_one_test("42 42");
}

int main(int argc, char **argv) {
  if (argc == 2) {
    // Single literal passed by user
    run_one_test(argv[1]);
  } else {
    std::cout << "Usage: ./convert <literal>" << std::endl;
    std::cout << "No valid argument given, running full test suite instead."
              << std::endl;
    run_all_tests();
  }
  return 0;
}
