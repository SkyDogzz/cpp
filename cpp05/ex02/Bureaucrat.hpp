#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#ifndef VERBOSE
#define VERBOSE 0
#endif

#include <exception>
#include <string>

#define COLOR_RED "\e[1;31m"
#define STYLE_RESET "\e[0m"

class AForm;
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
    void signForm(AForm& form);
    void executeForm(AForm& form);
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat&);

#endif
