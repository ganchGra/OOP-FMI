#include"stdafx.h"

Student::Student(const unsigned fn, const char* name, const char* adress, const char* telNumber, const char* egn)
	:Person(name, adress, telNumber, egn)
{
	this->m_fn = fn;
}

//Student::~Student()
//{
//	std::cout << "CHAO\n";
//}

unsigned Student::getFN()const {
	return this->m_fn;
}

void Student::printStudentInfo() const
{
	std::cout 
		<<"Student\n"
		<< "FN: " << this->getFN() << std::endl;
	this->printPersonalInformation();
}

std::ostream& operator<<(std::ostream& out, const Student& src)
{
	out << "Student\n"
		<< "FN: " << src.getFN() << std::endl
		<< Person(src);

	return out;
}
