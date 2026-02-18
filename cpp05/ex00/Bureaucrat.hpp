#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
    const std::string _name;
    unsigned int _grade;

private:
    Bureaucrat();

public:
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    const std::string& getName(void) const;
    const unsigned int& getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat&);

#endif
