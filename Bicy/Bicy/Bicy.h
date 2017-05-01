#pragma once
#include "bicyDetails.h"

class Bicy
{
public:
	Bicy();
	Bicy(const Bicy& other);
	Bicy& operator=(const Bicy& other);
	~Bicy();

	Bicy& operator+(const BicyDetail& detail);
	Bicy& operator-(const BicyDetail& detail);

	bool operator==(const Bicy& other) const;
	bool operator!=(const Bicy& other) const;
	bool operator<(const Bicy& other) const;
	bool operator<=(const Bicy& other) const;
	bool operator>(const Bicy& other) const;
	bool operator>=(const Bicy& other) const;	

	char& operator[](char * index);

	void setBrand(const char* brand);
	void setDetails(const BicyDetail * detail, size_t numofDetails);

	const char* getBrand() const;
	double getPrice() const;
private:
	char * brand;
	BicyDetail * details;
	size_t numberOfDetails;
	double price;
};
