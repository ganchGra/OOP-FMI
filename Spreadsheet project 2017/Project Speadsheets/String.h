/// Class String description
/**
* Strings are objects that represent sequences of characters
*/

#pragma once

#include"stdafx.h"
class String
{
public:

	/// Default constructor
	String();

	/// Copy constructor
	String(const String& rhs);

	/// Construct string object from char array
	String(const char * text);

	/// Construct string object from character 
	String(char symbol);

	/// String destructor 
	~String();

	/// String assignment from another String obj
	String& operator=(const String& rhs);

	/// String assignment from char array
	String& operator=(const char* rhs);

	/// String assignment from single character
	String& operator=(char symbol);

public:
	/// Set obj with value another String obj
	void set(const String& rhs);

	/// Set obj with value char array
	void set(const char* text);

	/// Set obj with value single character
	void set(char symbol);

public:
	/* Capacity */

	/// Return length of String
	unsigned lenght() const;

	/// Test if string is empty 
	bool empty() const;

	/// Clear string
	void clear();

public:

	/* Element access */

	/// Get character of string 
	char& operator[](size_t index);

	/// Get character of string 
	const char& operator[](size_t index)const;

	/// Get character in string 
	char& at(size_t index);

	/// Get character in string 
	const char& at(size_t index) const;

	/// Access last character 
	char& back();

	/// Access last character 
	const char& back() const;

	/// Access first character 	
	char& front();

	/// Access first character 	
	const char& front() const;

public:

	/* Modifiers: */

	/// Append to String another String
	String& operator+=(const String& rhs);

	/// Append to String char array
	String& operator+=(const char * rhs);

	/// Append to String single character
	String& operator+=(char symbol);

	/// Append to String another String
	void append(const String& rhs);

	/// Append to String char array
	void append(const char* rhs);

	/// Append to String single character
	void append(char rhs);

public:

	/* String operations*/

	/// Get C String equivalent 
	const char* c_str() const;

	/// Reverse the String
	String& reverse();

private:
	///
	/// char array with String value
	///
	char * m_text;

	///
	/// String lenght
	/// 
	size_t m_size;
};

///
///Non-member function overloads
///

std::ostream& operator<<(std::ostream& os, const String& str);
//std::istream& operator>>(std::istream& is, String& str);

std::istream& getline(std::ifstream& is, String& str, char delim);
std::istream& getline(std::ifstream& is, String& str);

/// operator+
String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, const char* rhs);
String operator+(const char* lhs, const String& rhs);
String operator+(const String& lhs, char rhs);
String operator+(char lhs, const String& rhs);

/// relational operators (String)
bool operator== (const String& lhs, const String& rhs);
bool operator== (const char*   lhs, const String& rhs);
bool operator== (const String& lhs, const char*   rhs);

bool operator!= (const String& lhs, const String& rhs);
bool operator!= (const char*   lhs, const String& rhs);
bool operator!= (const String& lhs, const char*   rhs);

bool operator<  (const String& lhs, const String& rhs);
bool operator<  (const char*   lhs, const String& rhs);
bool operator<  (const String& lhs, const char*   rhs);

bool operator<= (const String& lhs, const String& rhs);
bool operator<= (const char*   lhs, const String& rhs);
bool operator<= (const String& lhs, const char*   rhs);

bool operator>  (const String& lhs, const String& rhs);
bool operator>  (const char*   lhs, const String& rhs);
bool operator>  (const String& lhs, const char*   rhs);

bool operator>= (const String& lhs, const String& rhs);
bool operator>= (const char*   lhs, const String& rhs);
bool operator>= (const String& lhs, const char*   rhs);


//Convert to String
String to_string(double val);
String to_string(long val);
