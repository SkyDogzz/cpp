#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Form {
private:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

private:
    Form();

public:
    Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    const std::string& getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;

    void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& ostream, const Form& form);

#endif
