#include"Owner.h"
//#include"car.h"
#include<iostream>
#include<fstream>


int main()
{
	Owner one("Gratsiela", 1234, 1);
	one.print();
	std::cout << std::endl;
	
	Owner two("Gratsiela", 1222, 2); // alredy exist
	two.print();
	std::cout << std::endl;
	
	Owner three("Teorodra", 1991, 3);
	three.print();
	std::cout << std::endl;
	
	Owner four("Vasil", 1555, 2);  //invalid input
	four.print();
	std::cout << std::endl;
	
	Owner five("Anna", 1991, 2);   // alredy exist
	five.print();
	std::cout << std::endl;

	//TODO FUNCTION POPULAR CAR
	int TotPopularCar_Type = 0;
	int idPopCar = 0;
	
	if (Car::countLamborgini >= Car::countMercedes)
	{
		TotPopularCar_Type = Car::countLamborgini;
		idPopCar = 0;
	}
	else if(Car::countLamborgini < Car::countMercedes)
	{
		TotPopularCar_Type = Car::countMercedes;
		idPopCar = 1;
	}
	if (Car::countPagani > TotPopularCar_Type)
	{
		TotPopularCar_Type = Car::countPagani;
		idPopCar = 2;
	}
	if (Car::countBugatti > TotPopularCar_Type)
	{
		TotPopularCar_Type = Car::countBugatti;
		idPopCar = 3;
	}
	std::cout << "Popolar car: ";
	Car::getBrandType(idPopCar);
	std::cout << std::endl;

	std::cout <<"Total Owner object: "<< Owner::getCountOwnerObj() << std::endl;
	double AVGpower =(double)( Car::getTotalPower()) / (double)(Owner::getCountOwnerObj());
	std::cout << AVGpower << std::endl;
	
	return 0;
}