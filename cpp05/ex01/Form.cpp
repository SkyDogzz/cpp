#include "Form.hpp"
#include <ostream>

Form::Form(std::string name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : _name(name), _signed(0), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  else if (gradeToExecute > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
  if (this != &other)
    _signed = other._signed;
  return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form Grade Too High Excption";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form Grade Too Low Excption";
}

const std::string &Form::getName(void) const { return _name; }

unsigned int Form::getGradeToSign(void) const { return _gradeToSign; }

unsigned int Form::getGradeToExecute(void) const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (bureaucrat.getGrade() > 150)
    throw Bureaucrat::GradeTooLowException();
  _signed = 1;
  std::cout << bureaucrat << " signed form " << this << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
  return ostream << form.getName() << std::endl;
}
