#include"stdafx.h"

/// Default constructor
Command::Command()
	:m_task(), m_taskArg()
{}

/// Copy constructor
Command::Command(const Command& rhs)
	: m_task(rhs.m_task), m_taskArg(rhs.m_taskArg)
{}

/// Create new obj from String
Command::Command(const String text)
	: m_task(), m_taskArg()
{
	set(text);
}

/// Create new obj from char array
Command::Command(const char* text)
	: m_task(), m_taskArg()
{
	set(text);
}

/// Create new obj from single character
Command::Command(char symbol)
	: m_task(), m_taskArg()
{
	set(symbol);
}

/// Destructor
Command::~Command()
{
	clear();
}

/// Assign from Command obj
Command& Command::operator=(const Command& rhs)
{
	if (this != &rhs)
	{
		clear();
		m_task = rhs.m_task;
		m_taskArg = rhs.m_taskArg;
	}
	return *this;
}

/// Assign from String
Command& Command::operator=(const String& rhs)
{
	set(rhs.c_str());
	return *this;
}

/// Assign from char array
Command& Command::operator=(const char* rhs)
{
	set(rhs);
	return *this;
}

/// Assign from signle character
Command& Command::operator=(char symbol)
{
	set(symbol);
	return *this;
}

/// Return command task
String Command::task() const
{
	return m_task;
}

/// Return command argument
String Command::commandArg() const
{
	return m_taskArg;
}

/// Clear command task and argument
void Command::clear()
{
	m_task.clear();
	m_taskArg.clear();
}

///
/// Set Command values from different sources
///
void Command::set(const String text)
{
	set(text.c_str());
}
void Command::set(const char* text)
{
	if (text == NULL|| text =="")
		throw std::exception("Insert command!");

	size_t size = strlen(text);
	if (size == 0)
		throw std::exception("Insert command!");

	//reset Command values
	clear();

	size_t pos = 0;
	//set task
	for (pos; text[pos] != ' ' && pos < size; ++pos)
		m_task += text[pos];

	//escape whitespaces
	for (pos; text[pos] == ' ' && pos < size; pos++)
	{}

	//set argument
	for (pos; pos < size; ++pos)
		m_taskArg += text[pos];
}
void Command::set(const char symbol)
{
	if (symbol == NULL)
		throw std::exception("Insert command!");

	//reset Command values
	clear();
	//Set task (argument isn't exist)
	m_task = symbol;
}

