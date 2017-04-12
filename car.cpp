#include"car.h"
#include<iostream>

///
///Defaut constructor
///
Car::Car()
{
	brand = NULL;
	id = -1;
	power = 0;
}

///
///Initializes a new Car object with specific values 
///
Car::Car(const int idNum)
{
	if (idNum < 0 || idNum > 3)
	{
		std::cout << "Nonexistent car...";
		return;
	}
	this->id = idNum;;
	setCar(idNum);
}

///
///Copy constructor
///
Car::Car(const Car& c)
{
	this->id = c.getId();
	setCar(c.getId());
}

///
///Set id, brand and power of the car
///
void Car::setCar(const int id)
{
	this->id = id;
	switch (id)
	{
	case 0:
		this->brand = "Lamborgini Murcielago";
		this->power = 670;
		break;
	case 1:
		this->brand = "Mercedes-AMG";
		this->power = 503;
		break;
	case 2:
		this->brand = "Pagani Zonda R";
		this->power = 740;
		break;
	case 3:
		this->brand = "Bugatti Veyron";
		this->power = 1020;
		break;
	default:
		brand = NULL;
		power = 0;
	}
}
///
///Getting function
///
const char * Car::getBrand() const
{
	return (this->brand == NULL) ? "" : this->brand;
		return "";
	
	//size_t len = strlen(this->brand) + 1;
	//char * cpyBrand = new char[len];
	//strcpy_s(cpyBrand, len, this->brand);
	//return cpyBrand;
}

const int Car::getId() const
{
	return this->id;
}

const int Car::getPower() const
{
	return this->power;
}

///
///Print car information
///
void Car::printCar() const
{
	std::cout << "Brand: " << (this->getBrand()) ? this->getBrand() : "";
	std::cout << std::endl;
	std::cout << "Id number: " << this->getId() << std::endl;
	std::cout << "Power: " << this->getPower() << std::endl;
}