#include"stdafx.h"
#include "String.h"

/// Default constructor
String::String()
	:m_text(NULL), m_size(0)
{}

/// Copy constructor
String::String(const String& rhs)
	: m_text(NULL), m_size(0)
{
	set(rhs.m_text);
}

/// Construct string object from char array
String::String(const char * text)
	: m_text(NULL), m_size(0)
{
	set(text);
}

/// Construct string object from character 
String::String(char symbol)
	: m_text(NULL), m_size(0)
{
	set(symbol);
}

/// String destructor 
String::~String()
{
	clear();
}

/// String assignment from another String obj
String& String::operator=(const String& rhs)
{
	if (this != &rhs)
	{
		set(rhs.m_text);
	}
	return *this;
}

/// String assignment from char array
String& String::operator=(const char * rhs)
{
	set(rhs);

	return *this;
}

/// String assignment from single character
String& String::operator=(char symbol)
{
	set(symbol);

	return *this;
}

/// Set obj with value another String obj
void String::set(const String& rhs)
{
	set(rhs.m_text);
}

/// Set obj with value char array
void String::set(const char* text)
{
	if (text == NULL)
		return;

	clear();
	m_size = strlen(text);
	m_text = new char[m_size + 1];
	strcpy_s(m_text, m_size + 1, text);
}

/// Set obj with value single character
void String::set(char symbol)
{
	if (symbol == NULL)
		return;

	if (m_text != NULL)
	{
		clear();
	}

	m_size = 1;
	m_text = new char[m_size];
	m_text[0] = symbol;
	m_text[1] = '\0';
}

/* Capacity */

/// Return length of String
unsigned String::lenght() const
{
	return m_size;
}

/// Test if string is empty 
bool String::empty() const
{
	return (!m_text);
}

/// Clear string
void String::clear()
{
	//if is only one symbol
	if (m_size == 1)
	{
		m_text = NULL;
		m_size = 0;
		return;
	}

	delete[] m_text;
	m_text = NULL;
	m_size = 0;
}

/* Element access */

/// Get character of string 
char& String::operator[](size_t index)
{
	if (index >= m_size)
	{
		throw std::out_of_range("Out of range...");
	}
	return m_text[index];
}

/// Get character of string 
const char& String::operator[](size_t index)const
{
	if (index > m_size)
	{
		throw std::out_of_range("Out of range...");
	}
	return m_text[index];
}

/// Get character in string 
char& String::at(size_t index)
{
	return this->operator[](index);
}

/// Get character in string 
const char& String::at(size_t index) const
{
	return this->operator[](index);
}

/// Access last character 
char& String::back()
{
	return m_text[m_size - 1];
}

/// Access last character 
const char& String::back() const
{
	return m_text[m_size - 1];
}

/// Access first character 	
char& String::front()
{
	return m_text[0];
}

/// Access first character 	
const char& String::front() const
{
	return m_text[0];
}

/* Modifiers: */

/// Append to String another String
String& String::operator+=(const String & rhs)
{
	append(rhs);

	return *this;
}

/// Append to String char array
String& String::operator+=(const char * rhs)
{
	append(rhs);

	return *this;
}

/// Append to String single character
String& String::operator+=(char symbol)
{
	append(symbol);

	return *this;
}

/// Append to String another String
void String::append(const String& rhs)
{
	append(rhs.m_text);
}

/// Append to String char array
void String::append(const char* rhs)
{
	if (rhs == NULL)
	{
		return;
	}
	if (m_size == 0)
	{
		set(rhs);
		return;
	}
	size_t newSize = strlen(m_text) + strlen(rhs) + 1;
	char * fullText = new char[newSize];

	strcpy_s(fullText, newSize, m_text);
	strcat_s(fullText, newSize, rhs);

	clear();
	set(fullText);
	delete[] fullText;
}