/// Execute Command
void Command::execute() const
{
	//
	// Command: help
	//
	if (m_task == "help" && m_taskArg == NULL)
	{
		help();
	}

	//
	// Command: open <PathToFile> 
	//
	else if (m_task == "open")
	{
		if (m_taskArg == NULL)
			throw std::exception("Please, insert file path!");

		String fileName = m_taskArg;
		open(m_taskArg);

		std::cout << "Successfully opened " << fileName << std::endl;
	}

	//
	// Command: close 
	//
	else if (m_task == "close"  && m_taskArg == NULL)
	{
		String fileName = Spreadsheet::getInstance().fileName();
		close();
		std::cout << "Successfully closed " << fileName << std::endl;
	}

	//
	// Command: save 
	//
	else if (m_task == "save" && m_taskArg == NULL)
	{
		save();
		std::cout << "Successfully saved " << Spreadsheet::getInstance().fileName() << std::endl;
	}
	
	//
	// Command: saveas <PathToFile> 
	//
	else if (m_task == "saveas")
	{
		if (m_taskArg == NULL)
			throw std::exception("Please, insert a name of the new file!");
	
		String newFileName = m_taskArg;
		saveAs(newFileName);
		std::cout << "Successfully saved " << newFileName << std::endl;
	}
	
	//
	// Command: print 
	//
	else if (m_task == "print"  && m_taskArg == NULL)
	{
		print();
		std::cout << "Successfully print " << Spreadsheet::getInstance().fileName() << std::endl;
	}
	
	//
	// Command: edit R<value>C<value> <NewCellValue> 
	//
	else if (m_task == "edit")
	{
		if (m_taskArg == NULL)
			throw std::exception("Please, insert correct command: edit R<value>C<value> <NewCellValue> !");
	
		size_t sizeArg = m_taskArg.lenght();
		
		String stringRow;
		String stringCol;

		String index;
		String newCellValue;

		//take index
		unsigned pos = 0;
		for (pos; m_taskArg[pos] != ' ' && pos < sizeArg; pos++)
			index += m_taskArg[pos];
	
		if (m_taskArg[pos] != ' ')
			throw std::exception("Please, insert correct command: edit R<value>C<value> <NewCellValue> !");
		
		// escape whitespaces
		for (pos; m_taskArg[pos] == ' ' && pos < sizeArg; pos++) {}
			
		//take newCellValue
		for (pos; pos < sizeArg; pos++)
			newCellValue += m_taskArg[pos];

		try
		{
			edit(index, newCellValue);
			std::cout << "Successfully change cell "<< index << std::endl;
		}
		catch (const std::exception& e)
		{
			throw std::exception(e);
		}
	}
	
	//
	// Command: add [row | col] <unsigned> 
	//
	else if (m_task == "add")
	{
		size_t sizeArg = m_taskArg.lenght();
		if (!sizeArg)
			throw std::exception("Please, insert correct command: add [row|col] <unsigned> !");
	
		String choise; 
		String stringNum;
		unsigned number;
	
		size_t pos = 0;
	
		//extracting introduced choice
		for (pos ; m_taskArg[pos] != ' ' && pos < sizeArg; pos++)
			choise += m_taskArg[pos];
	
		//escape whitespace
		for (pos; m_taskArg[pos] == ' ' && pos < sizeArg; pos++)
		{}
			
		//extracting the number of the new rows or columns
		for (pos; pos < sizeArg; pos++)
			stringNum += m_taskArg[pos];
	
		if(stringNum.c_str()==NULL)
			throw std::exception("The number of new [row][col] must be unsigned type!");
	
		//convert the extracted number if is valid
		try
		{
			number = convertToInt(stringNum);
			if (number <= 0)
				throw std::exception("The number of new [row][col] must be unsigned type.");
		}
		catch (const std::exception& e)
		{
			String mess = stringNum + " "+ e.what();
			throw std::exception(mess.c_str());
		}
	
		//add row or colum or throw exception when the choice is wrong
		if (choise == "row")
		{
			addEmptyRow(number);
			String mess = (number == 1) ? ("Successfully add " + stringNum + " empty row.") : ("Successfully add " + stringNum + " empty rows.");
			std::cout << mess  << std::endl;
		}
		else if (choise == "col")
		{
			addEmptyCol(number);
			String mess = (number == 1)? ("Successfully add " + stringNum + " empty column."): ("Successfully add " + stringNum + " empty colums.");
			std::cout << mess << std::endl;
		}
		else
		{
			throw std::exception("Wrong choise! Please, insert correct command: add [row|col] <unsigned> !");
		}
	}

	//
	// Clean and exit from the Spreadsheet
	//
	else if (m_task == "exit")
	{
		Spreadsheet::getInstance().clean();
		Spreadsheet::getInstance().release();
		return;
	}

	//
	// Wrong command
	//
	else
	{
		throw std::exception("Invalid Spreadsheet command...!");
	}
}

///
///Convert Strint to Cell
///
CellType* Command::convertToCellType(const String src) const
{
	if (src.c_str() == NULL)
	{
		return NULL;
	}
	else if (isFloat(src))
	{
		return new CellDouble(convertToFloat(src), src);
	}
	else if (isInt(src))
	{
		return new CellInt(convertToInt(src), src);
	}
	else if (isString(src))
	{
		return new CellString(src);
	}
	else if (isFormula(src))
	{
		return new CellFormula(src);
	}
	else
	{
		throw std::exception(" is unknown data type");
	}
}
/* Command menu */

