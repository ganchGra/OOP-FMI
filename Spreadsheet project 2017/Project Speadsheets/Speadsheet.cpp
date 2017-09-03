#include"stdafx.h"

//
// Singleton instance
//
Spreadsheet * Spreadsheet::pInstance = NULL;
Spreadsheet& Spreadsheet::getInstance()
{
	if (pInstance == NULL)
		pInstance = new Spreadsheet;
	
	return *pInstance;	
}
void Spreadsheet::release()
{
	delete pInstance;
	pInstance = NULL;
}


/// Default constructor
Spreadsheet::Spreadsheet()
	:m_cells(NULL),m_row(0),m_col(0), m_maxDataLenght(NULL), m_fileName(), m_isOpen(false)
{}

/// Operator =
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	return *this;
}

/// Destructor
Spreadsheet::~Spreadsheet()
{
	clean();
}

/* Get Spreadsheet information */
unsigned Spreadsheet::row() const
{
	return m_row;
}
unsigned Spreadsheet::col() const
{
	return m_col;
}
String Spreadsheet::fileName() const
{
	return m_fileName;
}
bool Spreadsheet::isOpen() const
{
	return m_isOpen;
}

/// Get maxCell lenght
unsigned Spreadsheet::getCellLenght(unsigned index) const
{
	if (index >= m_col)
	{
		throw "Out of range...";
	}
	return m_maxDataLenght[index];
}

/// Take cell
const CellType*  Spreadsheet::takeCell(unsigned row, unsigned col) const
{
	if (row >= m_row || col >= m_col)
		throw std::exception("Cell not found");

	return m_cells[row][col];
}
const CellType* Spreadsheet::operator[](String arg) const
{
	if (isValidCell(arg))
	{
		String stringRow;
		String stringCol;

		size_t sizeArg = arg.lenght();

		//Take row and col value

		size_t pos = 0;
		//escape 'R'
		++pos;

		//take row value
		for (pos; arg[pos] != 'C' && pos < sizeArg; pos++)
			stringRow += arg[pos];

		//escape 'C'
		++pos;

		//take colum value
		for (pos; pos < sizeArg; pos++)
			stringCol += arg[pos];

		unsigned row = convertToInt(stringRow);
		unsigned col = convertToInt(stringCol);

		//Spreadsheet begin from row 0 col 0, the input is from row 1 col 1
		--row;
		--col;
		if (row >= m_row || col >= m_col)
			throw std::exception("Cell not found");

		return m_cells[row][col];
	}
	else
		throw std::exception("Please, insert correct command: edit R<value>C<value> <NewCellValue> !");
}
CellType* Spreadsheet::operator[](const String arg)
{
	if (isValidCell(arg))
	{
		String stringRow;
		String stringCol;

		size_t sizeArg = arg.lenght();

		//Take row and col value

		size_t pos = 0;
		//escape 'R'
		++pos;

		//take row value
		for (pos; arg[pos] != 'C' && pos < sizeArg; pos++)
			stringRow += arg[pos];

		//escape 'C'
		++pos;

		//take colum value
		for (pos; pos < sizeArg; pos++)
			stringCol += arg[pos];

		unsigned row = convertToInt(stringRow);
		unsigned col = convertToInt(stringCol);

		//Spreadsheet begin from row 0 col 0, the input is from row 1 col 1
		--row;
		--col;
		if (row >= m_row || col >= m_col)
			throw std::exception("Cell not found");

		return m_cells[row][col];
	}
	else
		throw std::exception("Please, insert correct command: edit R<value>C<value> <NewCellValue> !");
}
/// All set functions

