#include "PMergeMe.hpp"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " [list of positive integers]";
    return 1;
  }
  try {
    PMergeMe instance;
    instance.verifArgs((argv + 1));
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknow exception thrown" << std::endl;
  }
}