void Command::help() const
{
	std::cout
		<< "******************************************************************************************************************************************************************\n"
		<< "* Available Spreadsheet commands:                                                                                                                                 *\n"
		<< "*  - open <PathToFile>                    - Open specified file, given as the first argument. If the file does not exist then it's been created.                 *\n"
		<< "*  - close                                - Closes an already opened file without saving any changes in it.                                                      *\n"
		<< "*                                           Close does not exit the program. If no file has been opened, you get an ERROR.                                       *\n"
		<< "*  - save                                 - Saves data in the opened file. If no file has been opened, you get an ERROR.                                         *\n"
		<< "*  - saveas <PathToFile>                  - Saves data in the specified file, given as the first argument. If no file has been opened, you get an ERROR.         *\n"
		<< "*  - print                                - Prints files data on console window. If no file has been opened, you get an ERROR.                                   *\n"
		<< "*  - edit R<value>C<value> <NewCellValue> - Changes value in given cell. First argument specifies row and column of the cell.                                    *\n"
		<< "*                                           Second argument specifies the new cell value. Valids data types are: <integer>, <double>, \"<string>\", =<formula>.    *\n"
		<< "*  - add [row|col] <unsigned>             - Add empty row or column. Second argument specifies the number of the new rows or columns.                            *\n"
		<< "*  - exit                                 - Exit the program without saving any changes in opened file, if there is one.                                         *\n"
		<< "*  - help                                 - Prints available commands info.                                                                                      *\n"
		<< "******************************************************************************************************************************************************************\n";
}

void Command::open(String fileName) const
{
	if (Spreadsheet::getInstance().isOpen())
	{
		String mess = "Cannot open one more Speeadsheet. Please close: " + Spreadsheet::getInstance().fileName();
		throw std::exception(mess.c_str());
	}

	std::ifstream file(fileName.c_str(), std::ios::in);

	//if is not exist create new file
	if (!file)
	{
		try
		{
			Spreadsheet::getInstance().setIsOpen(true);
			saveAs(fileName); 
			Spreadsheet::getInstance().setFileName(fileName);
			return;
		}
		catch (const std::exception& e)
		{
			Spreadsheet::getInstance().setIsOpen(false);
			throw std::exception(e);
		}
	}

	/*Load all information in the Vector*/
	//extract the number of all columns
	unsigned numberOfColumns = 0;

	Vector<String> vectorCol;
	Vector<Vector<String>> vectorRow;

	while (file.good() && !file.eof())
	{
		//extract single value between commas 
		String cellValue;
		getline(file, cellValue, ',');

		// add value in the column vector
		vectorCol.push_back(cellValue);

		//add column vector to row vector if extract value is on the end of the line or end of the file
		if (file.peek() == '\n' || file.peek() == EOF)
		{
			vectorRow.push_back(vectorCol);
			unsigned vecColSize = vectorCol.size();
			if (numberOfColumns < vecColSize)
				numberOfColumns = vecColSize;

			vectorCol.clear();
		}
		file.ignore();
	}
	file.close();
	/*End load*/

	unsigned row = vectorRow.size();
	unsigned col = numberOfColumns;
	CellType *** bufferCells = new CellType**[row];
	
	///Insert cell data into the buffer Spreadsheet
	for (unsigned i = 0; i < row; i++)
	{
		unsigned colLenght = vectorRow[i].size();
		bufferCells[i] = new CellType*[col];

		for (unsigned j = 0; j < col; j++)
		{
			if (j < colLenght)
			{
				CellType* type;
				try
				{
					 type = convertToCellType(vectorRow[i][j]);
				}
				catch (const std::exception& e)
				{

					String mess =
						"Error: row " + to_string((long)(i+1)) +
						", col " + to_string((long)(j + 1)) + ", " +
						vectorRow[i][j] + e.what();

					throw std::exception(mess.c_str());
				}
				if (type == NULL)
					bufferCells[i][j] = NULL;
				else
					bufferCells[i][j] = type->clone();

				delete type;
			}
			else
			{
				bufferCells[i][j] = NULL;

			}
		}
	}

	///Asign data on obj Spreadsheet
	Spreadsheet::getInstance().setCells(bufferCells, row, col);
	Spreadsheet::getInstance().setIsOpen(true);
	Spreadsheet::getInstance().setFileName(fileName);

	// Clean buffer
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			delete bufferCells[i][j];
		}
		delete[] bufferCells[i];
	}
}

void Command::close() const
{
	if (Spreadsheet::getInstance().isOpen())
	{
		Spreadsheet::getInstance().clean();
		Spreadsheet::getInstance().release();
		return;
	}
	else
	{
		throw std::exception("Please, open a file!");
	}
}

void Command::save() const
{
	saveAs(Spreadsheet::getInstance().fileName());
}

