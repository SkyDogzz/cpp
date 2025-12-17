#include "PMergeMe.hpp"

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(const PMergeMe &other) { (void)other; }

PMergeMe &PMergeMe::operator=(const PMergeMe &other) {
  return *this;
  (void)other;
}

PMergeMe::~PMergeMe() {}

bool contains_bad_char(std::string &s, std::string set) {
  const char *consted = static_cast<const char *>(s.data());

  while (*consted) {
    if (set.find(*consted) == std::string::npos)
      return true;
    consted++;
  }
  return false;
}

static bool validInt(const char *s) {
  std::string set = "0123456789";
  std::string str = s;

  if (contains_bad_char(str, set))
    return false;
  else if (str.size() > 10)
    return false;
  else if (atol(str.c_str()) > UINT_MAX)
    return false;
  return true;
}

static bool findInVec(std::vector<unsigned int> vec, unsigned int search) {
  std::vector<unsigned int>::iterator it = vec.begin();

  while (it != vec.end()) {
    if (*it == search)
      return true;
    it++;
  }
  return false;
}

void PMergeMe::verifArgs(char **args) {
  while (*args) {
    if (!validInt(*args))
      throw PMergeMe::ArgWrongFormat();
    if (findInVec(_verif, atol(*args)))
      throw PMergeMe::ArgDuplicate();
    _verif.push_back(atol(*args));
    args++;
  }
}

const char *PMergeMe::ArgWrongFormat::what() const throw() {
  return "Wrong arg format";
}

const char *PMergeMe::ArgDuplicate::what() const throw() {
  return "Duplicate arg";
}
