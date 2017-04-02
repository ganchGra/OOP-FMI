#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

//TODO

String::String()
{
	pStr = NULL;
	size = 0;
}

String::String(const char * str)
{
	pStr = NULL;
	setString(str);
	
}

String::~String()
{
	delete[] pStr;
}
const char * String::getString() const{ 
	return pStr; 
}
void String::setString(const char * str)
{
	delete[] pStr;
	if (!str)
	{
		pStr = NULL;
		size = 0;
	}
	else {
		size = strlen(str);
		pStr = new (std::nothrow) char[size + 1];
		strcpy(pStr, str);
	}
}
String::String(const String & other)
{
	setString(other.getString());
}
String String::operator=(const String & other)
{
	if (this != &other)
	{
		setString(other.getString());
	}
	return *this;
	
}
