#ifndef AFORM_HPP
#define AFORM_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
protected:
    const std::string _name;
    bool _signed;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

private:
    AForm();

public:
    AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm() = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    const std::string& getName(void) const;
    unsigned int getGradeToSign(void) const;
    unsigned int getGradeToExecute(void) const;
    bool isSigned(void) const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void beExecuted(void);
};

std::ostream& operator<<(std::ostream& ostream, const AForm& form);

#endif
