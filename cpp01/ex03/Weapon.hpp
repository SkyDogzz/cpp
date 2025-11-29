#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string _type;

public:
	Weapon(std::string const& type);

	void setType(std::string const& type);
	std::string const& getType() const;
};

#endif
