#include "Employer.h"
#include "Date.h"
#include<iostream>

//TODO

void Employer::setNewValue(char*& dest, const char* src)
{
	if (!src)
	{
		delete[] dest;
		dest = NULL;

		return;
	}
	size_t lenght = strlen(src) + 1;
	char * buffer = new char[lenght];
	strcpy_s(buffer, lenght, src);

	delete[] dest;
	dest = buffer;
}
void Employer::setName(const char* name)
{
	setNewValue(this->name, name);
}

void Employer::setPosition(const char* position)
{
	setNewValue(this->position, position);
}

void Employer::setSalary(double salary)
{
	if (salary < 0)
		throw "Invalid value!";

	this->salary = salary;
	
}
Employer::Employer(const char* name, const Date& dateOfBirth,
	const Date& startDate, const char * position,
	double salary)
	:name(NULL), position(NULL), dateOfBirth(dateOfBirth)
{
	setName(name);
	//this->dateOfBirth = dateOfBirth;
	this->startDate = startDate;
	setPosition(position);
	setSalary(salary);
}
Employer::Employer(const Employer& other)
	:name(NULL), position(NULL),dateOfBirth(dateOfBirth)
{
	setName(other.name);
	setPosition(other.position);
	setSalary(other.salary);
}

Employer::~Employer()
{
	delete[] this->name;
	delete[] this->position;
}
const char * Employer::getName() const
{
	return (this->name == NULL) ? "" : this->name;
}
const char * Employer::getPosition() const
{
	return (this->position == NULL) ? "" : this->position;
}
const Date Employer::getData() const
{
	dateOfBirth.print();
}
