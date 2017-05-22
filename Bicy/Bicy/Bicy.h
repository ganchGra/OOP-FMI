#pragma once
#include "bicyDetails.h"

class Bicy
{
public:
	Bicy();
	Bicy(const char* brand, const BicyDetail * details,const size_t numberOfDetails);
	Bicy(const Bicy& other);
	Bicy& operator=(const Bicy& other);
	~Bicy();

	///
	///Add detail to the bicy
	///
	Bicy& operator+(const BicyDetail& detail);

	///
	///Remove detail from the bicy
	///
	Bicy& operator-(const BicyDetail& detail);
	
	/*Compare the price and the brand of two bicycle*/
	///Are equal
	bool operator==(const Bicy& other) const;
	///Are different
	bool operator!=(const Bicy& other) const;

	/*Compare the number of the top quality parts between two bicycles*/
	bool operator<(const Bicy& other) const;
	bool operator<=(const Bicy& other) const;
	bool operator>(const Bicy& other) const;
	bool operator>=(const Bicy& other) const;	

	//Return the pointer to the part with the corresponding name, if exist. If not return NULL.
	//TODO???
	const BicyDetail* operator[](const char * index) const;

	///
	///Set bicycle information
	///
	void setBrand(const char* brand);
	void setDetails(const BicyDetail * detail, size_t numofDetails);

	///
	///Get bicycle information
	///
	const char* getBrand() const;
	const BicyDetail * getDetails() const;
	double getPrice() const;
	size_t getNumOfDetail() const;
	size_t getNumPrimeDetails() const;

	///
	///Print bicycle infotmation
	///
	void print() const;

private:
	char * brand;
	BicyDetail * details;
	size_t numberOfDetails;
	double price;

	/* The price is the sum of the prices of the singol detail that build it,
	* multiplied by 1.5. */
	void setPrice();
	///
	///Help function to swap and setprice to the bike
	///
	void swapDetails(BicyDetail *& dest, BicyDetail *&src, const size_t numofDetails);
};
