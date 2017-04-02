#include "Set.h"
#include <iostream>

int main()
{
	Set a;
	for (int i = 0; i < 10; ++i)
		a.addElement(i);
	Set b;
	for (int i = 5; i < 20; ++i)
		b.addElement(i);
	Set q;
	for (int i = 10; i < 20; ++i)
		q.addElement(i);
	std::cout << q.isSubset(b) << std::endl;
	std::cout << q.isSuperset(b) << std::endl;
	a.print();
	b.print();
	Set c;
	c = a.getUnion(b);
	c.print();
	c = a.getIntersection(b);
	c.print();
	c = a.getDifference(b);
	c.print();
	c = a.getSymmetricDifference(b);
	c.print();
	a.removeElement(5);
	a.print();
}