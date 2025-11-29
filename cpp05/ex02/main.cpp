#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void separator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n";
}

static void testExecution(Bureaucrat &executor, AForm &form) {
  std::cout << "\n[TEST] " << executor.getName() << " (grade "
            << executor.getGrade() << ") tries to execute " << form.getName()
            << std::endl;
  std::cout << "Form state before exec: " << form << std::endl;
  try {
    executor.executeForm(form);
  } catch (std::exception &e) {
    std::cout << "Exception during executeForm: " << e.what() << std::endl;
  }
  std::cout << "Form state after exec:  " << form << std::endl;
}

static void testSigning(Bureaucrat &signer, AForm &form) {
  std::cout << "\n[TEST] " << signer.getName() << " (grade "
            << signer.getGrade() << ") tries to sign " << form.getName()
            << std::endl;
  try {
    signer.signForm(form);
  } catch (std::exception &e) {
    std::cout << "Exception during signForm: " << e.what() << std::endl;
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  separator("CREATION OF BUREAUCRATS");
  Bureaucrat top("Top", 1);
  Bureaucrat high("High", 20);
  Bureaucrat mid("Mid", 75);
  Bureaucrat low("Low", 150);
  Bureaucrat execRobot("ExecRobot", 45);
  Bureaucrat execShrub("ExecShrub", 137);
  Bureaucrat execPardon("ExecPardon", 5);

  std::cout << top << std::endl;
  std::cout << high << std::endl;
  std::cout << mid << std::endl;
  std::cout << low << std::endl;
  std::cout << execRobot << std::endl;
  std::cout << execShrub << std::endl;
  std::cout << execPardon << std::endl;

  separator("CREATION OF FORMS");
  ShrubberyCreationForm shrub("home");
  RobotomyRequestForm robo("Bender");
  PresidentialPardonForm pardon("Arthur Dent");

  std::cout << shrub << std::endl;
  std::cout << robo << std::endl;
  std::cout << pardon << std::endl;

  separator("EXECUTE UNSIGNED FORMS (SHOULD FAIL)");
  testExecution(execShrub, shrub);
  testExecution(execRobot, robo);
  testExecution(execPardon, pardon);

  separator("SIGNING WITH INSUFFICIENT GRADES");
  testSigning(low, shrub);
  testSigning(mid, robo);
  testSigning(high, pardon);

  separator("SIGNING WITH SUFFICIENT GRADES");
  testSigning(execShrub, shrub);
  testSigning(execRobot, robo);
  testSigning(execPardon, pardon);

  separator("EXECUTE WITH INSUFFICIENT GRADE");
  // Try to execute shrubbery with low-grade bureaucrat
  testExecution(low, shrub);
  // Try to execute robotomy with mid (too low, needs 45)
  testExecution(mid, robo);
  // Try to execute pardon with high (too low, needs 5)
  testExecution(high, pardon);

  separator("EXECUTE WITH SUFFICIENT GRADE");
  testExecution(execShrub, shrub);
  testExecution(execRobot, robo);
  testExecution(execPardon, pardon);

  separator("MULTIPLE ROBOTOMY EXECUTIONS TO TEST 50% SUCCESS");
  for (int i = 0; i < 5; ++i) {
    std::cout << "\n--- Robotomy attempt #" << (i + 1) << " ---\n";
    testExecution(execRobot, robo);
  }

  separator("COPY AND ASSIGNMENT TESTS (FORMS)");
  try {
    ShrubberyCreationForm shrub2("garden");
    ShrubberyCreationForm shrub3(shrub);
    std::cout << "Original shrub: " << shrub << std::endl;
    std::cout << "Copied shrub:   " << shrub3 << std::endl;
    shrub2 = shrub;
    std::cout << "Assigned shrub: " << shrub2 << std::endl;

    RobotomyRequestForm robo2("Someone");
    robo2 = robo;
    std::cout << "Assigned robotomy: " << robo2 << std::endl;

    PresidentialPardonForm pardon2(pardon);
    std::cout << "Copied pardon: " << pardon2 << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception in copy/assign tests: " << e.what() << std::endl;
  }

  separator("END OF EX02 TESTS");
  return 0;
}
