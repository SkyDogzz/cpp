#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string _name;

public:
	Zombie(std::string const& name);
	~Zombie();

	void announce() const;
};

Zombie* newZombie(std::string const& name);
void randomChump(std::string const& name);

#endif
