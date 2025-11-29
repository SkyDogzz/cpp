#ifndef FIXED_HPP
#define FIXED_HPP

#include <iosfwd>

class Fixed {
private:
	int raw;
	static int const frac = 8;

public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);

#endif
