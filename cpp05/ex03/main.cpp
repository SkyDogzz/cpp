#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void separator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n";
}

static AForm *safeMakeForm(Intern &intern, const std::string &name,
                           const std::string &target) {
  std::cout << "\n[Intern factory] Requesting form \"" << name
            << "\" targeting \"" << target << "\"\n";
  AForm *form = 0;
  try {
    form = intern.makeForm(name, target);
    if (form) {
      std::cout << "Created form at address: " << form << std::endl;
    } else {
      std::cout << "makeForm returned NULL pointer.\n";
    }
  } catch (std::exception &e) {
    std::cout << "Exception inside makeForm: " << e.what() << std::endl;
  }
  return form;
}

static void signAndExecute(Bureaucrat &signer, Bureaucrat &executor,
                           AForm *form) {
  if (!form) {
    std::cout << "[signAndExecute] Null form pointer, skipping.\n";
    return;
  }
  std::cout << "\n[Pipeline] Signer: " << signer.getName()
            << " / Executor: " << executor.getName()
            << " / Form: " << form->getName() << std::endl;

  try {
    signer.signForm(*form);
  } catch (std::exception &e) {
    std::cout << "Exception while signing: " << e.what() << std::endl;
  }

  try {
    executor.executeForm(*form);
  } catch (std::exception &e) {
    std::cout << "Exception while executing: " << e.what() << std::endl;
  }
}

int main() {
  std::srand(static_cast<unsigned int>(std::time(0)));

  separator("CREATE INTERN AND BUREAUCRATS");
  Intern someRandomIntern;

  Bureaucrat top("Top", 1);
  Bureaucrat shrubExec("ShrubExec", 137);
  Bureaucrat robotExec("RobotExec", 45);
  Bureaucrat pardonExec("PardonExec", 5);
  Bureaucrat low("Low", 150);

  std::cout << top << std::endl;
  std::cout << shrubExec << std::endl;
  std::cout << robotExec << std::endl;
  std::cout << pardonExec << std::endl;
  std::cout << low << std::endl;

  separator("VALID FORM CREATION VIA INTERN");
  AForm *shrub = safeMakeForm("shrubbery creation", "garden");
  AForm *robo = safeMakeForm("robotomy request", "Bender");
  AForm *pardon = safeMakeForm("presidential pardon", "Arthur Dent");

  separator("INVALID FORM CREATION VIA INTERN");
  AForm *unknown1 = safeMakeForm("coffee request", "Machine");
  AForm *unknown2 = safeMakeForm("totally random form", "Nobody");
  (void)unknown1;
  (void)unknown2;

  separator("PIPELINES WITH CORRECT GRADES");
  if (shrub) {
    signAndExecute(top, shrubExec, shrub);
  }
  if (robo) {
    signAndExecute(top, robotExec, robo);
  }
  if (pardon) {
    signAndExecute(top, pardonExec, pardon);
  }

  separator("ATTEMPT EXECUTION WITH LOW GRADE (SHOULD FAIL)");
  if (shrub) {
    signAndExecute(low, low, shrub);
  }
  if (robo) {
    signAndExecute(low, low, robo);
  }
  if (pardon) {
    signAndExecute(low, low, pardon);
  }

  separator("MULTIPLE ROBOTOMIES CREATED BY INTERN");
  AForm *robo2 = safeMakeForm("robotomy request", "Marvin");
  AForm *robo3 = safeMakeForm("robotomy request", "HAL9000");
  if (robo2) {
    signAndExecute(top, robotExec, robo2);
    std::cout << "\n--- Extra robotomy executions on robo2 ---\n";
    for (int i = 0; i < 3; ++i) {
      try {
        robotExec.executeForm(*robo2);
      } catch (std::exception &e) {
        std::cout << "Exception during extra exec: " << e.what() << std::endl;
      }
    }
  }
  if (robo3) {
    signAndExecute(top, robotExec, robo3);
  }

  separator("CLEANUP (DELETE ALLOCATED FORMS)");
  delete shrub;
  delete robo;
  delete pardon;
  delete robo2;
  delete robo3;

  separator("END OF EX03 TESTS");
  return 0;
}
