#include"Set.h"
#include<iostream>

Set& Set::operator+=(int elem)
{
	//if(this->operator()(elem))   //is the same

	if ((*this)(elem))
		return *this;

	int * temp = new int[this->count + 1];
	for (size_t i = 0; i < this->count; i++)
	{
		temp[i] = this->elem[i];
	}
	temp[this->count++] = elem;
	delete[] this->elem;
	this->elem = temp;
	return *this;
}
Set Set::operator+(int elem) const
{
	Set result = *this;
	result += elem;
	return result;
}
Set& Set::operator+=(const Set& right)
{
	for (size_t i = 0; i < right.count; i++)
	{
		*this += right.elem[i];
	}
	return *this;
}

Set& Set::operator-=(int elem)
{
	int * temp = new int[this->count - 1];
	size_t pos = 0;

	for (size_t i = 0; i < this->count; i++)
	{
		if (this->elem[i] != elem)
			temp[pos++] = this->elem[i];
	}

	delete[] this->elem;
	--this->count;
	this->elem = temp;

	return *this;
}
Set& Set::operator-(int) const
{

}
Set& Set::operator-=(const Set& right)
{
	for (size_t i = 0; i < right.count; i++)
	{
		*this -= right.elem[i];
	}
	return *this;
}

//intersection 
Set& Set::operator*=(const Set& rigth)
{
	for (size_t i = 0; i < this->count; i++)
	{
		if (!rigth(this->elem[i]))
		{
			*this -= this->elem[i];
			--i;
		}
	}
	return *this;
}

//Set& operator%=(int);
//Set& operator%(int) const;
//Set& operator%=(const Set&);

bool Set::operator()(int x) const
{
	for (size_t i = 0; i < this->count; ++i)
	{
		if (this->elem[i] == x)
			return true;
	}
	return false;
}
bool Set::operator!() const
{
	return !this->count;
}

bool Set::operator==(const Set& right) const
{
	if (this->count != right.count)
		return false;

	for (size_t i = 0; i < this->count; i++)
	{
		if (!right(this->elem[i]))
			return false;
	}
	return true;
}
bool Set::operator<(const Set& right) const
{
	if (this->count >= right.count)
		return false;

	for (size_t i = 0; i < this->count; i++)
	{
		if (!right(this->elem[i]))
			return false;
	}
	return true;
}
bool Set::operator<=(const Set& right) const
{
	return (*this == right) || (*this < right);
}

size_t Set::getCount() const
{
	return this->count;
}
int& Set::operator[](size_t index)
{
	if (index >= this->count)
		throw "Index out of range..";

	return this->elem[index];
}
const int& Set::operator[](size_t index) const
{
	if (index >= this->count)
		throw "Index out of range..";

	return this->elem[index];
}

std::ostream& operator<<(std::ostream& output, const Set& set)
{
	size_t count = set.getCount();
	output << count << std::endl;

	for (size_t i = 0; i < count; i++)
	{
		output << set[i] << ' ';
	}
	return output;
}