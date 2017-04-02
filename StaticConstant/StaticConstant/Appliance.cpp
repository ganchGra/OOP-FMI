#include"Appliance.h"
#include<iostream>

const double Appliance::VOLTAGE = 220;
const double Appliance::MAX_AMPERAGE = 16;
const double Appliance::MAX_LOAD = Appliance::VOLTAGE * Appliance::MAX_AMPERAGE;

int Appliance::countObject = 0;
double Appliance::currentLoad = 0;

void Appliance::setCategory(const char * category)
{
	if (!category)
	{
		delete[] this->category;
		this->category = NULL;

		return;
	}

	size_t lenght = strlen(category) + 1;
	char* buffer = new char[lenght];
	strcpy_s(buffer, lenght, category);

	delete[] this->category;
	this->category = buffer;
}

void Appliance::setPower(const double power)
{
	if (power < 0)
		throw "Negative power!";

	this->power = power;
}

void Appliance::turnOn()
{
	if (this->isTurnOn()) return;

	if (this->power + Appliance::currentLoad < Appliance::MAX_LOAD)
	{
		Appliance::currentLoad += this->power;
		this->on = true;
		++Appliance::countObject;
	}
	else
	{
		std::cout << "The system will be overloaded!" << std::endl;
	}
}

void Appliance::turnOff()
{
	if (this->isTurnOn())
	{
		Appliance::currentLoad -= this->power;
		this->on = false;

		--Appliance::countObject;
	}
}

Appliance::Appliance(const char* category, double power, bool on)
	:category(NULL),on(false)
{
	this->setPower(power);
	this->setCategory(category);
	if (on) 
		this->turnOn();
	
}

Appliance::Appliance(const Appliance& other)
	:category(NULL), on(false)
{
	this->setPower(other.power);
	this->setCategory(other.category);
	if (other.isTurnOn())
		this->turnOn();
}

Appliance& Appliance::operator=(const Appliance& other)
{
	if (this != &other)
	{
		this->setPower(other.power);
		this->setCategory(other.category);
		if (other.isTurnOn())
			this->turnOn();
		else
			this->turnOff();
	}

	return *this;
}

Appliance::~Appliance()
{
	delete[] this->category;
	turnOff();
}

void Appliance::print() const
{
	std::cout << "Category: " << this->getCategory() << std::endl;
	std::cout << "Power: " << this->getPower() << std::endl;
	std::cout << "ON: " << std::boolalpha << this->isTurnOn() << std::endl;

	std::cout << "Current load: " << Appliance::getCurrentLoad() << std::endl;
}