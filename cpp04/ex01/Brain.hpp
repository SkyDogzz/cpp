#ifndef BRAIN_CPP
#define BRAIN_CPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <string>

#define BRAIN_SIZE 100

class Brain {
protected:
  std::string _ideas[BRAIN_SIZE];

public:
  Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  ~Brain();
};

#endif
