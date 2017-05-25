#pragma once
#include"stdafx.h"

class Student:public Person
{
public:
	//I don't want to create obj without value
	//Student();

	Student(const unsigned fn,const char* name, const char* adress, const char* telNumber, const char* egn);
	//~Student();

private:
	unsigned m_fn;

public:
	unsigned getFN()const;
	void printStudentInfo() const;
};

std::ostream& operator<<(std::ostream& out, const Student& src);