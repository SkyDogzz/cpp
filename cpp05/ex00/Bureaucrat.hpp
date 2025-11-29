#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class GradeTooHighException : public std::exception {};
class GradeTooLowException : public std::exception {};

class Bureaucrat {
private:
  const std::string _name;
  unsigned int _grade;

public:
  Bureaucrat(std::string name, unsigned int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  const std::string &getName(void) const;
  const unsigned int &getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &);

#endif