/// Append to String single character
void String::append(char symbol)
{
	if (symbol == NULL)
	{
		return;
	}
	if (m_size == 0)
	{
		set(symbol);
		return;
	}
	unsigned newSize = m_size + 2;
	char * fullText = new char[newSize];
	char symbolArr[2] = { symbol,'\0' };
	strcpy_s(fullText, newSize, m_text);
	strcat_s(fullText, newSize, symbolArr);

	clear();
	set(fullText);
	delete[] fullText;
}

/* String operations*/

/// Get C String equivalent 
const char* String::c_str() const
{
	return m_text;
}

/// Reverse the String
String& String::reverse()
{
	size_t len = this->lenght();
	String buffer;

	for (int i = len - 1; i >= 0; --i)
	{
		buffer += this->m_text[i];
	}
	clear();
	set(buffer);

	return *this;
}

///
///Non-member function overloads
///

/*operator<<*/
std::ostream& operator<<(std::ostream& os, const String& str)
{
	if (str.empty())
		os << "NULL";
	else
		os << str.c_str();

	return os;
}

std::istream& getline(std::ifstream& is, String& str, char delim)
{
	while ((is.good() /*&& !is.eof()*/) &&
		(is.peek() != delim && is.peek() != '\n' && is.peek() != EOF))
	{
		char c;
		is.get(c);
		str += c;
	}
	if (str.c_str() == NULL)
	{
		return is;
	}

	///Trim whiteSpace befor string 
	size_t size = str.lenght();
	String bufferBefore;
	size_t posOfFirstChar = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] != ' ')
		{
			posOfFirstChar = i;
			break;
		}
	}
	if (posOfFirstChar == 0 && str[0] == ' ')
	{
		str.clear();
		return is;
	}
	for (posOfFirstChar; posOfFirstChar < size; posOfFirstChar++)
		bufferBefore += str[posOfFirstChar];

	str = bufferBefore;

	///Trim whiteSpace after string 
	unsigned pos = str.lenght() - 1;
	String bufferAfter;
	posOfFirstChar = 0;
	for (pos; pos >= 0; pos--)
	{
		if (str[pos] != ' ')
		{
			posOfFirstChar = pos;
			break;
		}
	}
	for (size_t pos = 0; pos <= posOfFirstChar; pos++)
		bufferAfter += str[pos];
	str = bufferAfter;
	return is;
}
std::istream& getline(std::ifstream& is, String& str)
{
	getline(is, str, '\n');

	return is;
}

/* operator+ */
String operator+(const String& lhs, const String& rhs)
{
	String newString = lhs;
	newString += rhs;

	return newString;

}
String operator+(const String& lhs, const char* rhs)
{
	String newString = lhs;
	newString += rhs;

	return newString;
}
String operator+(const char* lhs, const String& rhs)
{
	String newString = lhs;
	newString += rhs;

	return newString;
}
String operator+(const String& lhs, char rhs)
{
	String newString = lhs;
	newString += rhs;

	return newString;
}
String operator+(char lhs, const String& rhs)
{
	String newString = lhs;
	newString += rhs;

	return newString;
}

