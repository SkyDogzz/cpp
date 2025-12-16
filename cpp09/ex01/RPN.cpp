#include "RPN.hpp"

#include <algorithm>
#include <cstring>
#include <string>

RPN::RPN(std::string expression) : _res(0) {
	verifExpression(expression);
	constructList(expression);
	verifList();
}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	return *this;
	(void)other;
}

RPN::~RPN() {}

static bool contains_bad_char(std::string& s, std::string set) {
	const char* consted = static_cast<const char*>(s.data());

	while (*consted) {
		if (set.find(*consted) == std::string::npos)
			return true;
		consted++;
	}
	return false;
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

static bool multipleSpaces(std::string& s) {
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
void RPN::verifExpression(std::string& expression) {
	std::string set = "0123456789 -+*/";

	if (contains_bad_char(expression, set))
		throw RPN::ContainsBadCharException();

	if (multipleSpaces(expression))
		throw RPN::MultipleSpaceException();

	if (expression.at(expression.size() - 1) == ' ')
		throw RPN::MultipleSpaceException();
}

void RPN::constructList(std::string& expression) {
	const char* del = " ";
	char*		expr = const_cast<char*>(expression.data());

	char* t = strtok(expr, del);
	while (t != NULL) {
		_ope.push_back(std::string(t));
		t = strtok(NULL, del);
	}
}

const char* RPN::Number::ContainsBadCharException::what() const throw() {
	return "number contain bad char";
}

const char* RPN::Number::MinusProblemException::what() const throw() {
	return "multiple or misplaced minus";
}

const char* RPN::Operand::NotAnOperandException::what() const throw() {
	return "not an operand";
}

static void isANumber(std::string s) {
	int minus = std::count(s.begin(), s.end(), '-');

	if (contains_bad_char(s, "-0123456789"))
		throw RPN::Number::ContainsBadCharException();
	if (minus > 1 || (minus && s[0] != '-'))
		throw RPN::Number::MinusProblemException();
}

static void isAnOperand(std::string s) {
	if (s.size() != 1)
		throw RPN::Operand::NotAnOperandException();
	if (contains_bad_char(s, "+-/*"))
		throw RPN::Operand::NotAnOperandException();
}

void RPN::verifList() {
	if (_ope.size() % 2 == 0)
		throw RPN::EvenNumberOfOpeException();
	std::list<std::string>::iterator it = _ope.begin();
	isANumber(*it);
	it++;
	if (it == _ope.end())
		return;
	isANumber(*it);
	it++;
	isAnOperand(*it);
	it++;
	while (it != _ope.end()) {
		isANumber(*it);
		it++;
		isAnOperand(*it);
		it++;
	}
}

int RPN::resolve(void) {
	std::list<std::string>::iterator it = _ope.begin();
	isANumber(*it);
	_res = atoi((*it).data());
	it++;
	while (it != _ope.end()) {
		int operan = atoi((*it).data());
		it++;
		char operat = (*it).at(0);
		it++;

		if (operat == '-')
			_res -= operan;
		else if (operat == '+')
			_res += operan;
		else if (operat == '*')
			_res *= operan;
		else if (operat == '/')
			_res /= operan;
	}
	return _res;
}
