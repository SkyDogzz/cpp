#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string _name;

public:
	Zombie();
	Zombie(std::string const& name);
	~Zombie();

	void announce() const;
	void setName(std::string const& name);
};

Zombie* zombieHorde(int n, std::string const& name);

#endif
