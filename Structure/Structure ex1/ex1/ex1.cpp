#include<iostream>
//*************STUDENT***************//
struct Student {
	char s_first_name[30];
	char s_last_name[30];
	int s_age;
	int s_fn;
};
void Insert_Student_Data(Student& stud) {
	std::cout << "Compile student information\n";
	std::cout << "First name: ";
	std::cin.getline(stud.s_first_name, 30);

	std::cout << "Last name: ";
	//std::cin.ignore();
	std::cin.getline(stud.s_last_name, 30);

	std::cout << "Age: ";
	std::cin >> stud.s_age;
		
	std::cout << "FN: ";
	std::cin >> stud.s_fn;
	std::cout << std::endl;
}


void Print_Student_Data(Student& const id) {
	std::cout << "Student: "
		<< id.s_first_name
		<< " "
		<< id.s_last_name << std::endl
		<< "Age: " << id.s_age << std::endl
		<< "Faculty number: " << id.s_fn << std::endl;
}
//************END_STUDENT***************//

//**************TEACHER*****************//
struct Teacher{
	char first_name[30];
	char last_name[30];
	int age;
};

void Insert_Teach_Data(Teacher& teach) {
	std::cout << "Compile teacher information\n";
	std::cout << "First name: ";
	std::cin.ignore();
	std::cin.getline(teach.first_name,30);

	std::cout << "Last name: ";
	//std::cin.ignore();
	std::cin.getline(teach.last_name, 30);

	std::cout << "Age: ";
	std::cin >> teach.age;
}

void Print_Teach_Data(Teacher& const teach) {
	std::cout << "Teacher: "
		<< teach.first_name
		<< " "
		<< teach.last_name 
		<< std::endl
	    << "Age: " 
		<< teach.age 
		<< std::endl;
}
//**********END_TEACHER*****************//
void Compile_FMI_INFO(Student& stud,Teacher& teach) {
	Insert_Student_Data(stud);
	std::cout << std::endl;
	Insert_Teach_Data(teach);
	std::cout << std::endl;
}
void Print_FMI_INFO(Student& stud, Teacher& teach) {
	//std::cout << std::endl;
	Print_Student_Data(stud);
	std::cout << std::endl;
	Print_Teach_Data(teach);
}
int main() {
	Student fmi_Student;
	Teacher oop_Teacher;

	Compile_FMI_INFO(fmi_Student,oop_Teacher);
	Print_FMI_INFO(fmi_Student, oop_Teacher);

	return 0;
}