#include"stdafx.h"

/// Default constructor
CellInt::CellInt()
	:m_number(NULL),m_stringNumber()
{}

/// Create new obj from assign value
CellInt::CellInt(int number,String StringNumber)
	:m_number(number),m_stringNumber(StringNumber)
{}

/* Virtual function from the base class CellType */
CellType* CellInt::clone() const
{
	return new CellInt(*this);
}
void CellInt::print(std::ostream& out) const
{
	out << m_stringNumber;
}
unsigned CellInt::lenght() const
{
	return m_stringNumber.lenght();
}
double CellInt::value() const
{
	return m_number;
}
String CellInt::type() const
{
	return "int";
}
String CellInt::stringCell() const
{
	return m_stringNumber;
}
/* End virtual function from the base class CellType */
