#ifndef RPN_HPP
#define RPN_HPP

#include <cstring>
#include <iostream>
#include <list>
#include <string>

class RPN {
public:
	std::list<long> _operand;

	RPN(std::string expression);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	class ContainsBadCharException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NoOperandToConsumeException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NorOperandOperatorException : public std::exception {
	public:
		const char* what() const throw();
	};

	class MultipleSpaceException : public std::exception {
	public:
		const char* what() const throw();
	};

	class EvenNumberOfOpeException : public std::exception {
	public:
		const char* what() const throw();
	};

	class DivideByNothingException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotComsumedOperandException : public std::exception {
	public:
		const char* what() const throw();
	};

	long getRes(void);
};

#endif
