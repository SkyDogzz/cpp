#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>

static void runReferenceScenario() {
	std::cout << "\n--- HumanA reference scenario ---" << std::endl;
	Weapon sword("shiny sword");
	HumanA arthur("Arthur", sword);
	arthur.attack();
	sword.setType("legendary Excalibur");
	arthur.attack();
}

static void runPointerScenario() {
	std::cout << "\n--- HumanB pointer scenario ---" << std::endl;
	Weapon axe("crude axe");
	HumanB lancelot("Lancelot");
	lancelot.attack();
	lancelot.setWeapon(axe);
	lancelot.attack();
	axe.setType("enchanted axe");
	lancelot.attack();
}

static void runSharedWeaponScenario() {
	std::cout << "\n--- Shared weapon scenario ---" << std::endl;
	Weapon spear("long spear");
	HumanA leonidas("Leonidas", spear);
	HumanB horatio("Horatio");
	horatio.setWeapon(spear);
	leonidas.attack();
	horatio.attack();
	spear.setType("broken spear");
	leonidas.attack();
	horatio.attack();
}

int main() {
	std::cout << "Testing unnecessary violence simulations" << std::endl;
	runReferenceScenario();
	runPointerScenario();
	runSharedWeaponScenario();
	return 0;
}
