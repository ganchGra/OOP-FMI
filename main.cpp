#include"Owner.h"
#include"car.h"
#include<iostream>
#include<fstream>


int main()
{
	Owner one("Gratsiela", 1234, 1);
	Owner two("Gratsiela", 1234, 2);
	Owner three("Teorodra", 1991, 3);
	Owner four("Vasil", 1555, 4);  
	Owner five("Anna", 1991, 2);   

	one.print();
	std::cout << std::endl;

	two.print();
	std::cout << std::endl;

	three.print();
	std::cout << std::endl;

	four.print();
	std::cout << std::endl;

	five.print();
	std::cout << std::endl;

	std::cout << Owner::getCountOwnerObj() << std::endl;
	
	return 0;
}