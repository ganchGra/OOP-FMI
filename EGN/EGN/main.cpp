#include<iostream>
#include"EGN.h"

int main() 
{
	char egntest[11];
	EGN test;
	std::cout << "INSERT EGN: ";
	std::cin.clear();
	std::cin.getline(egntest, 11);
	//std::cin.getline(test.setEGN, 11); //How to use & to create pointer to member ?
	test.setEGN(egntest);

	std::cout << "Your birthday is: "; test.printBirthday();
	std::cout << "Your region is: "; test.printRegion();
	
	std::cout 
		<< "Your gender is: " << test.getGender() << std::endl
		<< "Your day is: "<< test.getDay() << std::endl
		<< "Your mounth is: " << test.getMonth() << std::endl
		<< "Your year is: " << test.getYear() << std::endl;
	
	std::cout << "Your gender is: "; test.printGender();

	return 0;
}