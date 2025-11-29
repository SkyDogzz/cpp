#include "DiamondTrap.hpp"

int main() {
  std::cout << "\n===== DIAMOND CREATION =====\n\n";
  DiamondTrap d("DiaStar");
  DiamondTrap e("Emerald");

  std::cout << "\n===== ATTRIBUTE TEST =====\n\n";
  d.attack("Bandit");
  d.takeDamage(40);
  d.beRepaired(20);

  e.attack("Goblin");
  e.takeDamage(80);
  e.beRepaired(50);

  std::cout << "\n===== SPECIAL ABILITIES =====\n\n";
  d.whoAmI();
  e.whoAmI();

  std::cout << "\n===== SCAV + FRAG FEATURES =====\n\n";
  d.guardGate();     // From ScavTrap
  d.highFivesGuys(); // From FragTrap

  std::cout << "\n===== ENERGY DRAIN TEST =====\n\n";
  for (int i = 0; i < 60; ++i) {
    d.attack("Infinite Dummy");
  }
  d.beRepaired(10);

  std::cout << "\n===== MULTIPLE DIAMONDS =====\n\n";
  DiamondTrap army[3] = {DiamondTrap("Ruby"), DiamondTrap("Sapphire"),
                         DiamondTrap("Onyx")};

  for (int i = 0; i < 3; ++i) {
    army[i].attack("Training Dummy");
    army[i].whoAmI();
  }

  std::cout << "\n===== DESTRUCTION ORDER CHECK =====\n\n";
  {
    DiamondTrap tmp("Temporary");
    tmp.attack("Fleeting Shadow");
    tmp.whoAmI();
  }

  std::cout << "\n===== END OF TEST =====\n\n";
  return 0;
}
