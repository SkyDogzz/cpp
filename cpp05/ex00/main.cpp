#include "Bureaucrat.hpp"
#include <iostream>

static void separator(const std::string &title) {
  std::cout << "\n========== " << title << " ==========\n";
}

static void testCreation(const std::string &name, int grade) {
  std::cout << "\n[TEST] Creating Bureaucrat(\"" << name << "\", " << grade
            << ")\n";
  try {
    Bureaucrat b(name, grade);
    std::cout << "Created: " << b << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception caught during creation: " << e.what() << std::endl;
  }
}

static void testIncrement(Bureaucrat &b, int times) {
  std::cout << "\n[TEST] Incrementing " << b.getName() << " " << times
            << " times\n";
  for (int i = 0; i < times; ++i) {
    try {
      std::cout << "Before increment: " << b << std::endl;
      b.incrementGrade();
      std::cout << "After  increment: " << b << std::endl;
    } catch (std::exception &e) {
      std::cout << "Exception caught while incrementing: " << e.what()
                << std::endl;
    }
  }
}

static void testDecrement(Bureaucrat &b, int times) {
  std::cout << "\n[TEST] Decrementing " << b.getName() << " " << times
            << " times\n";
  for (int i = 0; i < times; ++i) {
    try {
      std::cout << "Before decrement: " << b << std::endl;
      b.decrementGrade();
      std::cout << "After  decrement: " << b << std::endl;
    } catch (std::exception &e) {
      std::cout << "Exception caught while decrementing: " << e.what()
                << std::endl;
    }
  }
}

int main() {
  separator("BASIC CREATION");
  testCreation("Alice", 1);
  testCreation("Bob", 75);
  testCreation("Charlie", 150);

  separator("INVALID CREATION (SHOULD THROW)");
  testCreation("TooHigh", 0);
  testCreation("TooLow", 151);
  testCreation("WayTooHigh", -10);
  testCreation("WayTooLow", 999);

  separator("INCREMENT / DECREMENT ON VALID INSTANCES");
  try {
    Bureaucrat mid("MidLevel", 75);
    std::cout << "Initial: " << mid << std::endl;
    testIncrement(mid, 3);
    testDecrement(mid, 5);
  } catch (std::exception &e) {
    std::cout << "Unexpected exception: " << e.what() << std::endl;
  }

  separator("INCREMENT AT TOP BOUNDARY");
  try {
    Bureaucrat top("TopDog", 1);
    std::cout << "Initial: " << top << std::endl;
    testIncrement(top, 2); // second should throw
  } catch (std::exception &e) {
    std::cout << "Unexpected exception: " << e.what() << std::endl;
  }

  separator("DECREMENT AT BOTTOM BOUNDARY");
  try {
    Bureaucrat bottom("BottomDweller", 150);
    std::cout << "Initial: " << bottom << std::endl;
    testDecrement(bottom, 2); // second should throw
  } catch (std::exception &e) {
    std::cout << "Unexpected exception: " << e.what() << std::endl;
  }

  separator("COPY AND ASSIGNMENT TESTS");
  try {
    Bureaucrat original("Original", 42);
    std::cout << "Original: " << original << std::endl;

    Bureaucrat copy(original);
    std::cout << "Copy:     " << copy << std::endl;

    Bureaucrat assigned("SomeoneElse", 100);
    std::cout << "Before assignment: " << assigned << std::endl;
    assigned = original;
    std::cout << "After  assignment: " << assigned << std::endl;
  } catch (std::exception &e) {
    std::cout << "Unexpected exception in copy/assign: " << e.what()
              << std::endl;
  }

  Bureaucrat a = Bureaucrat("oui", 42);
  Bureaucrat b = a;
  std::cout << a << std::endl;
  std::cout << b << std::endl;

  separator("END OF EX00 TESTS");
  return 0;
}
