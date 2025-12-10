#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void single_test(int index) {
  std::cout << "===== Test #" << index << " =====" << std::endl;
  Base *ptr = generate();
  std::cout << "Pointer: " << ptr << std::endl;

  std::cout << "identify(Base*): ";
  identify(ptr);

  std::cout << "identify(Base&): ";
  if (ptr)
    identify(*ptr);
  else
    std::cout << "Null pointer, cannot take reference" << std::endl;

  delete ptr;
}

static void null_test() {
  std::cout << "===== Null pointer test =====" << std::endl;
  Base *ptr = 0;

  std::cout << "identify(Base*): ";
  identify(ptr);
  identify(*ptr);
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  for (int i = 0; i < 10; ++i)
    single_test(i);

  null_test();

  return 0;
}
