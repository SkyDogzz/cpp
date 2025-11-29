#include "Zombie.hpp"

Zombie* newZombie(std::string const& name) {
	return new Zombie(name);
}
