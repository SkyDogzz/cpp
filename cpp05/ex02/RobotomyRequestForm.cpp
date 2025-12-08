#include "RobotomyRequestForm.hpp"

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 145, 137) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "Random drilling sound goes brrrr" << std::endl;

	int r = rand() % 2;
	if (r % 2 == 0)
		std::cout << _name << " has been robotomized" << std::endl;
	else
		std::cout << _name << " robotomization failed" << std::endl;
}
