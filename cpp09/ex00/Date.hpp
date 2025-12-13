#ifndef DATE_HPP
#define DATE_HPP

#include <bits/stdc++.h>
#include <string>

enum month {
  JANUARY = 1,
  FEBRUARY = 2,
  MARCH = 3,
  APRIL = 4,
  MAY = 5,
  JUNE = 6,
  JULY = 7,
  AUGUST = 8,
  SEPTEMBER = 9,
  OCTOBER = 10,
  NOVEMBER = 11,
  DECEMBER = 12
};

class Date {
private:
  unsigned int _year;
  unsigned int _month;
  unsigned int _day;

public:
  Date();
  Date(unsigned int year, unsigned int month, unsigned int day);
  Date(std::string yymmdd);
  Date(const Date &other);
  Date &operator=(const Date &other);
  ~Date();

  class YearMustBeWithin1000And9999 : public std::exception {
  public:
    const char *what() const throw();
  };

  class MonthMustBeWithin1And12 : public std::exception {
  public:
    const char *what() const throw();
  };

  class DayMustBeInRange : public std::exception {
  public:
    const char *what() const throw();
  };

  class DateFormatNotValid : public std::exception {
  public:
    const char *what() const throw();
  };

  bool validYear(void);
  bool validMonth(void);
  bool validDay(void);

  bool operator>(const Date &rval);
};

#endif
