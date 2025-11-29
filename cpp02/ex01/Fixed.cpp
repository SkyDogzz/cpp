#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : raw(i << frac) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : raw(static_cast<int>(roundf(f * (1 << frac)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : raw(fixed.raw) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->raw = fixed.raw;
	return *this;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
	return ostream << fixed.toFloat();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->raw) / (1 << frac);
}

int Fixed::toInt(void) const {
	return this->raw >> frac;
}
