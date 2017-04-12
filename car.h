#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

class Car
{
private:
	///
	///Brand of car
	///
	char *brand;

	///
	///Unique car ID number 
	///
	int id;

	///
	///Max power of the car
	///
	int power;

private:
	///
	///Set brand and power of the car
	///

public:
	///
	///Defaut constructor
	///
	Car();

	///
	///Initializes a new Car object with specific values 
	///
	Car(const int id);

	///
	///Copy constructor
	///
	Car(const Car& c);
	
	void setCar(const int id);
	///
	///Getting function
	///
	const char * getBrand() const;
	const int getId() const;
	const int getPower() const;

	void printCar() const;
};
#endif // !CAR_H_INCLUDE
