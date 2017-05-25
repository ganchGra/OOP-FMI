#pragma once

class EGN
{
private:
	char egn[10];
	int year;
	int month;
	int day;
	int region;
	char gender;
	int chekNum;
	///
	///check if the EGN is valid
	///and set the value of all integer variables
	///
	const bool isValid(const char* egn) const;
	void set_YEAR_MONTH_DAY(const char * egn);
	void set_REGION(const char * egn);
	void set_GENDER(const char * egn);
	void set_CHECK_NUM(const char * egn);

	void setEGN(const char* egn);
public:
	//I don't want to create obj without value
	//EGN();

	///
	///Create obj with inizialization value
	///
	EGN(const char * egn);

	const char* getEGN() const;  
	int getYear()const;
	int getMonth()const;
	int getDayOfBirth() const;
	char getGender() const;

	const void printRegion() const;
	const void printBirthday() const;
	const void printGender() const;
	const void printEGN() const;
};

std::ostream& operator<<(std::ostream& out, const EGN& src);