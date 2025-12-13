#include "Date.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
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

bool containOnlyNumbers(char *str) {
  while (*str) {
    if (!std::isdigit(*str))
      return false;
    str++;
  }
  return true;
}

Date::Date(std::string yymmdd) {
  const char *del = "-";

  std::string::difference_type n =
      std::count(yymmdd.begin(), yymmdd.end(), '-');
  if (n != 2)
    throw Date::DateFormatNotValid();
  char *t = strtok(const_cast<char *>(yymmdd.data()), del);
  if (t == NULL || !containOnlyNumbers(t))
    throw Date::DateFormatNotValid();
  _year = atoi(t);
  t = strtok(NULL, del);
  if (t == NULL || !containOnlyNumbers(t))
    throw Date::DateFormatNotValid();
  _month = atoi(t);
  t = strtok(NULL, del);
  if (t == NULL || !containOnlyNumbers(t))
    throw Date::DateFormatNotValid();
  _day = atoi(t);
  t = strtok(NULL, del);
  if (t != NULL)
    throw Date::DateFormatNotValid();
  if (!validYear())
    throw Date::YearMustBeWithin1000And9999();
  if (!validMonth())
    throw Date::MonthMustBeWithin1And12();
  if (!validDay())
    throw Date::DayMustBeInRange();
}

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

bool Date::operator>(const Date &rval) const {
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

bool Date::operator<(const Date &rval) const {
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

const char *Date::YearMustBeWithin1000And9999::what() const throw() {
  return "Year must be within 1000 and 9999";
}

const char *Date::MonthMustBeWithin1And12::what() const throw() {
  return "Month must be within 1 and 12";
}

const char *Date::DayMustBeInRange::what() const throw() {
  return "Day must be in range (1 - 28/29/30/31)";
}

const char *Date::DateFormatNotValid::what() const throw() {
  return "Date format not valid: yyyy-mm-dd";
}
