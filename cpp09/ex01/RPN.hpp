#ifndef RPN_HPP
#define RPN_HPP

#include <cstring>
#include <iostream>
#include <list>
#include <string>

class RPN {
public:
	long				   _res;
	std::list<std::string> _ope;

	RPN(std::string expression);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	class ContainsBadCharException : public std::exception {
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

	class Number {
	public:
		class ContainsBadCharException : public std::exception {
		public:
			const char* what() const throw();
		};
		class MinusProblemException : public std::exception {
		public:
			const char* what() const throw();
		};
	};

	class Operand {
	public:
		class NotAnOperandException : public std::exception {
		public:
			const char* what() const throw();
		};
	};

	void verifList(void);
	void constructList(std::string& expression);
	void verifExpression(std::string& expression);
	int	 resolve(void);
};

#endif
