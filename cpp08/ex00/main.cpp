#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::cout << "===== EASYFIND TESTS =====" << std::endl;

  std::vector<int> v;
  for (int i = 0; i < 20; ++i)
    v.push_back(i * 2);

  try {
    std::vector<int>::iterator it = easyfind(v, 8);
    std::cout << "Found in vector: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Vector error: " << e.what() << std::endl;
  }

  try {
    easyfind(v, 7);
  } catch (std::exception &e) {
    std::cout << "Expected failure (vector): " << e.what() << std::endl;
  }

  std::list<int> l;
  for (int i = 0; i < 10; ++i)
    l.push_back(i);

  try {
    std::list<int>::iterator it = easyfind(l, 5);
    std::cout << "Found in list: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "List error: " << e.what() << std::endl;
  }

  std::deque<int> d;
  d.push_back(42);
  d.push_back(21);
  d.push_back(84);

  try {
    std::deque<int>::iterator it = easyfind(d, 42);
    std::cout << "Found in deque: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Deque error: " << e.what() << std::endl;
  }

  return 0;
}
