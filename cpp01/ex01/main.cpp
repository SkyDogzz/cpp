#include "Zombie.hpp"

#include <iostream>

static void inspectHorde(Zombie* horde, int size) {
	if (!horde) {
		std::cout << "No zombies to inspect." << std::endl;
		return;
	}
	for (int i = 0; i < size; ++i) {
		horde[i].announce();
	}
}

int main() {
	std::cout << "Creating a horde of 5 Michael zombies" << std::endl;
	Zombie* horde = zombieHorde(5, "Michael");
	inspectHorde(horde, 5);
	delete[] horde;

	std::cout << "\nAttempting to create an invalid horde" << std::endl;
	Zombie* invalid = zombieHorde(0, "Nobody");
	inspectHorde(invalid, 0);
	delete[] invalid;

	std::cout << "\nSingle zombie to verify constructors still work" << std::endl;
	Zombie solo("Lonely");
	solo.announce();
	return 0;
}
