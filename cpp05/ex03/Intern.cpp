#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    if (VERBOSE)
        std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    if (VERBOSE)
        std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (VERBOSE)
        std::cout << "Intern assignment operator called" << std::endl;
    if (this != &other) { }
    return *this;
}

Intern::~Intern()
{
    if (VERBOSE)
        std::cout << "Intern destructor called" << std::endl;
}

const char* Intern::FormDoesntExistException::what() const throw() { return "Form type doesnt exist"; }

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
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
