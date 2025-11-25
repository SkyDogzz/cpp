#include "ClapTrap.hpp"

int main() {
  std::cout << "=== BASIC CONSTRUCTION / DESTRUCTION TEST ===" << std::endl;
  {
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    ClapTrap c(a);

    std::cout << "=== SIMPLE ATTACK SEQUENCE ===" << std::endl;
    a.attack("a training dummy");
    b.attack("a rock");
    c.attack("a ghost");

    std::cout << "=== DAMAGE / REPAIR TEST ===" << std::endl;
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(20);
    a.beRepaired(5);
    a.attack("something");
  }

  std::cout << std::endl << "=== ENERGY DEPLETION TEST ===" << std::endl;
  {
    ClapTrap e("Exhausted");
    for (int i = 0; i < 12; ++i) {
      std::cout << "--- Turn " << i + 1 << " ---" << std::endl;
      e.attack("dummy");
    }

    std::cout << "--- Trying to repair with 0 energy ---" << std::endl;
    e.beRepaired(5);
  }

  std::cout << std::endl << "=== MIXED SCENARIO ===" << std::endl;
  {
    ClapTrap hero("Hero");
    ClapTrap monster("Monster");

    hero.attack("Monster");
    monster.takeDamage(0);

    monster.attack("Hero");
    hero.takeDamage(4);

    hero.beRepaired(2);
    hero.attack("Monster");
    monster.takeDamage(8);

    monster.takeDamage(100);
    monster.attack("Hero");
    monster.beRepaired(10);
  }

  std::cout << std::endl << "=== ASSIGNATION TEST ===" << std::endl;
  {
    ClapTrap a("First");
    ClapTrap b("Second");

    a.attack("something");
    b = a;
    b.attack("another thing");
  }

  return 0;
}
