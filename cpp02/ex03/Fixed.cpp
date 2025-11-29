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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void Fixed::setRawBits(int const value) {
	this->raw = value;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->raw) / (1 << frac);
}

int Fixed::toInt(void) const {
	return this->raw >> frac;
}

bool Fixed::operator>(const Fixed& rhs) const {
	return this->raw > rhs.raw;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->raw < rhs.raw;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->raw >= rhs.raw;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->raw <= rhs.raw;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->raw == rhs.raw;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->raw != rhs.raw;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->raw + rhs.raw);
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->raw - rhs.raw);
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	long product = static_cast<long>(this->raw) * static_cast<long>(rhs.raw);
	result.setRawBits(static_cast<int>(product >> frac));
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	long numerator = static_cast<long>(this->raw) << frac;
	result.setRawBits(static_cast<int>(numerator / rhs.raw));
	return result;
}

Fixed& Fixed::operator++() {
	this->raw += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->raw += 1;
	return temp;
}

Fixed& Fixed::operator--() {
	this->raw -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->raw -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs <= rhs)
		return lhs;
	return rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	if (lhs <= rhs)
		return lhs;
	return rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	if (lhs >= rhs)
		return lhs;
	return rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	if (lhs >= rhs)
		return lhs;
	return rhs;
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed) {
	return ostream << fixed.toFloat();
}
