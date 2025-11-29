#include "Zombie.hpp"

#include <iostream>

Zombie* zombieHorde(int n, std::string const& name) {
	if (n <= 0) {
		std::cerr << "Cannot create a horde with " << n << " zombies." << std::endl;
		return 0;
	}
	Zombie* horde = new Zombie[n];
	for (int i = 0; i < n; ++i) {
		horde[i].setName(name);
	}
	return horde;
}
