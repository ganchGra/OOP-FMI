#pragma once
#include"stdafx.h"

/// Class Spreadsheet description
/**
* Spreadsheet is Singleton obj. It have:
*                                       - cells with position  R<value>C<value> and different type: int, double, string and formula.
*                                       - file name
*/
class Spreadsheet
{

private:
	/// Singleton Instance
	static Spreadsheet * pInstance;

public:
	/// Get the pointer of the Spreadsheet obj
	static Spreadsheet& getInstance();

	/// Release the pointer of the Spreadsheet obj
	static void release();

private:
	
	/// Default constructor
	Spreadsheet();
	
	/// Operator =
	Spreadsheet& operator=(const Spreadsheet& rhs);
	
	/// Destructor
	~Spreadsheet();

public:
	/*  Get Spreadsheet information */
	
	/// Get number of rows in the Spreadsheet
	unsigned row() const;

	/// Get number of columns in the Spreadsheet
	unsigned col() const;

	/// Get file name of the Spreadsheet if is open
	String fileName() const;

	/// Get information if the Spreadsheet is open
	bool isOpen() const;

	/// Get maxCell lenght
	unsigned getCellLenght(unsigned index) const;
	
	/// Take cell R<value>C<value>
	const CellType* operator[](String arg) const;
	CellType* operator[](String arg);

	/// Take cell
	const CellType* takeCell(unsigned row, unsigned col) const;
	
private:

	///
	/// Help function to assign max lengh of any column in the Spreadsheet
	/// arguments: index of column, new cell lenght
	///
	void setMaxDataLenght(unsigned index,unsigned cellLenght);
	
public:
	///
	///  Chech if this input is with valid data: R<value>C<value>
	///	
	bool isValidCell(const String data) const;

	/// Set Cells, row and col size, and max colum lenght
	void setCells(CellType*** cells, unsigned rowSize, unsigned colSize);
	
	/// Change single cell value and type
	void changeCell(String index, CellType* newValue);

	/// Set Spreadsheet file name
	void setFileName(String fileName);

	/// Set if the Spreadsheet is open
	void setIsOpen(bool isOpen);

	///Clean the Spreadsheet values
	void clean();

private:
	///
	/// All cells in the Spreadsheet
	///
	CellType *** m_cells;

	///
	/// Row number
	///
	unsigned m_row;

	///
	/// Column number
	unsigned m_col;

	///
	/// Array with max columns data lenght
	///
	unsigned * m_maxDataLenght;
	
	///
	///File name
	///
	String m_fileName;

	///
	///Valid Spreadsheet
	///
	bool m_isOpen;
};

