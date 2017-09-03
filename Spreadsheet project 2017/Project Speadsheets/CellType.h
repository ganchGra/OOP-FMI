
/// Class CellType description
/**
 * Base class for the all Cell type 
 * pure virtual class
 */

#pragma once

class CellType
{
public:
	virtual ~CellType();

	///
	/// Derivate class can be cloned - Returns pointer to himself
	///
	virtual CellType* clone() const =  0;

	///
	/// Print on the stream given as the first argument 
	/// 
	virtual void print(std::ostream& out) const = 0;

	///
	/// Return lenght of the Cell type
	///
	virtual unsigned lenght() const = 0;

	///
	/// Return value of the Cell type
	///
	virtual double value() const = 0;

	///
	/// Return Cell type name
	///
	virtual String type() const = 0;

	///
	/// Return a content of the cell
	///
	virtual String stringCell() const = 0;
};
