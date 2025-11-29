#include "Harl.hpp"

#include <cctype>
#include <iostream>

std::string toUpper(std::string value) {
	for (std::string::size_type i = 0; i < value.size(); ++i) {
		value[i] = static_cast<char>(std::toupper(value[i]));
	}
	return value;
}

void Harl::debug() const {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup "
	             "burger. "
	             "I really do!"
	          << std::endl;
}

void Harl::info() const {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough "
	             "bacon in my "
	             "burger! If you did, I wouldn't be asking for more!"
	          << std::endl;
}

void Harl::warning() const {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years "
	             "whereas you "
	             "started working here just last month."
	          << std::endl;
}

void Harl::error() const {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string const& level) const {
	typedef void (Harl::*Complaint)() const;
	static const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	static const Complaint handlers[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string normalized = toUpper(level);
	for (int i = 0; i < 4; ++i) {
		if (normalized == levels[i]) {
			(this->*handlers[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
