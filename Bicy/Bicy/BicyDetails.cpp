#include "bicyDetails.h"
#include<iostream>

///
///Set bicy details
///
void BicyDetail::setType(const char* type)
{
	this->type = NULL;
	if (type != NULL)
	{
		size_t len = strlen(type) + 1;
		this->type = new char[len];
		strcpy_s(this->type, len, type);
	}	
}
void BicyDetail::setPrice(const int price)
{
	this->price = price;
}
void BicyDetail::setQuality(const int quality)
{
	if (quality < 1 || quality > 3)
	{
		throw "Invalid quality";
	}
	this->quality = quality;
}
///
///END set details
///
BicyDetail ::BicyDetail(const char* type, int price, int quality)
{
	setType(type);
	setPrice(price);
	setQuality(quality);
}

BicyDetail::BicyDetail()
{
	setType(NULL);
	setPrice(0);
	setQuality(1);
}
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
///Getting func
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
void BicyDetail::Print()
{
	std::cout
		<< this->getType()  << "\; "
		<< this->getPrice() << "euro\; "
		<< this->getQuality() << "\;" << std::endl;
}