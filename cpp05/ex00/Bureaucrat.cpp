#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
    : _name(name)
    , _grade(grade)
{
    if (VERBOSE)
        std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name)
    , _grade(other._grade)
{
    if (VERBOSE)
        std::cout << "Bureaucrat copy constructor called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (VERBOSE)
        std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    if (VERBOSE)
        std::cout << "Bureaucrat destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat: grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat: grade too low"; }

const std::string& Bureaucrat::getName(void) const { return _name; }

const unsigned int& Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& other)
{
    return ostream << other.getName() << " bureaucrat grade " << other.getGrade() << "." << std::endl;
}
