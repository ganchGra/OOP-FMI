#include "EGN.h"
#include<iostream>

///
///Defaut constructor
///
EGN::EGN()
{
	year = 1900;
	month = 1;
	day = 1;
	region = 0;
	gender = 'E';
	chekNum = 0;
}
///
///Create object 
///
EGN::EGN(const char * egn)
{
	setEGN(egn);
}

///
///Check if the EGN is valid and set the value
///
const bool EGN::isValid(const char * egn) const
{
	///
	///check the size SIZE_EGN = 10
	///
	size_t SIZE_EGN = strlen(egn);
	if (SIZE_EGN != 10)
		return false;

	///
	///check if all is numbers
	///
	for (size_t i = 0; i < SIZE_EGN; i++)
	{
		if (egn[i] <'0' || egn[i] >'9')
			return false;
	}

	///
	///check if the first four numbers are zero
	///
	int sum = 0;
	for (size_t i = 0; i <= 4; i++)
		sum += egn[i] - '0';
	if (sum == 0) return false;

	///
	///Take all elements
	///
	int isValidYear = (egn[0] - '0') * 10 + (egn[1] - '0');
	int isValidMonth = (egn[2] - '0') * 10 + (egn[3] - '0');
	int isValidDay = (egn[4] - '0') * 10 + (egn[5] - '0');
	int isValidCheckNum = (egn[9] - '0');

	///
	///check the last number
	///
	int sumWeight =
		(egn[0] - '0') * 2 +
		(egn[1] - '0') * 4 +
		(egn[2] - '0') * 8 +
		(egn[3] - '0') * 5 +
		(egn[4] - '0') * 10 +
		(egn[5] - '0') * 9 +
		(egn[6] - '0') * 7 +
		(egn[7] - '0') * 3 +
		(egn[8] - '0') * 6;
	int resChecknum = sumWeight % 11;
	resChecknum = (resChecknum >= 10) ? 0 : resChecknum;
	if (resChecknum != isValidCheckNum)	return false;

	///
	///Check and modificate the month
	///

	if (isValidMonth < 0 || isValidMonth > 52) return false;

	//when the year is between 1800 and 1899
	if (isValidMonth >= 21 && isValidMonth <= 32)
		isValidMonth = isValidMonth - 20;
	
	//when the year is between 2000 and 2099
	else if (isValidMonth >= 41 && isValidMonth <= 52)
		isValidMonth = isValidMonth - 40;
	
	///
	///Check the days
	///
	switch (isValidMonth)
	{
		//month with 31 days
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (isValidDay < 1 || isValidDay > 31)
			return false;

		//month with 30 days
	case 4: case 6: case 9: case 11:
		if (isValidDay < 1 || isValidDay > 30)
			return false;

		//month february
	case 2:
		bool isLeapYear = ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));

		if ((isValidDay < 1 || isValidDay > 28) && !isLeapYear)
			return false;

		else if (isValidDay < 1 && isValidDay > 29 && isLeapYear)
			return false;

	}
	return true;
}

///
///Set EGN into new object whitout value
///
void EGN::setEGN(const char* egn)
{
	if (isValid(egn))
	{
		strcpy(allNum, egn);
		set_YEAR_MONTH_DAY(egn);
		set_REGION(egn);
		set_GENDER(egn);
		set_CHECK_NUM(egn);
	}
	else
	{
		std::cout << "WRONG EGN!\n";
		return;
	}
}

///
/// SET ALL ELEMENTS 
///
void EGN::set_YEAR_MONTH_DAY(const char * egn)
{
	int setYear =(egn[0] - '0') * 10 + (egn[1] - '0');
	int setMonth = (egn[2] - '0') * 10 + (egn[3] - '0');
	int setDay = (egn[4] - '0') * 10 + (egn[5] - '0');
	//when the year is between 1900 and 1999
	if (setMonth >= 1 && setMonth <= 12)
	{
		this->year = 1900 + setYear;
		this->month = setMonth;

	}
	//when the year is between 1800 and 1899
	else if (setMonth >= 21 && setMonth <= 32)
	{
		this->year = 1800 + setYear;
		this->month = setMonth - 20;
	}
		
	//when the year is between 2000 and 2099
	else if (setMonth >= 41 && setMonth <= 52)
	{
		this->year = 2000 + setYear;
		this->month = setMonth - 40;
	}
	this->day = setDay;
}

