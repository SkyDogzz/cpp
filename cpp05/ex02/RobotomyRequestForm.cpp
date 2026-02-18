#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name)
    : AForm(name, 145, 137)
{
    if (VERBOSE)
        std::cout << "RobotomyRequestForm constructor called" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
{
    if (VERBOSE)
        std::cout << "RobotomyRequestForm copy operator called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (VERBOSE)
        std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    if (VERBOSE)
        std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::beExecuted(void)
{
    std::cout << "Random drilling sound goes brrrr" << std::endl;

    int r = rand() % 2;
    if (r % 2 == 0)
        std::cout << _name << " has been robotomized" << std::endl;
    else
        std::cout << _name << " robotomization failed" << std::endl;
}