void Spreadsheet::setCells(CellType*** cells, unsigned rowSize, unsigned colSize)
{
	String fileName = m_fileName;
	bool isOpen = m_isOpen;
	clean();

	m_fileName = fileName;
	m_isOpen = isOpen;
	m_cells = new CellType**[rowSize];
	m_maxDataLenght = new unsigned[colSize];
	m_row = rowSize;
	m_col = colSize;
	///Reset buffer MaxDataLenght
	for (unsigned i = 0; i < m_col; i++)
		m_maxDataLenght[i] = 0;

	for (unsigned row = 0; row < rowSize; row++)
	{
		m_cells[row] = new CellType*[colSize];

		for (unsigned col = 0; col < colSize; col++)
		{
			if(cells[row][col] != NULL)
			{
				m_cells[row][col] = cells[row][col]->clone();
				unsigned cellLenght = cells[row][col]->lenght();
				setMaxDataLenght(col, cellLenght);
			}
			else
			{
				m_cells[row][col] = NULL;
			}
		}
	}
}

void Spreadsheet::setFileName(String fileName)
{
	m_fileName = fileName;
}
void Spreadsheet::setIsOpen(bool isOpen)
{
	m_isOpen = isOpen;
}

void Spreadsheet::changeCell(String index, CellType* newValue)
{
	if (isValidCell(index))
	{
		String stringRow;
		String stringCol;
		size_t sizeData = index.lenght();

		//Take row and col value
		size_t pos = 1;
		//take row value
		for (pos; index[pos] != 'C' && pos < sizeData; pos++)
			stringRow += index[pos];
		++pos;

		//take colum value
		for (pos; pos < sizeData; pos++)
			stringCol += index[pos];
		unsigned row = convertToInt(stringRow);
		unsigned col = convertToInt(stringCol);
		--row;
		--col;
	
		if (row >= m_row || col >= m_col)
			throw std::out_of_range("Out of range...");

		delete m_cells[row][col];

		if (newValue == NULL)
		{
			m_cells[row][col] = NULL;
		}
		else
		{
			m_cells[row][col] = newValue->clone();
			unsigned sizeCell = m_cells[row][col]->lenght();
			if (m_maxDataLenght[col] < sizeCell)
				m_maxDataLenght[col] = sizeCell;
		}
	}
	else
		throw std::exception("Please, insert correct command: edit R<value>C<value> <NewCellValue> !");
}
///
///  Chech if this input is with valid data: R<value>C<value>
///	
bool Spreadsheet::isValidCell(const String data) const
{
	if (data == NULL)
		return false;

	String stringRow;
	String stringCol;

	if (data[0] != 'R')
		return false;

	size_t sizeData = data.lenght();

	//Take row and col value
	size_t pos = 1;
	//take row value
	for (pos; data[pos] != 'C' && pos < sizeData; pos++)
		stringRow += data[pos];

	if (data[pos] != 'C')
		return false;
	++pos;

	//take colum value
	for (pos; data[pos] != ' ' && pos < sizeData; pos++)
		stringCol += data[pos];

	if (stringRow == NULL || stringCol == NULL)
		return false;
	if (!isInt(stringRow) && !isInt(stringCol))
		return false;
	
	unsigned row, col;
	try
	{
		row = convertToInt(stringRow);
		col = convertToInt(stringCol);
	}
	catch (const std::exception&)
	{
		return false;
	}
	--row;
	--col;
	if (row < 0 || col < 0)
		return false;
	return true;
}

///
/// Help function to assign max lengh of any column in the Spreadsheet
/// arguments: index of column, new cell lenght
///
void Spreadsheet::setMaxDataLenght(unsigned index,unsigned cellLenght)
{
	if (m_maxDataLenght[index] == NULL || m_maxDataLenght[index] < cellLenght)
	{
		m_maxDataLenght[index] = cellLenght;
	}
}

///
///Clean the Spreadsheet values
///
void Spreadsheet::clean()
{
	// Clean Spreadsheet if is open
	if (m_isOpen)
	{
		for (size_t i = 0; i < m_row; i++)
		{
			for (size_t j = 0; j < m_col; j++)
			{
				delete m_cells[i][j];
			}
			delete[] m_cells[i];
		}

		delete[] m_cells;

		delete[] m_maxDataLenght;
		m_row = 0;
		m_col = 0;
		m_fileName.clear();
		m_isOpen = false;
	}
}