void Command::saveAs(String FileName) const
{
	if (!Spreadsheet::getInstance().isOpen())
		throw std::exception("Please, open a file!");

	std::ofstream file(FileName.c_str());
	if (!file)
	{
		String mess = "Wrong path... " + FileName;
		throw std::exception(mess.c_str());
	}
	unsigned maxRow = Spreadsheet::getInstance().row();
	unsigned maxCol = Spreadsheet::getInstance().col();
	for (unsigned row = 0; row < maxRow; row++)
	{
		for (unsigned col = 0; col < maxCol; col++)
		{
			if (Spreadsheet::getInstance().takeCell(row,col) != NULL)
			{
				Spreadsheet::getInstance().takeCell(row, col)->print(file);
				file << ',';
			}
			else if (col < col - 1)
			{
				file << ',';
			}
		}
		if (row < row - 1)
		{
			file << "\n";
		}
	}
	file.close();
}

void Command::print() const
{
	if (!Spreadsheet::getInstance().isOpen())
		throw std::exception("Please, open a file!");
	
	unsigned maxRow = Spreadsheet::getInstance().row();
	unsigned maxCol = Spreadsheet::getInstance().col();
	if ( maxRow == 0)
		throw std::exception("Empty file...");
	
	for (size_t row = 0; row < maxRow; row++)
	{
		for (size_t col = 0; col < maxCol; col++)
		{
			unsigned cellLen = Spreadsheet::getInstance().getCellLenght(col);
			if (Spreadsheet::getInstance().takeCell( row, col) == NULL)
			{
				printWhiteSpace(cellLen);
				std::cout << "|";
			}
			else
			{
				if (Spreadsheet::getInstance().takeCell(row, col)->type() == "formula")
				{
					try
					{
						double result = calcFormula(Spreadsheet::getInstance().takeCell(row, col)->stringCell());
						String StringResult = to_string(result);
						unsigned sizeResult = StringResult.lenght();
						printWhiteSpace(cellLen - sizeResult);
						std::cout << result;
					}
					catch (const std::exception& e)
					{
						unsigned sizeError = strlen("ERROR");
						printWhiteSpace(cellLen - sizeError);
						std::cout << e.what();
					}
				}
				else
				{
					unsigned sizeType = Spreadsheet::getInstance().takeCell(row, col)->lenght();
					printWhiteSpace(cellLen - sizeType);
					Spreadsheet::getInstance().takeCell(row, col)->print(std::cout);
				}
				std::cout << "|";
			}
		}
		std::cout << "\n";
	}
}
///
/// Help function for the print command
///
void Command::printWhiteSpace(unsigned number) const
{
	for (unsigned i = 0; i < number; i++)
		std::cout << ' ';
}

//
// Calculate formula if it is not valid throw exception
//
double Command::calcFormula(const String formula) const
{
	double result = 0;

	Vector<String> split;
	size_t formulaSize = formula.lenght();
	size_t pos = 1;
	do
	{
		String value;
		//escape whitespaces
		for (pos; formula[pos] == ' ' && pos < formulaSize; pos++)
		{}
		//take the word after whitespace or sign
		char sign = NULL;
		for (pos; formula[pos] != ' ' && pos < formulaSize; pos++)
		{
			
			if (formula[pos] == '+' || formula[pos] == '-' ||
				formula[pos] == '/' || formula[pos] == '*')
			{
				sign = formula[pos];
				pos++;
				break;
			}
			else
			{
				value += formula[pos];
			}
		}
		split.push_back(value);
		if (sign != NULL)
		{
			String strSign(sign);
			sign = NULL;
			split.push_back(strSign);
		}
	} while (pos < formulaSize);

	size_t vectorSize = split.size();
	///the formula must be with even element
	if (vectorSize % 2 == 0)
		throw std::exception("ERROR");

	char sign = NULL;
	for (size_t pos = 0; pos < vectorSize; pos++)
	{
		//chek if exist sign is in the even positions
		if (pos % 2 == 0 && (split[pos] == "+" || split[pos] == "-" || split[pos] == "/" || split[pos] == "*"))
		{
			throw std::exception("ERROR");
		}
		else
		{
			//take and convert number from the vector
			double num;
			if (isInt(split[pos]))
				num = static_cast<double>(convertToInt(split[pos]));
			else if (isFloat(split[pos]))
				num = convertToFloat(split[pos]);
			else if (Spreadsheet::getInstance().isValidCell(split[pos]))
			{
				try
				{
					const CellType * cell = Spreadsheet::getInstance().operator[](split[pos]);
					if (cell == NULL)
						num = 0;
					else if (cell->type() == "formula")
						num = calcFormula(cell->stringCell());
					else
						num = cell->value();
				}
				catch (...)
				{
					//cell out of range
					num = 0;
				}
			}
			else
				throw std::exception("ERROR");

			if (pos == 0)
				result = num;
			if (sign == '+')
				result += num;
			else if (sign == '-')
				result -= num;
			else if (sign == '/')
			{
				if (num)
					result /= num;
				else
					throw std::exception("ERROR");
			}
			else if (sign == '*')
				result *= num;
			++pos;
		}

		//chek if the sign is in the true position
		if (pos < vectorSize && pos % 2 == 1 && (split[pos] != "+" && split[pos] != "-" && split[pos] != "/" && split[pos] != "*"))
			throw std::exception("ERROR");
		else if (pos < vectorSize)
			sign = split[pos][0];
	}
	return result;
}

