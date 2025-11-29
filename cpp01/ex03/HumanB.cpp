#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string const& name) : _name(name), _weapon(NULL) {
}

void HumanB::attack() const {
	if (_weapon == NULL) {
		std::cout << _name << " has no weapon to attack with" << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}
