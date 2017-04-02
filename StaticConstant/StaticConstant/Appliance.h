#ifndef EL_APPLIANCE_H
#define EL_APPLIANCE_H
class Appliance
{
public:
	Appliance(const char * category, double power, bool turnOn);
	Appliance(const Appliance&);
	Appliance & operator=(const Appliance&);
	~Appliance();

	const char* getCategory() const { return (this->category) ? this->category : ""; }
	double getPower() const{ return this->power; }
	bool isTurnOn() const { return this->on; }

	static double getVoltage() { return Appliance::VOLTAGE; }
	static double getMaxAmperage() { return Appliance::MAX_AMPERAGE; }
	static double getMaxLoad() { return Appliance::MAX_LOAD; }

	static int getCountObject() { return Appliance::countObject; }
	static double getCurrentLoad(){ return Appliance::currentLoad; }

	void setCategory(const char*);
	void setPower(const double);
	
	void turnOn();
	void turnOff();

	void print() const;

private:
	char * category;
	double power;
	bool on;

	static const double VOLTAGE;
	static const double MAX_AMPERAGE;
	static const double MAX_LOAD;

	static int countObject;
	static double currentLoad;
};

#endif // EL_APPLIANCE_H

