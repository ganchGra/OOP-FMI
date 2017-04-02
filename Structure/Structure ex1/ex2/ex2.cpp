#include<iostream>
struct DATE{
	int date;
	int mounth;
	int year;
};
void Insert_Date(DATE& ins) {
	std::cin >> ins.date
		>>ins.mounth
		>> ins.year;
	switch(ins.mounth)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (ins.date < 1 || ins.date > 31)
			std::cout << "INCORECT DATE\n";
		break;
	case 4: case 6: case 9: case 11:
		if (ins.date < 1 || ins.date > 30)
			std::cout << "INCORECT DATE\n";
		break;
	case 2:
		if (ins.date <1 || ins.date > 28)
			std::cout << "INCORECT DATE\n";
		break;
	default:
		std::cout << "INCORECT DATE\n";
		break;
	}
	if (ins.year < 1 || ins.year < 1800 )
		std::cout << "INCORECT DATE\n";

}
void Print_Date(DATE& pr_date) {
	std::cout << pr_date.date << "/" << pr_date.mounth << "/" << pr_date.year << std::endl;
}
int main() {
	DATE exam;
	Insert_Date(exam);
	Print_Date(exam);
	return 0;
}