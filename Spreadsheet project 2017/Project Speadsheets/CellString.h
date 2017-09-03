/// Class CellString description
/**
 * String type of the cell
 * derivated class at CellType
 * The class value can be converted to a number if it's content is valid number
 */

#pragma once
#include"stdafx.h"

class CellString:public CellType
{
public:
	/// Default constructor
	CellString();

	/// Create new obj from String
	CellString(const String rhs);

	/// Create new obj from char array
	CellString(const char * text);

	/// Create new obj from single character
	CellString(char symbol);

	/* Virtual function from the base class CellType */
	virtual CellType* clone() const;
	virtual void print(std::ostream& out) const;
	virtual unsigned lenght() const;
	virtual double value() const;
	virtual String type() const;
	virtual String stringCell() const;
	/* End virtual function from the base class CellType */

private:
	///
	///Content of the cell
	///
	String m_text;
};