void  Command::edit(String index, String newValue) const
{
	CellType * type;
	try
	{
		type = convertToCellType(newValue);
		Spreadsheet::getInstance().changeCell(index, type);
	}
	catch (const std::exception& e)
	{
		String mess = "Error " + newValue;
		mess += e.what();
		throw std::exception(mess.c_str());
	}
	delete type;
}


/// Add empty row. First argument specifies the number of the new rows.
void Command::addEmptyRow(size_t addNewRow) const
{
	unsigned oldRowSize = Spreadsheet::getInstance().row();
	unsigned newRowSize = oldRowSize + addNewRow;
	unsigned colSize = Spreadsheet::getInstance().col();

	CellType *** buffer = new CellType**[newRowSize];

	///Copy old Table
	for (unsigned row = 0; row < oldRowSize; row++)
	{
		buffer[row] = new CellType*[colSize];
		for (unsigned col = 0; col < colSize; col++)
		{
			if (Spreadsheet::getInstance().takeCell(row,col) == NULL)
				buffer[row][col] = NULL;
			else
				buffer[row][col] = Spreadsheet::getInstance().takeCell(row, col)->clone();
		}
	}

	//Insert Empty row
	for (unsigned row = oldRowSize; row < newRowSize; row++)
	{
		buffer[row] = new CellType*[colSize];
		for (unsigned col = 0; col < colSize; col++)
			buffer[row][col] = NULL;
	}
	Spreadsheet::getInstance().setCells(buffer, newRowSize, colSize);
	//Clean buffer
	for (size_t i = 0; i < newRowSize; i++)
	{
		for (size_t j = 0; j < colSize; j++)
		{
			delete buffer[i][j];
		}
		delete[] buffer[i];
	}
	delete[] buffer;

}

/// Add empty columns,. First argument specifies the number of the columns.
void Command::addEmptyCol(size_t addNewCol) const
{
	unsigned rowSize = Spreadsheet::getInstance().row();
	unsigned oldColSize = Spreadsheet::getInstance().col();
	unsigned newColSize = oldColSize + addNewCol;

	if (rowSize == 0)
		throw std::exception("This Spreadsheet is empty. Please, first add a row!");

	CellType *** buffer = new CellType**[rowSize];

	//Copy old Table
	for (unsigned row = 0; row < rowSize; row++)
	{
		buffer[row] = new CellType*[newColSize];

		for (unsigned col = 0; col < oldColSize; col++)
		{
			if (Spreadsheet::getInstance().takeCell(row, col) == NULL)
				buffer[row][col] = NULL;
			else
				buffer[row][col] = Spreadsheet::getInstance().takeCell(row, col)->clone();
		}
	}

	//Insert Empty col
	for (unsigned row = 0; row < rowSize; row++)
	{
		for (unsigned col = oldColSize; col < newColSize; col++)
			buffer[row][col] = NULL;
	}
	Spreadsheet::getInstance().setCells(buffer, rowSize, newColSize);
	//Clean buffer
	for (size_t i = 0; i < rowSize; i++)
	{
		for (size_t j = 0; j < newColSize; j++)
		{
			if(buffer[i][j] != NULL)
				delete buffer[i][j];
		}
		delete[] buffer[i];
	}
	delete[] buffer;
}


