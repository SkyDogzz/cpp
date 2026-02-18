#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
    : AForm(name, 25, 5)
{
    if (VERBOSE)
        std::cout << "PresidentialPardonForm contructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
{
    if (VERBOSE)
        std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (VERBOSE)
        std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    if (VERBOSE)
        std::cout << "PresidentialPardonForm destructor called";
}

void PresidentialPardonForm::beExecuted()
{
    std::cout << getName() << " have been pardoned by Zaphod Beeblebrox" << std::endl;
}
