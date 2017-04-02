#include "Date.h"
#include<iostream>

#include<time.h>
#include<cassert>

bool Date::isLeap(unsigned y) const
{
	return (y % 4 == 0) && !(y % 100 == 0 && y % 400 != 0);
}
unsigned Date::daysInMnt(unsigned m, unsigned y) const
{
	assert(m >= 1 && m <= 12);

	static char daytab[12] = { 31, 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
	return daytab[m - 1] + (m == 2 && isLeap(y));
}
bool Date::isValid(unsigned d, unsigned m, unsigned y) const
{
	if (y > 4096) return false;
	if (m == 0 || m > 12) return false;
	if (d == 0 || d > daysInMnt(m, y)) return false;
	
	return true;
}

Date::Date() : day(0), month(0), year(0) 
{
	///Exctract the current date system
	time_t t = time(NULL);
	tm * now = localtime(&t);
	///set the current date 
	setDate(now->tm_mday, 1 + now->tm_mon, 1900 + now->tm_year);
}

Date::Date(unsigned d, unsigned m, unsigned y) : day(0), month(0), year(0)
{
	if (isValid(d, m, y))
		setDate(d, y, m);
	else
		throw "Invalid date!";
	
}
void Date::setDate(unsigned day, unsigned month, unsigned year)
{
	if (isValid(day,month,year))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		std::clog << "Attemp to set bad data: "
			<< day << '/' << month << '/' << year << '\n';
	}
}

void Date::setDay(unsigned newDay)
{
	if (isValid(newDay, getMonth(), getYear()))
		this->day = newDay;
	else
		std::clog << "Attemp to set bad day: " << newDay << '\n';
}

void Date::setMonth(unsigned newMonth)
{
	if (isValid(getDay(), newMonth, getYear()))
		this->month = newMonth;
	else
		std::clog << "Attemp to set bad month: " << newMonth << '\n';
}

void Date::setYear(unsigned newYear)
{
	if (isValid(getDay(), getMonth(), newYear))
		this->year = newYear;
	else
		std::clog << "Attemp to set bad year: " << newYear << '\n';
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::print() const
{
	std::cout 
		<< this->day << '/'
		<< this->month << '/'
		<< this->year << std::endl;
}





