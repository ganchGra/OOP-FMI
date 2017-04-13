#include"car.h"
#include<iostream>

//Static count object data
int Car::countLamborgini = 0;
int Car::countMercedes = 0;
int Car::countPagani = 0;
int Car::countBugatti = 0;

//Total power to the all object
int Car::totalPower = 0;

//Defaut constructor
Car::Car()
{
	brand = NULL;
	id = -1;
	power = 0;
}

//Initializes a new Car object with specific values 
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

//Destructor
Car::~Car()
{
	if (this->id == 0) countLamborgini -= 1;
	if (this->id == 1) countMercedes -= 1;
	if (this->id == 2) countPagani -= 1;
	if (this->id == 3) countBugatti -= 1;
	totalPower -= this->power;
}
//Set id, brand and power of the car
void Car::setCar(const int id)
{
	this->id = id;
	switch (id)
	{
	case 0:
		this->brand = "Lamborgini Murcielago";
		this->power = 670;
		this-> countLamborgini += 1;
		break;
	case 1:
		this->brand = "Mercedes-AMG";
		this->power = 503;
		this->countMercedes += 1;
		break;
	case 2:
		this->brand = "Pagani Zonda R";
		this->power = 740;
		this->countPagani += 1;
		break;
	case 3:
		this->brand = "Bugatti Veyron";
		this->power = 1020;
		this->countBugatti += 1;
		break;
	default:
		brand = NULL;
		power = 0;
	}
	totalPower += this->power;
}

//Getting function
const char * Car::getBrand() const
{
	return (this->brand == NULL) ? "" : this->brand;	
}

const int Car::getId() const
{
	return this->id;
}

const int Car::getPower() const
{
	return this->power;
}
const int Car::getTotalPower()
{
	return totalPower;
}
void Car::getBrandType(const int id)
{
	switch (id)
	{
	case 0:
		std::cout << "Lamborgini Murcielago";
		break;
	case 1:
		std::cout << "Mercedes-AMG";
		break;
	case 2:
		std::cout << "Pagani Zonda R";
		break;
	case 3:
		std::cout << "Bugatti Veyron";
		break;
	default:
		std::cout << "This car not exist...";
	}
}
//Print car information
void Car::printCar() const
{
	if (this->getBrand() == NULL) return;
	std::cout << "Brand: " << this->getBrand();
	std::cout << std::endl;
	std::cout << "Id number: " << this->getId() << std::endl;
	std::cout << "Power: " << this->getPower() << std::endl;
}