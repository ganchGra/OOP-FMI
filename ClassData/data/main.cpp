#include "Date.h"
#include<iostream>
#include<exception>

//enum ExceptionType
//{
//	INT,
//	DOUBLE,
//	STRING,
//	OBJECT
//};
//
//void throwException(ExceptionType type)
//{
//	/*switch (type)
//	{
//	case INT:
//		throw 1;
//
//	case DOUBLE:
//		throw 3.0;
//
//	case STRING:
//		throw "Something went wrong!";
//
//	case OBJECT:
//		throw std::out_of_range("Index is out bounds!");
//
//	default:
//		throw std::exception("Wrong!");
//	}*/
//}

int main() 
{
	Date test;
	test.setDate(31, 01, 2017);
	test.print();
	//std::cout << Date::isValid << std::endl;
/*
	try
	{
		throwException(INT);
	}
	catch (int& ex)
	{
		std::cout << ex << std::endl;
	}
	catch (double& ex)
	{
		std::cout << ex <<std::endl;
	}
	catch (const char * ex)
	{
		std::cout << ex << std::endl;
	}
	catch (std::out_of_range& ex)
	{
		std::cout << ex.what() << std::endl;
	}*/

	/*Date* arr = new Date[3];

	delete[] arr;*/

	/*Date*arr[3] = { NULL };
	for (int i = 0; i < 3; i++)
	{
		int d, m, y;
		std::cin >> d >> m >> y;
		arr[i] = new Date(d, m, y);
		arr[i]->print();
	}
	for (int i = 0; i < 3; i++)
	{
		delete arr[i];
	}*/




	/*Date d;
	d.print();

	Date d1(8, 3, 2017);
	d1.print();
	d = d1;
	d.print();*/
	return 0;
}