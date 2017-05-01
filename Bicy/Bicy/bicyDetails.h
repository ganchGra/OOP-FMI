//#pragma once
#ifndef BICYDETAILS_INCLUDE_H
#define BICYDETAILS_INCLUDE_H


class BicyDetail
{
public:
	BicyDetail();
	BicyDetail(const char* type, int price, int quality);
	BicyDetail(const BicyDetail& other);
	BicyDetail& operator=(const BicyDetail& other);
	~BicyDetail();

	void setType(const char* type);
	void setPrice(const int price);
	void setQuality(const int quality);

	const char* getType() const;
	int getPrice() const;
	int getQuality() const;


	void Print();
private:
	char * type;
	int price;
	int quality;
};


#endif // !BICYDETAILS_INCLUDE_H
