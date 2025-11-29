#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {};

#include <iostream>
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "called" << std::endl;
  if (this != &other) {
    _grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName(void) const { return _name; }

const unsigned int &Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
  if (_grade <= 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (_grade >= 150)
    throw GradeTooLowException();
  _grade++;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &other) {
  return ostream << other.getName() << " bureaucrat grade " << other.getGrade()
                 << "." << std::endl;
}
