#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
private:
	void debug() const;
	void info() const;
	void warning() const;
	void error() const;

public:
	void complain(std::string level) const;
};

#endif
