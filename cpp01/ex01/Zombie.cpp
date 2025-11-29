#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie() : _name("Nameless") {
	std::cout << "Zombie " << _name << " default constructor called" << std::endl;
}

Zombie::Zombie(std::string const& name) : _name(name) {
	std::cout << "Zombie " << _name << " constructor called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destructor called" << std::endl;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string const& name) {
	_name = name;
}
