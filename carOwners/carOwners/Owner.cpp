#include<iostream>
#include"Owner.h"
#include"car.h"

//Inizialization of the static data
int Owner::countOwnerObj = 0;
int * Owner::regNumList = NULL;

//Initializes a new Owner object with specific values 
Owner::Owner(const char * name, int reg, int id)
{
	this->name = NULL;
	this->reg = 0;
	
	//chek and set if this car exist
	carOwner.setCar(id);
	if (carOwner.getBrand() == "") 
		return;
	
	//chek and set if this registration num is in the list
	setReg(reg);
	if (this->reg == -1) 
	{
		if(carOwner.getBrand()!= NULL || carOwner.getBrand() != "")
			carOwner.~Car();
		
		std::cout << "Already existing registration number...\n";
		return;
	}
	else if(this->reg == 0)
	{
		if (carOwner.getBrand() != NULL || carOwner.getBrand() != "")
			carOwner.~Car();

		std::cout << "Invalid reg number!..\n";
		return;
	}
	
	//set name if this car is with true value
	setName(name);	
}
 
//Free the resourses used by Owner object
Owner::~Owner()
{
	delete[] this->name;
	delete_RegNum_From_List(this->reg);
	--countOwnerObj;
}
///Helping function
//Copy from to char array
void Owner::copyFromTo(char *&dest, const char * src)
{
	if (src == NULL)
	{
		delete[] dest;
		dest = NULL;
		return;
	}
	size_t len = strlen(src) + 1;
	char * buffer = new char[len];
	strcpy_s(buffer,len, src); 
	delete[] dest;
	dest = buffer;
}

//Resize int arr
void Owner::resizeIntArr(int *& arr, size_t originalSize, size_t newSize)
{
	int * buffer = new int[newSize];
	for (size_t i = 0; i < originalSize; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

//Delete registration number from the list
void Owner::delete_RegNum_From_List(const int number)
{
	//delete list if exist only one registration number
	if (countOwnerObj == 1)
	{
		delete[] regNumList;
		return;
	}
	// 1 2 3 4
	// 1 2 4
	
	int RegPosition = 0;
	for (size_t i = 0; i < countOwnerObj; i++)
	{
		if (regNumList[i] != number)
		{
			regNumList[i] = regNumList[RegPosition];
			RegPosition++;
		}
	}
	resizeIntArr(regNumList, countOwnerObj, countOwnerObj - 1);
}

//Set owner name
void Owner::setName(const char * name)
{
	copyFromTo(this->name, name);
}

//Set car reg
void Owner::setReg(const int reg)
{
	if (reg > 1000 && reg < 9999) {
		if (countOwnerObj == 0)
		{
			++countOwnerObj;
			regNumList = new int[countOwnerObj];
			regNumList[0] = reg;
			this->reg = reg;
		}
		else
		{
			for (size_t i = 0; i < countOwnerObj; i++)
			{
				if (reg == regNumList[i])
				{  
					// alredy exist reg number
					this->reg = -1;
					return;
				}
			}
			//Resize Registration list and add the new reg num
			resizeIntArr(regNumList, countOwnerObj, countOwnerObj + 1);
			++countOwnerObj;
			regNumList[countOwnerObj - 1] = reg;
			this->reg = reg;
		}
	}
}

//Get owner name
const char * Owner::getName() const
{
	return (this->name == NULL) ? "" : this->name;
}

/*
 * Get car information
 * Brand, Unique Id , Power, Registration number
 */
const char * Owner::getCarBrand() const
{
	return this->carOwner.getBrand();
}

const int Owner::getCarId() const
{
	return this->carOwner.getId();
}

const int Owner::getCarPower() const
{
	return this->carOwner.getPower();
}

const int Owner::getCarReg() const
{
	return this->reg;
}

//Print Object value
void Owner::print() const
{	
	if (this->getName() == "" || this->getName() == NULL ||
		this->getCarReg() == 0 || this->getCarReg() == -1 || 
		this->carOwner.getBrand() == "" || this->carOwner.getBrand() == NULL) 
	{
		std::cout << "Invalid object...\n";
		return;
	}
	
	std::cout << "Owner: " << this->getName() << std::endl;
	std::cout << "Car registration num: " << this->getCarReg() << std::endl;
	std::cout << "Car ID: " << this->carOwner.getId() << std::endl;
	std::cout << "Car brand: " << this->carOwner.getBrand() << std::endl;
	std::cout << "Car power: " << this->carOwner.getPower() << std::endl;	
}

