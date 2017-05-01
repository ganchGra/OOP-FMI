#include "Bicy.h"
#include <iostream>

Bicy::Bicy()
{
	setBrand(NULL);
	//setDetails
}

Bicy::~Bicy()
{
	delete[] brand;
	delete[] details;
}

Bicy& Bicy::operator=(const Bicy& other)
{
	if (this != &other)
	{
		this->setBrand(other.brand);
		this->setDetails(other.details,other.numberOfDetails);
	}
}

Bicy::Bicy(const Bicy& other)
{
	this->setBrand(other.brand);
	this->setDetails(other.details, other.numberOfDetails);
}

Bicy& Bicy::operator+(const BicyDetail& detail)
{

}
Bicy& Bicy::operator-(const BicyDetail& detail)
{

}

bool Bicy::operator==(const Bicy& other) const
{
	if (this->getBrand() == other.getBrand() && this->getPrice() == other.getPrice())
		return true;

	return false;
}
bool Bicy::operator!=(const Bicy& other) const
{
	if (this == &other) return false;

	return true;
}
bool Bicy::operator<(const Bicy& other) const
{

}
bool Bicy::operator<=(const Bicy& other) const
{

}
bool Bicy::operator>(const Bicy& other) const
{

}
bool Bicy::operator>=(const Bicy& other) const
{

}

char& Bicy::operator[](char * index)
{

}

void Bicy::setBrand(const char* brand)
{
	if (brand == NULL)
	{
		this->brand = NULL;
		return;
	}
	size_t len = strlen(brand) + 1;
	this->brand = new char[len];
	strcpy_s(this->brand, len, brand);
}
void Bicy::setDetails(const BicyDetail * detail, size_t numofDetails)
{
	double price = 0;
	this->numberOfDetails = numofDetails;
	
	if (numofDetails == 0)
		return;
	
	for (size_t i = 0; i < numofDetails; i++)
	{
		this->details[i] = detail[i];
		price += detail[i].getPrice();
	}
	this->price = price * 1.5;
}
const char* Bicy::getBrand() const
{
	return ((this->brand == NULL) ? "" : this->brand);
}
double Bicy::getPrice() const
{
	return this->price;
}