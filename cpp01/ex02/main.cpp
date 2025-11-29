#include <iostream>
#include <string>

static void printAddresses(std::string const& value,
                           std::string const* ptr,
                           std::string const& ref) {
	std::cout << "Address of string variable : " << &value << std::endl;
	std::cout << "Address stored in pointer  : " << ptr << std::endl;
	std::cout << "Address referenced by ref  : " << &ref << std::endl;
}

static void printValues(std::string const& value, std::string const* ptr, std::string const& ref) {
	std::cout << "Value of string variable   : " << value << std::endl;
	std::cout << "Value pointed by pointer   : " << *ptr << std::endl;
	std::cout << "Value referenced by ref    : " << ref << std::endl;
}

int main() {
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string* stringPTR = &stringVAR;
	std::string& stringREF = stringVAR;

	std::cout << "Initial state" << std::endl;
	printAddresses(stringVAR, stringPTR, stringREF);
	printValues(stringVAR, stringPTR, stringREF);

	std::cout << "\nMutating via pointer" << std::endl;
	*stringPTR = "Pointer edit kicks in";
	printValues(stringVAR, stringPTR, stringREF);

	std::cout << "\nMutating via reference" << std::endl;
	stringREF = "Reference edit takes over";
	printValues(stringVAR, stringPTR, stringREF);

	return 0;
}
