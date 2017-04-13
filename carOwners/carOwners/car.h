#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

class Car
{
private:
	//Brand of car
	char *brand;

	//Unique car ID number 
	int id;

	//Max power of the car
	int power;

public:
	//Count total brand
	static int countLamborgini;
	static int countMercedes;
	static int countPagani;
	static int countBugatti;

	//Total power to the all object
	static int totalPower;
public:
	//Defaut constructor
	Car();

	//Initializes a new Car object with specific values 
	Car(const int id);
	
	//Destructor
	~Car();

	//Set all information of the car 
	void setCar(const int id);

	//Getting function
	const char * getBrand() const;
	const int getId() const;
	const int getPower() const;
	static const int getTotalPower();
	static void getBrandType(const int id);
	void printCar() const;
};
#endif // !CAR_H_INCLUDE
