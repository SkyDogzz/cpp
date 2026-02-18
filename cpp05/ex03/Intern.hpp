#ifndef INTERN_HPP
#define INTERN_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    class FormDoesntExistException : public std::exception {
    public:
        const char* what() const throw();
    };

    AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
