#include "Date.hpp"
#include <algorithm>
#include <string>

Date::Date() {}

bool Date::validYear() {
  if (_year < 1000 || _year > 9999)
    return false;
  return true;
}

bool Date::validMonth() {
  if (_month > 12)
    return false;
  return true;
}

bool Date::validDay() {
  unsigned int maxDays;

  if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 ||
      _month == 10 || _month == 12)
    maxDays = 31;
  else if (_month == 2) {
    if (_year % 4 == 0)
      maxDays = 29;
    else
      maxDays = 28;
  } else
    maxDays = 29;
  if (_day > maxDays)
    return false;
  return true;
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
  _year = year;
  _month = month;
  _day = day;
  if (!validYear())
    throw Date::YearMustBeWithin1000And9999();
  if (!validMonth())
    throw Date::MonthMustBeWithin1And12();
  if (!validDay())
    throw Date::DayMustBeInRange();
}

Date::Date(std::string yymmdd) {}

Date::Date(const Date &other) {
  _year = other._year;
  _month = other._month;
  _day = other._day;
}

Date &Date::operator=(const Date &other) {
  if (this != &other) {
    _year = other._year;
    _month = other._month;
    _day = other._day;
  }
  return *this;
}

Date::~Date() {}

const char *Date::YearMustBeWithin1000And9999::what() const throw() {
  return "Year must be within 1000 and 9999";
}

const char *Date::MonthMustBeWithin1And12::what() const throw() {
  return "Month must be within 1 and 12";
}

const char *Date::DayMustBeInRange::what() const throw() {
  return "Day must be in range (1 - 28/29/30/31)";
}
