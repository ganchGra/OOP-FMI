#ifndef EGN_H_INCLUDE
#define EGN_H_INCLUDE

class EGN
{
private:
	char allNum[10];
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
	const bool isValid(const char * egn) const;
	void set_YEAR_MONTH_DAY(const char * egn);
	void set_REGION(const char * egn);
	void set_GENDER(const char * egn);
	void set_CHECK_NUM(const char * egn);
	
public:
	EGN();
	EGN(const char * egn);

	//char* getEGN() const;  //TODO 
	int getYear()const;
	int getMonth()const;
	int getDay() const;
	char getGender() const;

	const void printRegion() const;
	const void printBirthday() const;
	const void printGender() const;
	
	void setEGN(const char* egn);
};

#endif //EGN_H_INCLUDE
