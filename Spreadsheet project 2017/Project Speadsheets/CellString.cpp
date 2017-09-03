#include"stdafx.h"

/// Default constructor
CellString::CellString()
	:m_text()
{}

/// Create new obj from String
CellString::CellString(const String rhs)
	: m_text(rhs)
{}

/// Create new obj from char array
CellString::CellString(const char * text)
	: m_text(text)
{}

/// Create new obj from single character
CellString::CellString(char symbol)
	: m_text(symbol)
{}

/* Virtual function from the base class CellType */
CellType* CellString::clone() const
{
	return new CellString(*this);
}
void CellString::print(std::ostream& out) const
{
	out << m_text;
}
unsigned CellString::lenght() const
{
	return m_text.lenght();
}
double CellString::value() const
{
	double num = convertToNum(m_text);
	return num;
}
String CellString::type() const
{
	return "string";
}
String CellString::stringCell() const
{
	return m_text;
}
/* End virtual function from the base class CellType */



