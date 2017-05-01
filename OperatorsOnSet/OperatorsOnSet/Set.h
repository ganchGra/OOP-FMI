#pragma once
#include<fstream>

class Set
{
public:
	Set();
	Set(const Set&);
	Set& operator=(const Set&);
	~Set();

	Set& operator+=(int);
	Set operator+(int) const;
	Set& operator+=(const Set&);

	Set& operator-=(int);
	Set& operator-(int) const;
	Set& operator-=(const Set&);

	Set& operator*=(const Set&);

	Set& operator%=(int);
	Set& operator%=(int) const;
	Set& operator%=(const Set&);

	bool operator()(int) const;
	bool operator!() const;

	bool operator==(const Set&) const;
	bool operator<(const Set&) const;
	bool operator<=(const Set&) const;

	size_t getCount() const;
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

private:
	int * elem;
	size_t count;
};

std::ostream& operator<<(std::ostream& output, const Set& set);