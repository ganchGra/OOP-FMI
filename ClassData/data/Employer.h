#ifndef EMPLOYER_H_INCLUDE
#define EMPLOYER_H_INCLUDE
#include"Date.h"

class Employer
{
private:
	char * name;
	const Date dateOfBirth;

	Date startDate;
	char * position;
	double salary;
	void setNewValue(char*&, const char*);
	Employer& operator=(const Employer&);

public:
	Employer(const char* name, const Date& dateOfBirth,
		const Date& startDate, const char * position,
		double salary);
	Employer(const Employer&);
	~Employer();

	void setName(const char*);
	void setPosition(const char*);
	void setSalary(double);

	const char * getName() const;
	const Date getData() const;
	const char * getPosition() const;

};

#endif// EMPLOYER_H_INCLUDE
