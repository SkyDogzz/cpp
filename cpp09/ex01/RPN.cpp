#include "RPN.hpp"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

bool multipleSpaces(std::string s);
bool isAnOperator(std::string s);
bool isAnOperand(std::string s);
bool contains_bad_char(std::string& s, std::string set);

RPN::RPN(std::string expression) {
	if (multipleSpaces(expression))
		throw RPN::MultipleSpaceException();
	else if (contains_bad_char(expression, "0123456789 -+/*"))
		throw RPN::MultipleSpaceException();
	char*		expr = const_cast<char*>(expression.data());
	const char* del = " ";

	char* t = strtok(expr, del);
	if (!t)
		throw RPN::NoOperandToConsumeException();
	_operand.push_back(atoi(t));
	if (!isAnOperand(static_cast<std::string>(t))) {
		throw RPN::NoOperandToConsumeException();
	}
	t = strtok(NULL, del);
	while (t != NULL) {
		if (isAnOperand(t)) {
			_operand.push_back(atoi(t));
		} else if (isAnOperator(t)) {
			if (_operand.size() < 2)
				throw RPN::NoOperandToConsumeException();
			long op2 = _operand.back();
			_operand.pop_back();
			long op1 = _operand.back();
			_operand.pop_back();
			if (op2 == 0)
				throw RPN::DivideByNothingException();
			if (strcmp(t, "+") == 0)
				_operand.push_back(op1 + op2);
			else if (strcmp(t, "-") == 0)
				_operand.push_back(op1 - op2);
			else if (strcmp(t, "*") == 0)
				_operand.push_back(op1 * op2);
			else if (strcmp(t, "/") == 0)
				_operand.push_back(op1 / op2);
		} else
			throw RPN::NorOperandOperatorException();
		t = strtok(NULL, del);
	}
}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	return *this;
	(void)other;
}

RPN::~RPN() {}

bool contains_bad_char(std::string& s, std::string set) {
	const char* consted = static_cast<const char*>(s.data());

	while (*consted) {
		if (set.find(*consted) == std::string::npos)
			return true;
		consted++;
	}
	return false;
}

const char* RPN::NorOperandOperatorException::what() const throw() {
	return "nor operand or operator";
}

const char* RPN::DivideByNothingException::what() const throw() {
	return "attempt to divide by 0";
}

const char* RPN::NoOperandToConsumeException::what() const throw() {
	return "expr need operand to consume";
}

const char* RPN::ContainsBadCharException::what() const throw() {
	return "contains bad characters";
}

const char* RPN::MultipleSpaceException::what() const throw() {
	return "multiple spaces";
}

const char* RPN::EvenNumberOfOpeException::what() const throw() {
	return "even numbers of ope";
}
const char* RPN::NotComsumedOperandException::what() const throw() {
	return "not all operands were comsumed";
}

bool multipleSpaces(std::string s) {
	const char* consted = (s.c_str());

	bool lastIsSpace = false;
	while (*consted) {
		if (lastIsSpace && *consted == ' ')
			return true;
		if (*consted == ' ')
			lastIsSpace = true;
		else
			lastIsSpace = false;
		consted++;
	}
	return false;
}

bool isAnOperand(std::string s) {
	int minus = std::count(s.begin(), s.end(), '-');

	if (contains_bad_char(s, "-0123456789"))
		return false;
	if (minus > 1 || (minus && s[0] != '-') || (minus && s.size() == 1))
		return false;
	return true;
}

bool isAnOperator(std::string s) {
	if (s.size() != 1)
		return false;
	if (contains_bad_char(s, "+-/*"))
		return false;
	return true;
}

long RPN::getRes(void) {
	if (_operand.size() != 1)
		throw RPN::NotComsumedOperandException();
	return *_operand.begin();
}
