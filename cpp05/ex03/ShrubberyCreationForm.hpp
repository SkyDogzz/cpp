#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <stdlib.h>
#include <time.h>

#include <cstdlib>
#include <exception>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    class CouldntOpenFileException : public std::exception {
    public:
        const char* what() const throw();
    };

    void beExecuted(void);
};

#endif
