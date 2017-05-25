#include"stdafx.h"

void Person::setString(char*& dest, const char* src)
{
	if (src)
	{
		if (dest != NULL)
		{
			delete[] dest;
			dest = NULL;
		}

		size_t size = strlen(src) + 1;
		dest = new char[size];
		strcpy_s(dest, size, src);
	}
}
void Person::setPersonData(const char* name, const char* adress, const char* telNumber)
{
	setString(this->m_name, name);
	setString(this->m_adress, adress);
	setString(this->m_telNumber, telNumber);
}
Person::Person(const char* name, const char* adress, const char* telNumber, const char* egn)
	:m_name(NULL), m_adress(NULL), m_telNumber(NULL), EGN(egn)
{
	setPersonData(name, adress, telNumber);
}

Person::Person(const Person& rhs)
	: m_name(NULL),m_adress(NULL),m_telNumber(NULL), EGN(rhs)
{
	setPersonData(rhs.getName(), rhs.getAdress(), rhs.getTelNumber());
}

Person& Person::operator=(const Person& rhs)
{
	if (this != &rhs)
	{
		EGN::EGN(rhs);
		setPersonData(rhs.getName(), rhs.getAdress(), rhs.getTelNumber());
	}
	return *this;
}
Person::~Person()
{
	delete[] m_name;
	delete[] m_adress;
	delete[] m_telNumber;
}

///
///
///
const char * Person::getName() const
{
	return this->m_name;
}
const char * Person::getAdress() const
{
	return this->m_adress;
}
const char * Person::getTelNumber() const
{
	return this->m_telNumber;
}
void Person::printPersonalInformation() const
{
	std::cout
		<< "Name: " << this->getName() << std::endl
		<< "Adress: " << this->getAdress() << std::endl
		<< "Telefon number: " << this->getTelNumber() << std::endl;
	this->printEGN();

}

std::ostream& operator<<(std::ostream& out, const Person& src)
{
	out
		<< "Name: " << src.getName() << std::endl
		<< "Adress: " << src.getAdress() << std::endl
		<< "Telefon number: " << src.getTelNumber() << std::endl;

	out<<EGN(src);

	return out;
}