#ifndef _DATE_H_INCLUDED_
#define _DATE_H_INCLUDED_

/**
* Type with day of week
*/
enum DayOfWeek
{
	MONDAY,
	TUESDAY,
	WEDNSDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

/**
* Calendar date class
*/
class Date
{
private:
	unsigned day, month, year;

public:
	
	Date();
	Date(unsigned day, unsigned month, unsigned year);
	
	
	///Checking utility function
	bool isValid(unsigned d, unsigned m, unsigned y) const;

	///Utility function to compare two dates
	int compareDates(const Date& date1, const Date& date2) const;

	///
	///Create getting function
	///
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	DayOfWeek getDayOfWeek() const;

	///
	///Set date parameters. If parameters are not valid, the date does not change
	///
	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);
	void setDate(unsigned day, unsigned month, unsigned year);
	
	///Utiliry function to print date
	void print() const;

private:
	///Utility function for leap year
	bool isLeap(unsigned year) const;

	///Utiliry function to get all day in a month
	unsigned daysInMnt(unsigned month, unsigned year) const;
};

#endif //_DATE_H_INCLUDED_