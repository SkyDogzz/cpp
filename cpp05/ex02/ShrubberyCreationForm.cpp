#include "ShrubberyCreationForm.hpp"

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::CouldntOpenFileException::what() const throw() {
	return "Couldnt open output file";
}

void ShrubberyCreationForm::beExecuted(void) {
	unsigned int size = 110;
	unsigned int half = size / 2;

	srand(time(NULL));

	std::ofstream file((_name + "_shrubbery").data());
	if (!file.is_open())
		throw ShrubberyCreationForm::CouldntOpenFileException();

	for (unsigned int i = 0; i <= half; i++) {
		for (unsigned int s = 0; s < half - i; s++)
			file << " ";
		for (unsigned int k = 0; k < 2 * i + 1; k++) {
			int r = rand() % 201;
			if (r < 10)
				file << "0";
			else if (r < 20)
				file << "-";
			else
				file << "*";
		}
		file << std::endl;
	}

	for (unsigned int t = 0; t < 3; t++) {
		for (unsigned int s = 0; s < half - 1; s++)
			file << " ";
		file << "|||" << std::endl;
	}

	file.close();
}