/// relational operators (String)
bool operator== (const String& lhs, const String& rhs)
{
	if (lhs.c_str() == NULL && rhs.c_str() == NULL)
		return true;
	else if (lhs.c_str() == NULL && rhs.c_str() != NULL)
		return false;
	else if (lhs.c_str() != NULL && rhs.c_str() == NULL)
		return false;
	else if (strcmp(lhs.c_str(), rhs.c_str()) == 0)
		return true;
	return false;
}
bool operator== (const char*   lhs, const String& rhs)
{
	if (lhs == NULL && rhs.c_str() == NULL)
		return true;
	else if (lhs == NULL && rhs.c_str() != NULL)
		return false;
	else if (lhs != NULL && rhs.c_str() == NULL)
		return false;
	else if (strcmp(lhs, rhs.c_str()) == 0)
		return true;
	return false;
}
bool operator== (const String& lhs, const char*   rhs)
{
	if (lhs.c_str() == NULL && rhs == NULL)
		return true;
	else if (lhs.c_str() == NULL && rhs != NULL)
		return false;
	else if (lhs.c_str() != NULL && rhs == NULL)
		return false;
	else if (strcmp(lhs.c_str(), rhs) == 0)
		return true;

	return false;
}
bool operator!= (const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const char*   lhs, const String& rhs)
{
	return !(lhs == rhs);
}
bool operator!= (const String& lhs, const char*   rhs)
{
	return !(lhs == rhs);
}
bool operator<  (const String& lhs, const String& rhs)
{
	if (lhs.c_str() == NULL || rhs.c_str() == NULL)
		return false;

	if (strcmp(lhs.c_str(), rhs.c_str()) < 0)
		return true;
	return false;
}
bool operator<  (const char*   lhs, const String& rhs)
{
	if (lhs == NULL || rhs.c_str() == NULL)
		return false;

	if (strcmp(lhs, rhs.c_str()) < 0)
		return true;
	return false;
}
bool operator<  (const String& lhs, const char*   rhs)
{
	if (lhs.c_str() == NULL || rhs == NULL)
		return false;
	if (strcmp(lhs.c_str(), rhs) < 0)
		return true;
	return false;
}
bool operator<= (const String& lhs, const String& rhs)
{
	return (lhs == rhs || lhs < rhs);
}
bool operator<= (const char*   lhs, const String& rhs)
{
	return (lhs == rhs || lhs < rhs);
}
bool operator<= (const String& lhs, const char*   rhs)
{
	return (lhs == rhs || lhs < rhs);
}
bool operator>  (const String& lhs, const String& rhs)
{
	return !(lhs <= rhs);
}
bool operator>  (const char*   lhs, const String& rhs)
{
	return !(lhs <= rhs);
}
bool operator>  (const String& lhs, const char*   rhs)
{
	return !(lhs <= rhs);
}
bool operator>= (const String& lhs, const String& rhs)
{
	return (lhs == rhs || !(lhs < rhs));
}
bool operator>= (const char*   lhs, const String& rhs)
{
	return (lhs == rhs || !(lhs < rhs));
}
bool operator>= (const String& lhs, const char*   rhs)
{
	return (lhs == rhs || !(lhs < rhs));
}

//Convert to String
String to_string(double val)
{
	if (val == 0)
		return "0";

	String result;
	String bufferBeforDot;
	char sign = NULL;
	if (val < 0)
	{
		sign = '-';
		val *= -1;
	}
	int beforPoint = static_cast<int>(val);
	double afterPoint = val - beforPoint;

	if (beforPoint == 0)
		bufferBeforDot = "0";
	else
	{
		while (beforPoint)
		{
			int rest = beforPoint % 10;
			beforPoint /= 10;
			char singleNum = rest + '0';
			bufferBeforDot += singleNum;
		}
		bufferBeforDot.reverse();
	}
	if (afterPoint == 0)
		return (sign == NULL) ? bufferBeforDot : sign + bufferBeforDot;

	String bufferAfteDot;

	while (afterPoint >= 0.001)
	{
		afterPoint *= 10;
		int rest = static_cast<int>(afterPoint);
		char singleNum = rest + '0';
		bufferAfteDot += singleNum;
		afterPoint -= rest;
	}
	bufferAfteDot.reverse();
	if (sign == NULL)
		result += bufferBeforDot + ',' + bufferAfteDot;
	else
		result += sign + bufferBeforDot + ',' + bufferAfteDot;

	return result;
}
String to_string(long val)
{
	String buffer;
	if (val == 0)
	{
		buffer += '0';
		return buffer;
	}
	char sign = NULL;
	if (val < 0)
	{
		sign = '-';
		val *= -1;
	}

	//save number on the reverse part
	while (val)
	{
		long rest = val % 10;
		val /= 10;
		char singleNum = rest + '0';
		buffer += singleNum;
	}
	//reverse number
	buffer.reverse();

	return (sign == NULL) ? buffer : sign + buffer;
}