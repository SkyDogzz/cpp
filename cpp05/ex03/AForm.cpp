#include "AForm.hpp"

#include <ostream>

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name)
    , _signed(0)
    , _gradeToSign(gradeToSign)
    , _gradeToExecute(gradeToExecute)
{
    if (VERBOSE)
        std::cout << "AForm constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToExecute > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name)
    , _signed(other._signed)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExecute(other._gradeToExecute)
{
    if (VERBOSE)
        std::cout << "AForm copy constructr called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (VERBOSE)
        std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

AForm::~AForm()
{
    if (VERBOSE)
        std::cout << "AForm destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() { return "AForm Grade Too High Excption"; }

const char* AForm::GradeTooLowException::what() const throw() { return "AForm Grade Too Low Excption"; }

const char* AForm::FormNotSignedException::what() const throw() { return "AForm Not Signed Exception"; }

const std::string& AForm::getName(void) const { return _name; }

unsigned int AForm::getGradeToSign(void) const { return _gradeToSign; }

unsigned int AForm::getGradeToExecute(void) const { return _gradeToExecute; }

bool AForm::isSigned(void) const { return _signed; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (bureaucrat.getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
    _signed = 1;
    std::cout << bureaucrat << " signed form " << this << std::endl;
}

void AForm::beExecuted(void) { }

std::ostream& operator<<(std::ostream& ostream, const AForm& form) { return ostream << form.getName() << std::endl; }
