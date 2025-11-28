#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "\n===== BASIC CREATION =====\n\n";
  ClapTrap a("Alpha");
  ScavTrap b("Bravo");
  FragTrap c("Charlie");

  std::cout << "\n===== BASIC ACTIONS =====\n\n";
  a.attack("TargetA");
  a.takeDamage(3);
  a.beRepaired(2);

  b.attack("TargetB");
  b.takeDamage(20);
  b.beRepaired(10);
  b.guardGate();

  c.attack("TargetC");
  c.takeDamage(50);
  c.beRepaired(25);
  c.highFivesGuys();

  std::cout << "\n===== ENERGY DRAIN TEST =====\n\n";
  for (int i = 0; i < 12; ++i) {
    a.attack("Dummy");
  }
  a.beRepaired(5); // Should fail: no energy

  std::cout << "\n===== HIT POINTS DRAIN TEST =====\n\n";
  ClapTrap weak("Weakling");
  weak.takeDamage(200); // Dies
  weak.attack("Ghost"); // Cannot act
  weak.beRepaired(10);  // Cannot act

  std::cout << "\n===== MULTIPLE INSTANCES =====\n\n";
  FragTrap f1("FraggyOne");
  FragTrap f2("FraggyTwo");
  f1.attack("FraggyTwo");
  f2.takeDamage(30);

  std::cout << "\n===== MASSIVE STRESS TEST =====\n\n";
  for (int i = 0; i < 5; ++i) {
    c.attack("Enemy Horde");
    c.takeDamage(10);
    c.beRepaired(5);
  }

  std::cout << "\n===== END OF TEST =====\n\n";
  return 0;
}
