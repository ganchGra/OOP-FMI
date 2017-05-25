#include"stdafx.h"

Teacher::Teacher(const unsigned numberOfCourse, const char* name, const char* adress, const char* telNumber, const char* egn)
	:Person(name, adress, telNumber, egn)
{
	this->m_numberOfCourse = numberOfCourse;
}

unsigned Teacher::getNumberOfCourse()const
{
	return this->m_numberOfCourse;
}

void Teacher::printTeacherInformation() const
{
	std::cout << "Teacher\n";
	this->printPersonalInformation();
	std::cout << "Number of courses: " << this->m_numberOfCourse << std::endl;
}