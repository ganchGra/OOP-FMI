
#ifndef Owner_H_INCLUDED
#define Owner_H_INCLUDED

#include"car.h"

class Owner
{
	private:
	
		//Owner name
		//max 23 symbols
		char * name;
	
		//Registration number of the car
		/*positive four-digit number*/
		/* error list:
		 * -1 registration number alredy exist
		 * 0 invalid registration number
		 */
		int reg;
		
		//Onwers car with ID number, brand, power
		Car carOwner;
		
	private:
		///Helping function
		//Copy from to char array
		void copyFromTo(char *&dest, const char * src);

		//Resize int array
		void resizeIntArr(int *& arr,size_t originalSize, size_t newSize);

		//Static count total Owners object
		static int countOwnerObj;

		//Static array with all registration number
		/*Registration number must be unique*/
		static int * regNumList;
	public:	
		//Initializes a new Owner object with specific values 
		Owner(const char * name, int reg, int id);

		//Distructor
		~Owner();

	public:
		///Set function
		//Set owner name
		void setName(const char * name);

		//Set car reg;
		void setReg(const int reg);

		///Get function
		//Get owner name
		const char * getName() const;

		//Get car information
		/*Brand, Unique ID, Power, Registration number*/
		const char * getCarBrand() const;
		const int getCarId() const;
		const int getCarPower() const;
		const int getCarReg() const;

		//Get count of the total object
		static int getCountOwnerObj() { return countOwnerObj; }
		
		//Print all Owner information
		
		void print() const;
};
#endif // !Owner_H_INCLUDE

