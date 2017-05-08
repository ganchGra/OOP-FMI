#include "Bicy.h"
#include <iostream>

///
///Set bicycle information
///
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
	this->details = new BicyDetail[numberOfDetails];

	if (numofDetails == 0)
		return;

	for (size_t i = 0; i < numofDetails; i++)
		this->details[i] = detail[i];

	setPrice(detail, numofDetails);
}
void Bicy::setPrice(const BicyDetail *detail, size_t numofDetails)
{
	this->price = 0;
	if (detail == NULL) return;
	for (size_t i = 0; i < numberOfDetails; i++)
		this->price += detail[i].getPrice();

	this->price = price * 1.5;
}
//***End set bicycle infotmation***//

///
///Help function to swap and setprice to the bike
///
void Bicy::swapDetails(BicyDetail *& dest, BicyDetail *&src, const size_t numofDetails)
{
	delete[] dest;
	dest = src;
	setPrice(this->details, this->numberOfDetails);
}

///
///Getting function
///
const char* Bicy::getBrand() const
{
	return ((this->brand == NULL) ? "" : this->brand);
}

const BicyDetail* Bicy::getDetails() const
{
	return ((this->details == NULL) ? NULL : this->details);
}

double Bicy::getPrice() const
{
	return this->price;
}

size_t Bicy::getNumOfDetail() const
{
	return this->numberOfDetails;
}

size_t Bicy::getNumPrimeDetails() const
{
	size_t totalPrimeDet = 0;
	size_t totalDetails = this->getNumOfDetail();
	for (size_t i = 0; i <totalDetails; i++)
	{
		if (this->details[i].getQuality() == 1)
			totalPrimeDet++;
	}

	return totalPrimeDet;
}
//***End getting function***//


Bicy::Bicy()
{
	setBrand(NULL);
	setDetails(NULL,0);
}
Bicy::Bicy(const char* brand, const BicyDetail * details, const size_t numberOfDetails)
{
	setBrand(brand);
	setDetails(details, numberOfDetails);
}
Bicy::Bicy(const Bicy& other)
{
	this->setBrand(other.brand);
	this->setDetails(other.details, other.numberOfDetails);
}
Bicy::~Bicy()
{
	delete[] brand;
}

Bicy& Bicy::operator=(const Bicy& other)
{
	if (this != &other)
	{
		this->setBrand(other.brand);
		this->setDetails(other.details,other.numberOfDetails);
	}
	return *this;
}
///
///Add detail to the bicy
///
Bicy& Bicy::operator+(const BicyDetail& detail) 
{
	BicyDetail * buffer = new BicyDetail[this->numberOfDetails+1];
	for (size_t i = 0; i < this->numberOfDetails; i++)
		buffer[i] = this->details[i];
	
	buffer[numberOfDetails] = detail;

	this->numberOfDetails++;
	swapDetails(this->details, buffer, this->numberOfDetails);

	return *this;

}
///
///Remove detail to the bicy
///
Bicy& Bicy::operator-(const BicyDetail& detail)
{
	BicyDetail * buffer = new BicyDetail[this->numberOfDetails - 1];
	size_t position = 0;

	for (size_t i = 0; i < this->numberOfDetails; i++)
	{
		if (this->details[i].getType() != detail.getType())
		{
			buffer[position] = this->details[i];
			position++;
		}
	}
	this->numberOfDetails--;
	swapDetails(this->details, buffer, this->numberOfDetails);

	return *this;
}

/*Compare the price and the brand of two bicycle*/
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

/*Compare the number of the top quality parts between two bicycles*/
bool Bicy::operator<(const Bicy& other) const
{
	if (this->getNumPrimeDetails() < other.getNumPrimeDetails()) 
		return true;

	return false;

}
bool Bicy::operator<=(const Bicy& other) const
{
	return (this < &other) || (this->getNumPrimeDetails() == other.getNumPrimeDetails());
}

bool Bicy::operator>(const Bicy& other) const
{
	return (!(this <= &other));
}

bool Bicy::operator>=(const Bicy& other) const
{
	return (!(this < &other));
}

/*Read README to do it*/
//Return the pointer to the part with the corresponding name, if exist. If not return NULL.
char* Bicy::operator[](const char * index) const
{
	size_t indexLen = strlen(index);
	size_t brandLen = strlen(this->brand);
	if (indexLen > brandLen)
		return NULL;

	//TODO ??

}


///
///Print Bike information
///
void Bicy::print() const
{
	std::cout
		<< "Brand: " << this->getBrand() << std::endl
		<< "Price: " << this->getPrice() << std::endl;
	for (size_t i = 0; i < this->numberOfDetails; i++)
	{
		std::cout << "Detail: ";
		//this->details[i].Print();
		this->getDetails()[i].Print();
	}
}
