/// Project Speadsheets.cpp : Defines the entry point for the console application.

#include "stdafx.h"
int main()
{
	Command input("help");
	input.execute();
	
	do
	{
		try
		{
			std::cout << "> ";
			char buffer[_MAX_PATH];
			std::cin.getline(buffer,_MAX_PATH);

			//assign command
			input = buffer;
			input.execute();
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	} while (input.task() != "exit");

	std::cout << "Exiting the program..." << std::endl;

    return 0;
}

