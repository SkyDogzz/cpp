#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <cstdlib>
#include <exception>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm {
private:
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    void beExecuted(void);
};

#endif
