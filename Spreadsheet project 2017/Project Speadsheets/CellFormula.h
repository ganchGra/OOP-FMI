/// Class CellFormula description
/**
 * Formula cell type
 * derivated class at CellType
 * The formula will be validated and calculated in the Speadsheet
 */

#pragma once
#include"stdafx.h"

class CellFormula: public CellType
{
public:

	/// Default constructor
	CellFormula();

	/// Create new obj from String
	CellFormula(const String rhs);

	/// Create new obj from char array
	CellFormula(const char * text);

	/* Virtual function from the base class CellType */
	virtual CellType* clone() const;
	virtual void print(std::ostream& out) const;
	virtual unsigned lenght() const;
	virtual double value() const;
	virtual String type() const;
	virtual String stringCell() const;
	/*End virtual function*/

private:
	///
	///Content of the cell
	///
	String m_formula;	
};

