#include<iostream>
#include"bicyDetails.h"
#include"Bicy.h"
#include<fstream>

///TEXT FILE
void insertBicyDetailsInFile(std::ofstream& output,const BicyDetail& detail )
{
	if (!output) return;

	output
		<< detail.getType()   <<" | "
	    << detail.getPrice()  <<" | "
		<< detail.getQuality()
		<< std::endl;
}

bool readDetailFile(std::ifstream& file, BicyDetail& detail)
{
	if (!file) return false;

	char buffer[255];
	file.getline(buffer, 255,'|');
	size_t len = strlen(buffer) + 1;
	char * type = new char[len];
	strcpy_s(type, len, buffer);
	
	file.get(); //space 
	
	int price, quality;
	if (file)
	{
		file >> price;
		if (file)
		{
			//how to escape together space and |
			file.get(); //space
			file.get(); //| 
			if (file)
			{
				file >> quality;
				if (file)
				{
					detail.setType(type);
					detail.setPrice(price);
					detail.setQuality(quality);
				}
				file.ignore();
			}
		}
	}
	delete[] type;
	return file.good() || (file.eof() && !file.fail());
}

void insert(int numDetails, std::ofstream& file)
{
	while (numDetails)
	{
		BicyDetail detail;
		char typebuffer[255];
		int price, quality;

		//*********Set type***********//
		std::cin.ignore();
		std::cout << "Detail name: ";
		std::cin.getline(typebuffer, 255);
		size_t len = strlen(typebuffer) + 1;
		char * type = new char[len];
		strcpy_s(type, len, typebuffer);

		detail.setType(type);

		delete[] type;
		//*******End set type*********//

		//***Set price and quality***//
		std::cout << "Price: ";
		std::cin >> price;
		detail.setPrice(price);

		std::cout << "Quality: ";
		std::cin >> quality;
		detail.setQuality(quality);

		//*End set price and quality*//

		insertBicyDetailsInFile(file, detail);
		--numDetails;
	}
}
//END TEXT FILE

///BINARY FILE
bool insertBicyDetailsInBinaryFile(std::ofstream& output, const BicyDetail& detail)
{
	output.write((const char*)&detail, sizeof(BicyDetail));

	return output.good();
}
bool loadDetailsFromBinary(std::ifstream& file, BicyDetail& detail)
{
	file.read((char*)&detail, sizeof(BicyDetail));
	
	return file && file.gcount() == sizeof(BicyDetail);
}
///END BINARY FILE

///PRINT INFORMATION FROM THE FILE
void print(std::ostream& out, const BicyDetail& detail)
{
	out << "Detail name: " << detail.getType() << "\n"
		<< "Price: " << detail.getPrice() << "\n"
		<< "Quality: " << detail.getQuality() << "\n";
}
int main()
{ 
	///
	///if you want to change the detais in the file
	///
	//std::ofstream file("BicyDetails.txt",std::ios::out);
	//if (!file)
	//{
	//	std::cout << "File cannot be opened..";
	//	return 1;
	//}
	//
	//int numDetails;
	//std::cout << "Num of details: ";
	//std::cin >> numDetails;
	//if (numDetails > 0)
	//{
	//	insert(numDetails, file);
	//}
	//file.close();

	std::ifstream file("BicyDetails.txt", std::ios::in);
	
	if (!file)
	{
		std::cout << "BicyDetails.txt cannot be opened..";
		return 1;
	}
	
	std::ofstream binaryFile("BicyDetails.bin", std::ios::binary);

	if (!binaryFile)
	{
		std::cout << "BicyDetails.bin cannot be opened..";
		return 1;
	}
	/*Read and print from the text file and insert only top quality details in the binary file*/
	std::cout << "\nAll details IN THE TEXT FILE:\n";
	BicyDetail detail;
	while (readDetailFile(file, detail))
	{
		print(std::cout, detail);
		if(detail.getQuality() == 1)
			insertBicyDetailsInBinaryFile(binaryFile, detail);
	}
	binaryFile.close();
	file.close();

	/*Print all top quality details from the binary file*/

	///PROBLEM
	std::cout << "\nTot Quality details IN THE BINARY FILE:\n";
	
	std::ifstream readbinaryFile("BicyDetails.bin",std::ios::binary);
	readbinaryFile.ignore();
	readbinaryFile.seekg(0, std::ios::beg);
	if (!readbinaryFile)
	{
		std::cout << "BicyDetails.bin cannot be opened..";
		return 1;
	}

	while (loadDetailsFromBinary(readbinaryFile,detail))
	{
		print(std::cout, detail);
	}

	readbinaryFile.close();


	/**************************SMALL TEST****************************/

	/*******************Create new bicy****************/
	std::cout << "\n\nCreate new bike...\n";

	std::ifstream file2("BicyDetails.txt", std::ios::in);
	if (!file2)
	{
		std::cout << "BicyDetails.txt cannot be opened..";
		return 1;
	}

	/*Take all details from the text file*/
	BicyDetail bmxDet[3];
	size_t position = 0;
	while (readDetailFile(file2, detail))
	{
		bmxDet[position] = detail;
		position++;
	}
	file2.close();

	Bicy BMX;
	BMX.setBrand("BMX");
	BMX.setDetails(bmxDet, 3);
	BicyDetail chain("Veriga", 30, 1);
	
	Bicy TREK("TREK", NULL, 0);
	TREK + chain;
	TREK.print();

	std::cout <<"---------------------"<< std::endl;
	BMX.print();

	std::cout << "---------------------" << std::endl;

	BMX + chain;
	BMX.print();
	std::cout << "---------------------" << std::endl;

	TREK - chain;
	TREK.print();

	std::cout << "---------------------" << std::endl;

	std::cout << "Compare BMX and TREK" << std::endl;
	std::cout << "Are equal: "<<((BMX == TREK)?"True":"False") << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Are different: " << ((BMX != TREK) ? "True" : "False") << std::endl;
	
	std::cout << "---------------------" << std::endl;
	std::cout << "Is smaller: " << ((BMX < TREK) ? "True" : "False") << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Is smaller or equal: " << ((BMX <= TREK) ? "True" : "False") << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Is bigger: " << ((BMX > TREK) ? "True" : "False") << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Is bigger: " << ((BMX > TREK) ? "True" : "False") << std::endl;

	/**************************END SMALL TEST*************************/

	return 0;
}