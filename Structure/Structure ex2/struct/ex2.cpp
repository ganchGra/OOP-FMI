#include<iostream>

struct Student
{
	char *name;
	int age;
	int fn;
};

void printSudent(const Student& s) {
	std::cout << s.name << std::endl;
	std::cout << "Age: " << s.age << std::endl;
	std::cout << "FN: "<< s.fn << std::endl;
}
void insertStudent(Student& s) {
	char buffer[2048];
	std::cout << "Insert name: ";
	std::cin.getline(buffer, 2048);
	s.name = new char[strlen(buffer) + 1];

	strcpy(s.name, buffer);
	std::cout << "Insert age and FN: ";
	std::cin >> s.age >> s.fn;
}
int main() {
	Student fmi;
	insertStudent(fmi);
	printSudent(fmi);

	return 0;
}