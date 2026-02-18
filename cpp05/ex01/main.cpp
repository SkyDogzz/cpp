#include "Bureaucrat.hpp"
#include "Form.hpp"

static void separator(const std::string& title) { std::cout << "\n========== " << title << " ==========\n"; }

static void testFormCreation(const std::string& name, int signGrade, int execGrade)
{
    std::cout << "\n[TEST] Creating Form(\"" << name << "\", sign " << signGrade << ", exec " << execGrade << ")\n";
    try {
        Form f(name, signGrade, execGrade);
        std::cout << "Created: " << f << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception while creating form: " << e.what() << std::endl;
    }
}

static void testSigning(Bureaucrat& b, Form& f)
{
    std::cout << "\n[TEST] " << b.getName() << " tries to sign " << f.getName() << std::endl;
    std::cout << "Before: " << f << std::endl;
    try {
        b.signForm(f);
    } catch (std::exception& e) {
        std::cout << "Exception from signForm: " << e.what() << std::endl;
    }
    std::cout << "After:  " << f << std::endl;
}

int main()
{
    separator("FORM CREATION (VALID)");
    testFormCreation("NDA", 42, 10);
    testFormCreation("Contract", 1, 1);
    testFormCreation("LowLevelDoc", 150, 150);

    separator("FORM CREATION (INVALID)");
    testFormCreation("TooHighSign", 0, 10);
    testFormCreation("TooLowSign", 151, 10);
    testFormCreation("TooHighExec", 10, 0);
    testFormCreation("TooLowExec", 10, 151);
    testFormCreation("BothWrongHigh", 0, 0);
    testFormCreation("BothWrongLow", 200, 200);

    separator("SIGNING SCENARIOS");
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat senior("Senior", 40);
        Bureaucrat junior("Junior", 100);
        Bureaucrat intern("Intern", 150);

        Form hardForm("HardForm", 10, 10);
        Form midForm("MidForm", 75, 75);
        Form easyForm("EasyForm", 150, 150);

        std::cout << "\nInitial forms:\n";
        std::cout << hardForm << std::endl;
        std::cout << midForm << std::endl;
        std::cout << easyForm << std::endl;

        separator("JUNIOR AND INTERN TRY TO SIGN HARD FORM");
        testSigning(junior, hardForm);
        testSigning(intern, hardForm);

        separator("SENIOR SIGNS HARD FORM");
        testSigning(senior, hardForm);

        separator("BOSS SIGNS EVERYTHING");
        testSigning(boss, hardForm);
        testSigning(boss, midForm);
        testSigning(boss, easyForm);

        separator("TRY SIGNING ALREADY SIGNED FORMS");
        testSigning(boss, hardForm);
        testSigning(junior, midForm);
        testSigning(intern, easyForm);

    } catch (std::exception& e) {
        std::cout << "Unexpected exception in signing scenarios: " << e.what() << std::endl;
    }

    separator("COPY / ASSIGNMENT TESTS FOR FORM");
    try {
        Form templateForm("Template", 42, 21);
        std::cout << "Template: " << templateForm << std::endl;

        Form copy(templateForm);
        std::cout << "Copy:     " << copy << std::endl;

        Form another("Another", 150, 150);
        std::cout << "Before assignment: " << another << std::endl;
        another = templateForm;
        std::cout << "After  assignment: " << another << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected exception in copy/assign: " << e.what() << std::endl;
    }

    separator("END OF EX01 TESTS");
    return 0;
}
