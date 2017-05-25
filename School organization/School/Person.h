#pragma once

#include"stdafx.h"

class Person:public EGN
{
public:
	//I don't want to create obj without value
	//Person();
	Person(const char* name, const char* adress, const char* telNumber, const char* egn);
	Person(const Person& rhs);
	Person& operator=(const Person& rhs);
	~Person();

private:
	char * m_name;
	char * m_adress;
	char * m_telNumber;

private:
	void setPersonData(const char* name, const char* adress, const char* telNumber);
	void setString(char*& dest, const char* source);

public:
	const char * getName() const;
	const char * getAdress() const;
	const char * getTelNumber() const;

	void printPersonalInformation() const;
};

std::ostream& operator<<(std::ostream& out, const Person& src);
