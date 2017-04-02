#include"Appliance.h"
#include<iostream>

int main()
{
	Appliance aircon("Air con", 1100, true);
	Appliance pc("Pc", 500, true);
	Appliance washm("Wash m", 400, true);
	Appliance pechka("PECHKA", 2000, true);
	
	aircon.print();
	std::cout << std::endl;

	pc.print();
	std::cout << std::endl;
	
	washm.print();
	std::cout << std::endl;

	pechka.print();
	std::cout << std::endl;

	std::cout << "Appliance on: " << Appliance::getCountObject() << std::endl;
	aircon.turnOff();
	pc.turnOff();
	washm.turnOff();
	std::cout << "Appliance on: " << Appliance::getCountObject() << std::endl;
	

	return 0;
}