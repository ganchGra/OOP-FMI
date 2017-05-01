#include<iostream>
#include"bicyDetails.h"
#include<fstream>

void insertBicyDetailsInFile(std::ofstream& output,const BicyDetail& detail )
{
	if (!output) return;

	output
		<< detail.getType()   <<" | "
	    << detail.getPrice()  <<" | "
		<< detail.getQuality()
		<< std::endl;
}

bool insertBicyDetailsInBinaryFile(std::fstream& output, const BicyDetail& detail)
{
	output.write((const char*)&detail, sizeof(BicyDetail));

	return output.good();
}
bool loadDetailsFromBinary(std::fstream& file, BicyDetail& detail)
{
	file.read((char*)&detail, sizeof(BicyDetail));
	
	return file && file.gcount() == sizeof(BicyDetail);
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
	std::fstream binaryFile("BicyDetails.bin", std::ios::out| std::ios::in |std::ios::binary);
	if (!file)
	{
		std::cout << "BicyDetails.txt cannot be opened..";
		return 1;
	}
	if (!binaryFile)
	{
		std::cout << "BicyDetails.bin cannot be opened..";
		return 1;
	}
	BicyDetail detail;
	while (readDetailFile(file, detail))
	{
		print(std::cout, detail);
		if(detail.getQuality() == 1)
			insertBicyDetailsInBinaryFile(binaryFile, detail);
	}

	std::cout << "\nDETAILS IN THE BINARY FILE:\n";
	binaryFile.ignore();
	binaryFile.seekg(0, std::ios::beg);

	///ERROR   ??? 
	BicyDetail binaryDetail;
	while (loadDetailsFromBinary(binaryFile,detail))
	{
		print(std::cout, detail);
	}

	file.close();
	binaryFile.close();


	return 0;
}