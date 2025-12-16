#ifndef DATE_HPP
#define DATE_HPP

#include <algorithm>
#include <iostream>
#include <string>

class Date {
private:
	std::string	 _full;
	unsigned int _year;
	unsigned int _month;
	unsigned int _day;

public:
	Date();
	Date(std::string yymmdd);
	Date(const Date& other);
	Date& operator=(const Date& other);
	~Date();

	static bool			validDate(std::string yymmdd, Date& date);
	static bool			validFormat(std::string yymmdd);
	static unsigned int validYear(unsigned int year, Date& tmp);
	static unsigned int validMonth(unsigned int month, Date& tmp);
	static unsigned int validDay(unsigned int month, Date& tmp);

	bool operator>(const Date& rval) const;
	bool operator>=(const Date& rval) const;
	bool operator<(const Date& rval) const;
	bool operator<=(const Date& rval) const;
	bool operator==(const Date& rval) const;

	unsigned int	   getYear(void) const;
	unsigned int	   getMonth(void) const;
	unsigned int	   getDay(void) const;
	const std::string& getFull(void) const;

	class BadDateFormat : public std::exception {
		const char* what() const throw();
	};
	class BadYearInput : public std::exception {
		const char* what() const throw();
	};
	class BadMonthInput : public std::exception {
		const char* what() const throw();
	};
	class BadDayInput : public std::exception {
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Date& date);

#endif
