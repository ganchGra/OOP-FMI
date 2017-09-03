/// Class Command description
/**
 * Convert String into Spreadsheet command task and command argument and execute the command
 *
 * ************************************************************************************************************************************************************ *
 *  Spreadsheet support only a comma-separated values (CSV) files.
 *
 *  Available Spreadsheet commands:
 *  - open <PathToFile>                    - Open specified file, given as the first argument. If the file does not exist then it's been created.
 *  - close                                - Closes an already opened file without saving any changes in it.
 *                                           Close does not exit the program. If no file has been opened, you get an ERROR.
 *  - save                                 - Saves data in the opened file. If no file has been opened, you get an ERROR.
 *  - saveas <PathToFile>                  - Saves data in the specified file, given as the first argument. If no file has been opened, you get an ERROR.
 *  - print                                - Prints files data on console window. If no file has been opened, you get an ERROR.
 *  - edit R<value>C<value> <NewCellValue> - Changes value in given cell. First argument specifies row and column of the cell.
 *                                           Second argument specifies the new cell value. Valids data types are: <integer>, <double>, \"<string>\", =<formula>.
 *  - add [row|col] <unsigned>             - Add empty row or column. Second argument specifies the number of the new rows or columns.
 *  - exit                                 - Exit the program without saving any changes in opened file, if there is one.
 *  - help                                 - Prints available commands info.
 *************************************************************************************************************************************************************** */
#pragma once
#include"stdafx.h"

class Command
{
public:
	/// Default constructor
	Command();


	/// Copy constructor
	Command(const Command& rhs);


	/// Create new obj from String
	Command(const String text);


	/// Create new obj from char array
	Command(const char* text);


	/// Create new obj from single character
	Command(const char symbol);


	/// Destructor
	~Command();

	
	/// Assign from Command obj
	Command& operator=(const Command& rhs);

	/// Assign from String
	Command& operator=(const String& rhs);

	/// Assign from char array
	Command& operator=(const char* rhs);

	/// Assign from signle character
	Command& operator=(char symbol);

	
	/// Return command task
	String task() const;


	/// Return command argument
	String commandArg() const;

	
	/// Clear command task and argument
	void clear();

public:
	///
	/// Set Command values from different sources
	///
	void set(const String text);
	void set(const char* text);
	void set(const char symbol);

public:
	/// Execute the Spreadsheet command
	void execute() const;

private:
	/// Convert String into CellType
	CellType* convertToCellType(const String src) const;

	/* Command menu */
	void help() const;

	/// Open specified file, given as the first argument.
	void open(String fileName) const;
	
	/// Closes an already opened file
	void close() const;
	
	/// Saves data in the opened file
	void save() const;
	
	/// Saves data in the specified file, given as the first argument
	void saveAs(String FileName) const;
	
	/// Prints files data on console window
	void print() const;
	
	/// Changes value in given cell
	/** First and second arguments specifies row and column of the cell.
		Third argument specifies the new cell value. 
		Valids data types are: <integer>, <double>, \"<string>\", =<formula>. */
	void edit(String index, String newValue) const;
	
	
	/// Add empty row. First argument specifies the number of the new rows.
	void addEmptyRow(size_t addNewRow) const;
	
	/// Add empty columns,. First argument specifies the number of the columns.
	void addEmptyCol(size_t addNewCol)const;

private:
	///
	/// Help function for the print command
	///
	void printWhiteSpace(unsigned number) const;

	///
	///Calculate formula if it is not valid throw exception
	///
	double calcFormula(const String formula) const;
private:
	///
	/// Command task
	///
	String m_task;

	///
	/// Command argument
	///
	String m_taskArg;
};
