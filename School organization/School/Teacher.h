#pragma once
#include"stdafx.h"

class Teacher:public Person
{
public:
	//I don't want to create obj without value
	//Teacher();
	//~Teacher();

	Teacher(const unsigned numberOfCourse, const char* name, const char* adress, const char* telNumber, const char* egn);
private:
	unsigned m_numberOfCourse;

public:
	unsigned getNumberOfCourse()const;
	void printTeacherInformation() const;
};

