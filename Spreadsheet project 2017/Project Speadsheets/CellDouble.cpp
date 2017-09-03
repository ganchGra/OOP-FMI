#include"stdafx.h"

/// Default constructor
CellDouble::CellDouble()
	:m_number(NULL), m_stringNumber()
{}

/// Create new obj from assign value
CellDouble::CellDouble(double number, String stringNumber)
	: m_number(number),m_stringNumber(stringNumber)
{}

/* Virtual function from the base class CellType */
CellType* CellDouble::clone() const
{
	return new CellDouble(*this);
}
void CellDouble::print(std::ostream& out) const
{
	out << m_stringNumber;
}
unsigned CellDouble::lenght() const
{
	return m_stringNumber.lenght();
}
double CellDouble::value() const
{
	return m_number;
}
String CellDouble::type() const
{
	return "double";
}
String CellDouble::stringCell() const
{
	return m_stringNumber;
}
/*End Virtual function from the base class CellType*/

