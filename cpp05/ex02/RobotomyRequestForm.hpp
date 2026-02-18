#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
private:
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void beExecuted(void);
};
#endif
