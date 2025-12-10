#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

Intern::~Intern() {}

const char *Intern::FormDoesntExistException::what() const throw() {
  return "Form type doesnt exist";
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
  if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(formTarget);
  else if (formName == "presidential pardon")
    return new PresidentialPardonForm(formTarget);
  else if (formName == "robotomy request")
    return new RobotomyRequestForm(formTarget);
  else
    throw Intern::FormDoesntExistException();
  return NULL;
}
