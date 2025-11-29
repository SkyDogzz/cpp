#include "Zombie.hpp"

#include <iostream>

static void testStackZombie() {
	std::cout << "\n--- Stack zombie demo ---" << std::endl;
	Zombie pierre("Pierre");
	pierre.announce();
}

static void testHeapZombie() {
	std::cout << "\n--- Heap zombie demo ---" << std::endl;
	Zombie* paul = newZombie("Paul");
	paul->announce();
	delete paul;
}

static void testRandomChumps() {
	std::cout << "\n--- Random chump parade ---" << std::endl;
	std::string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
	for (size_t idx = 0; idx < sizeof(names) / sizeof(names[0]); ++idx) {
		randomChump(names[idx]);
	}
}

int main() {
	std::cout << "Welcome to the zombie playground" << std::endl;
	testStackZombie();
	testHeapZombie();
	testRandomChumps();
	std::cout << "\nAll zombies are done for the day.\n" << std::endl;
	return 0;
}
