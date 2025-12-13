#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
  std::cout << "===== MUTANTSTACK TESTS =====" << std::endl;

  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << "Top: " << mstack.top() << std::endl;

  mstack.pop();
  std::cout << "Size after pop: " << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  std::cout << "\nIterating MutantStack:" << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  std::stack<int> s(mstack);
  std::cout << "\nCopied into std::stack, top is: " << s.top() << std::endl;

  std::cout << "\n--- Comparison with std::list ---" << std::endl;

  std::list<int> lst;
  lst.push_back(5);
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  lst.push_back(0);

  for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
    std::cout << *lit << std::endl;

  return 0;
}
