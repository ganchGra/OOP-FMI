#include "bicyDetails.h"
#include<iostream>

///
///Set bicy details
///
void BicyDetail::setType(const char* type)
{
	if (type != NULL)
	{
		delete[] this->type;
		this->type = NULL;

		size_t len = strlen(type) + 1;
		this->type = new char[len];
		strcpy_s(this->type, len, type);
	}	
}
void BicyDetail::setPrice(const int price)
{
	if (price < 0) 
		throw "Invalid price...";

	this->price = price;
}
void BicyDetail::setQuality(const int quality)
{
	if (quality < 1 || quality > 3)
		throw "Invalid quality...";
	
	this->quality = quality;
}
///END set details

BicyDetail ::BicyDetail(const char* type, int price, int quality)
{
	this->type = NULL;
	setType(type);
	setPrice(price);
	setQuality(quality);
}

BicyDetail::BicyDetail()
	:type(NULL),price(0),quality(1)
{}

BicyDetail::BicyDetail(const BicyDetail& other)
{
	this->setType(other.type);
	this->setPrice(other.price);
	this->setQuality(other.quality);
}
BicyDetail& BicyDetail::operator=(const BicyDetail& other)
{
	if (this != &other)
	{
		this->setType(other.type);
		this->setPrice(other.price);
		this->setQuality(other.quality);
	}
	return *this;
}
BicyDetail::~BicyDetail()
{
	delete[] type;
}

///
///Getting function
///
const char* BicyDetail::getType() const
{
	if (this->type == NULL) return "";
	return this->type;
}
int BicyDetail::getPrice() const
{
	return this->price;
}
int BicyDetail::getQuality() const
{
	return this->quality;
}

///
///Print Bicy detail information
///
void BicyDetail::Print() const
{
	std::cout
		<< this->getType()  << "-"
		<< this->getPrice() << "euro - "
		<<"Quality: "<< this->getQuality()<< std::endl;
}