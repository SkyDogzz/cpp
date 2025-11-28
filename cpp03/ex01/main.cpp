#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  std::cout << "=== BASIC CONSTRUCTION / DESTRUCTION CHAINING ===" << std::endl;
  {
    ScavTrap s("Sentinel");
  }

  std::cout << std::endl << "=== CLAPTRAP VS SCAVTRAP ===" << std::endl;
  {
    ClapTrap c("Clappy");
    ScavTrap s("Scavvy");

    c.attack("target dummy");
    s.attack("target dummy");

    c.takeDamage(5);
    c.beRepaired(3);

    s.takeDamage(40);
    s.beRepaired(20);
  }

  std::cout << std::endl << "=== SPECIAL MODE: GUARD GATE ===" << std::endl;
  {
    ScavTrap gatekeeper("Gatekeeper");
    gatekeeper.guardGate();
    gatekeeper.attack("intruder");
    gatekeeper.takeDamage(90);
    gatekeeper.guardGate();
  }

  std::cout << std::endl << "=== ENERGY DEPLETION ON SCAVTRAP ===" << std::endl;
  {
    ScavTrap s("ExhaustedScav");
    for (int i = 0; i < 55; ++i) {
      std::cout << "--- Turn " << i + 1 << " ---" << std::endl;
      s.attack("dummy");
    }
    s.beRepaired(10);
    s.guardGate();
  }

  std::cout << std::endl << "=== COPY / ASSIGNMENT TESTS ===" << std::endl;
  {
    ScavTrap original("Original");
    ScavTrap copy(original);
    ScavTrap assigned("Assigned");
    assigned = original;

    original.attack("target 1");
    copy.attack("target 2");
    assigned.attack("target 3");

    original.guardGate();
    copy.guardGate();
    assigned.guardGate();
  }

  return 0;
}
