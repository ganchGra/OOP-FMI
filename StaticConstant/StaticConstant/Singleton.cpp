//#include<iostream>
////syzdavane na edinstvena instanciq primer
//class Singleton
//{
//public:
//	static Singleton& getInstance();
//
//	void doSth() const;
//private:
//	Singleton();
//	Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//	~Singleton();
//
//
//};
//
//Singleton::Singleton()
//{
//	std::cout << "The only instance was created!" << std::endl;
//}
//Singleton::~Singleton()
//{
//	std::cout << "The only instance was destructed!" << std::endl;
//
//}
//
//Singleton& Singleton::getInstance()
//{
//	static Singleton theOnlyObject;
//	return theOnlyObject;
//}
//
//void Singleton::doSth() const
//{
//	std::cout << "Do some work here...." << std::endl;
//}
//
//int main()
//{
//	Singleton& obj = Singleton::getInstance();
//	obj.doSth();
//
//	Singleton& otherObj = Singleton::getInstance();
//
//	return 0;
//}