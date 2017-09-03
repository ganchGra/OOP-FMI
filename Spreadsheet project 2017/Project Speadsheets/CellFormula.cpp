#include"stdafx.h"

/// Default constructor
CellFormula::CellFormula()
	:m_formula()
{}

/// Create new obj from String
CellFormula::CellFormula(const String rhs)
	: m_formula(rhs)
{}

/// Create new obj from char array
CellFormula::CellFormula(const char * text)
	: m_formula(text)
{}

/* Virtual function from the base class CellType */
CellType* CellFormula::clone() const
{
	return new CellFormula(*this);
}
String CellFormula::type() const
{
	return "formula";
}
String CellFormula::stringCell() const
{
	return m_formula;
}
void CellFormula::print(std::ostream& out) const
{
	out << m_formula;
}
unsigned CellFormula::lenght() const
{
	return m_formula.lenght();
}
double CellFormula::value() const
{
	throw std::exception("Please, calculate it in the command menu!");
}
/* End virtual function from the base class CellType */