void EGN::set_REGION(const char * egn)
{
	int setRegion = (egn[6] - '0') * 100 + (egn[7] - '0') * 10 + (egn[8] - '0');
	this->region = setRegion;
}
void EGN::set_GENDER(const char * egn)
{
	int setGenderNum =(egn[8] - '0');
	this->gender = ((setGenderNum % 2) == 0) ? 'm' : 'f';
}
void EGN::set_CHECK_NUM(const char * egn)
{
	int setCHECK_NUM = (egn[9] - '0');
	this->chekNum = setCHECK_NUM;
}

///
/// ALL GETTING FUNCTION
///
int EGN::getYear()const
{
	return year;	
}
int EGN::getMonth()const
{
	return month;
	
}
int EGN::getDay() const
{
	return day ;
}

char EGN::getGender() const
{
	return gender;
}

//char* EGN::getEGN() const
//{
//	//TODO
//  // Make copy 
//	//return allNum;  
//}

///
///PRINT FUNCTIONS
///
const void EGN::printRegion() const
{
	if (isValid(this->allNum))
	{
		int regionNum = this->region;
		if (regionNum >= 0 && regionNum <= 43) std::cout << "Blagoevgrad";
		else if (regionNum >= 44 && regionNum <= 93) std::cout << "Burgas";
		else if (regionNum >= 94 && regionNum <= 139) std::cout << "Varna";
		else if (regionNum >= 140 && regionNum <= 169) std::cout << "Veliko Tarnovo";
		else if (regionNum >= 170 && regionNum <= 183) std::cout << "Vidin";
		else if (regionNum >= 184 && regionNum <= 217) std::cout << "Vraca";
		else if (regionNum >= 218 && regionNum <= 233) std::cout << "Gabrovo";
		else if (regionNum >= 234 && regionNum <= 281) std::cout << "Kurdjali";
		else if (regionNum >= 282 && regionNum <= 301) std::cout << "Kiustendil";
		else if (regionNum >= 302 && regionNum <= 319) std::cout << "Lovech";
		else if (regionNum >= 320 && regionNum <= 341) std::cout << "Montana";
		else if (regionNum >= 342 && regionNum <= 377) std::cout << "Pazardjik";
		else if (regionNum >= 378 && regionNum <= 395) std::cout << "Pernik";
		else if (regionNum >= 396 && regionNum <= 435) std::cout << "Pleven";
		else if (regionNum >= 436 && regionNum <= 501) std::cout << "Plovdiv";
		else if (regionNum >= 502 && regionNum <= 527) std::cout << "Razgrad";
		else if (regionNum >= 528 && regionNum <= 555) std::cout << "Ruse";
		else if (regionNum >= 556 && regionNum <= 575) std::cout << "Silistra";
		else if (regionNum >= 576 && regionNum <= 601) std::cout << "Sliven";
		else if (regionNum >= 602 && regionNum <= 623) std::cout << "Smolqn";
		else if (regionNum >= 624 && regionNum <= 721) std::cout << "Sofia-city";
		else if (regionNum >= 722 && regionNum <= 751) std::cout << "Sofia-province";
		else if (regionNum >= 752 && regionNum <= 789) std::cout << "Stara Zagora";
		else if (regionNum >= 790 && regionNum <= 821) std::cout << "Dobrich";
		else if (regionNum >= 822 && regionNum <= 843) std::cout << "Targovishte";
		else if (regionNum >= 844 && regionNum <= 871) std::cout << "Haskovo";
		else if (regionNum >= 872 && regionNum <= 903) std::cout << "Shumen";
		else if (regionNum >= 904 && regionNum <= 925) std::cout << "Qmbol";
		else if (regionNum >= 926 && regionNum <= 999) std::cout << "Other";

		std::cout << std::endl;
	}
	else
	{
		std::cout << "WRONG EGN!\n";
		return;
	}
}

const void EGN::printBirthday() const
{
	if (isValid(this->allNum))
	{
		std::cout 
			<< this->day << "/"
			<< this->month << "/" 
			<< this->year << std::endl;
	}
	else
	{
		std::cout << "WRONG EGN!\n";
		return;
	}
}
const void EGN::printGender() const
{
	if (isValid(this->allNum))
	{
		char gen = this->gender;
		if (this->gender == 'f')
			std::cout << "Female" << std::endl;
		else
			std::cout << "Male" << std::endl;
	}
	else
	{
		std::cout << "WRONG EGN!\n";
		return;
	}
}

