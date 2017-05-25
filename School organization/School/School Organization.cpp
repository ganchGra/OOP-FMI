// School Organization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
	///******************EGN TEST********************//

	/*char egntest[11];
	
	std::cout << "insert egn: ";
	std::cin.clear();
	std::cin.getline(egntest, 11);
	egn test(egntest);
	

	std::cout << "your birthday is: "; test.printbirthday();
	std::cout << "your region is: "; test.printregion();

	std::cout
		<< "your gender is: " << test.getgender() << std::endl
		<< "your day is: " << test.getday() << std::endl
		<< "your mounth is: " << test.getmonth() << std::endl
		<< "your year is: " << test.getyear() << std::endl;

	std::cout << "your gender is: "; test.printgender();*/

	///******************PERSON TEST********************//

	//Person Gratsiela("Gratsiela", "Sv Troitsa", "+35989889463", "9111067937");
	////Person Tedi(Gratsiela);
	//
	//Gratsiela.printEGN();
	//std::cout << Gratsiela.getAdress() << std::endl;
	//std::cout << Gratsiela.getName() << std::endl;
	//std::cout << Gratsiela.getTelNumber() << std::endl;
	//std::cout << Gratsiela.getGender() << std::endl;
	//std::cout<< Gratsiela.getDayOfBirth() << std::endl;
	////Tedi.printPersonalInformation();
	////Gratsiela.printPersonalInformation();
	//std::cout << Gratsiela;

	///******************STUEDEN AND TEACHER TEST********************//

	Student Gratsiela(45311, "Gratsiela", "Sv Troitsa", "+35989889463", "9111067937");
	Gratsiela.printStudentInfo();
	Teacher OOP(2, "Somebody", "FMI", "02/132135", "8115177988");
	OOP.printTeacherInformation();


	return 0;
}