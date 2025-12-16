#include "Date.hpp"

#include <cstring>
#include <fstream>
#include <memory>

Date::Date() : _full(""), _year(0), _month(0), _day(0) {}

Date::Date(std::string yymmdd) : _full(yymmdd) {
	try {
		if (!Date::validDate(yymmdd, *this))
			return;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << " => " << _full << std::endl;
		_full = "";
	}
}

Date::Date(const Date& other) {
	_full = other._full;
	_year = other._year;
	_month = other._month;
	_day = other._day;
}

Date& Date::operator=(const Date& other) {
	if (this != &other) {
		_full = other._full;
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return *this;
}

Date::~Date() {}

bool Date::validDate(std::string yymmdd, Date& date) {
	if (!Date::validFormat(yymmdd))
		throw Date::BadDateFormat();
	char*		dateOnly = strtok(const_cast<char*>(yymmdd.data()), "|,");
	const char* del = "-";

	char* t = strtok(dateOnly, del);
	if (!t || !(date._year = validYear(atoi(t), date)))
		throw Date::BadYearInput();
	t = strtok(NULL, del);
	if (!t || !(date._month = validMonth(atoi(t), date)))
		throw Date::BadMonthInput();
	t = strtok(NULL, del);
	if (!t || !(date._day = validDay(atoi(t), date)))
		throw Date::BadDayInput();
	t = strtok(NULL, del);
	if (t != NULL)
		throw Date::BadDateFormat();

	return true;
}

static bool contains_bad_char(std::string yymmdd, std::string set) {
	const char* date = static_cast<const char*>(yymmdd.data());

	while (*date) {
		if (set.find(*date) == std::string::npos)
			return true;
		date++;
	}
	return false;
}

bool Date::validFormat(std::string yymmdd) {
	static const std::string set = "0123456789-";

	if (contains_bad_char(yymmdd, set))
		throw Date::BadDateFormat();
	return true;
}

unsigned int Date::validYear(unsigned int year, Date& tmp) {
	if (year < 1000 || year > 9999)
		return 0;
	tmp._year = year;
	return year;
}

unsigned int Date::validMonth(unsigned int month, Date& tmp) {
	if (month > 12)
		return 0;
	tmp._month = month;
	return month;
}

unsigned int Date::validDay(unsigned int day, Date& tmp) {
	unsigned int max = 0;

	if (day == 0)
		return false;

	if (tmp._month == 1 || tmp._month == 3 || tmp._month == 5 || tmp._month == 7 || tmp._month == 8 ||
		tmp._month == 10 || tmp._month == 12)
		max = 31;
	else if (tmp._month == 4 || tmp._month == 6 || tmp._month == 9 || tmp._month == 11)
		max = 30;
	else if (tmp._month == 2) {
		if (tmp._year % 4 == 0) {
			if (tmp._year % 400 == 0)
				max = 29;
			else if (tmp._year % 100 == 0)
				max = 28;
			else
				max = 29;
		} else
			max = 28;
	}

	if (day > max)
		return 0;
	tmp._day = day;
	return day;
}

bool Date::operator>(const Date& rval) const {
	if (_year > rval._year)
		return true;
	else if (_year < rval._year)
		return false;
	else if (_month > rval._month)
		return true;
	else if (_month < rval._month)
		return false;
	else if (_day > rval._day)
		return true;
	else if (_day < rval._day)
		return false;
	return false;
}

bool Date::operator<(const Date& rval) const {
	if (_year < rval._year)
		return true;
	else if (_year > rval._year)
		return false;
	else if (_month < rval._month)
		return true;
	else if (_month > rval._month)
		return false;
	else if (_day < rval._day)
		return true;
	else if (_day > rval._day)
		return false;
	return false;
}

bool Date::operator==(const Date& rval) const {
	if (_year == rval._year && _month == rval._month && _day == rval._day)
		return true;
	return false;
}

bool Date::operator>=(const Date& rval) const {
	return *this > rval || *this == rval;
}

bool Date::operator<=(const Date& rval) const {
	return *this < rval || *this == rval;
}

unsigned int Date::getYear(void) const {
	return _year;
}
unsigned int Date::getMonth(void) const {
	return _month;
}
unsigned int Date::getDay(void) const {
	return _day;
}

const std::string& Date::getFull(void) const {
	return _full;
}

const char* Date::BadDateFormat::what() const throw() {
	return "bad date format";
}
const char* Date::BadYearInput::what() const throw() {
	return "bad year input";
}
const char* Date::BadMonthInput::what() const throw() {
	return "bad month input";
}
const char* Date::BadDayInput::what() const throw() {
	return "bad day input";
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
	return out << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
}
