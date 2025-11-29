#include "Zombie.hpp"

void randomChump(std::string const& name) {
	Zombie zombie(name);
	zombie.announce();
}
