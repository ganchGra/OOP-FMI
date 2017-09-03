#include"stdafx.h"

///Checks the string if it is a specific type
bool isInt(const String src)
{
	if (src.c_str() == NULL)
		return false;
	
	size_t size = src.lenght();
	size_t pos = 0;
	
	// check if have sign
	if (src[pos] == '+' || src[pos] == '-')
		pos = 1;

	for (pos; pos < size; pos++)
	{
		//check if symbol is number
		if (src[pos] < '0' || src[pos] > '9')
			return false;
	}

	return true;
}
bool isFloat(const String src)
{
	if (src.c_str() == NULL)
		return false;
	
	size_t srcSize = src.lenght();
	size_t pos = 0;

	// check if have sign
	if (src[pos] == '+' || src[pos] == '-')
		pos = 1;

	//check if the first symbol is a number
	if (src[pos] < '0' || src[pos] > '9')
		return false;

	++pos;
	//before decimal point
	do
	{
		// fount the first dot
		if (src[pos] == '.')
		{
			pos++;
			break;
		}

		//check if the symbol befor the first dot is number
		if (src[pos] < '0' || src[pos] > '9')
			return false;

		pos++;
	} while (pos < srcSize);

	// break if current position is equal of the source size -> does not exit number after dot
	if (pos == srcSize)
		return false;

	//after decimal point
	do
	{
		//if have a second dot the number is not valid
		if (src[pos] == '.')
			return false;
		//if is not a number
		if (src[pos] < '0' || src[pos] > '9')
			return false;
		pos++;
	} while (pos < srcSize);

	return true;
}
bool isString(const String src)
{
	if (src.c_str() == NULL)
		return false;
	
	size_t srcSize = src.lenght();
	//for the both ""
	if (srcSize < 2)
		return false;
	if (src[0] == '"' && src[srcSize - 1] == '"')
		return true;

	return false;
}
bool isFormula(const String src) 
{
	size_t SrcSize = src.lenght();
	//Minumum size 2 =<value>
	if (SrcSize <= 1)
		return false;

	bool haveSign = false;
	if (src[0] == '=')
		haveSign = true;

	if (haveSign)
	{
		size_t pos = 1;
		//escape whitespaces
		for (pos; src[pos] == ' ' && pos < SrcSize; pos++)
		{}

		for (pos; pos < SrcSize; pos++)
		{
			bool isNum = src[pos] >= '0' && src[pos] <= '9';
			bool isSign = src[pos] == '+'|| src[pos] == '-' || src[pos] == '/' || src[pos] == '*';
			bool cellIndication = src[pos] == 'R' || src[pos] == 'C';
			if (!(src[pos] == ' ') && !cellIndication &&  !isNum && !isSign)
				return false;
		}
		return true;
	}

	return false;
}

///Convert from String to number
double convertToNum(const String src) 
{
	// Defaut value of the String
	double number = 0;

	if (isInt(src))
	{
		number = static_cast<double>(convertToInt(src));
	}
	else if (isFloat(src))
	{
		number = convertToFloat(src);
	}
	else if (isString(src))
	{
		String text;
		size_t len = src.lenght();
		//escape ""
		for (size_t i = 1; i < len - 1; i++)
			text += src[i];

		//check if the content of the String is a number value and convert it
		if (isInt(text))
			number = static_cast<double>(convertToInt(text));
		else if (isFloat(text))
			number = convertToFloat(text);
	}

	return number;
}
int convertToInt(const String src) 
{
	if (!isInt(src))
		throw std::exception("Is not integer type!");
	
	int number = 0;

	size_t srcSize = src.lenght();
	char sign = NULL;
	size_t pos = 0;
	if (src[pos] == '+')
	{
		sign = '+';
		++pos;
	}
	else if (src[pos] == '-')
	{
		sign = '-';
		++pos;
	}

	unsigned decimal = srcSize - 1;

	for (pos; pos < srcSize; pos++)
	{
		number += static_cast<int>((src[pos] - '0') * pow(10, decimal));
		--decimal;
	}
	if (sign == '-')
		number *= -1;

	return number;
}
double convertToFloat(const String src) 
{
	if (!isFloat(src))
	{
		throw std::exception("Is not float type!");
	}
	double number = 0;

	size_t srcSize = src.lenght();
	//take sign if exist
	char sign = NULL;
	size_t pos = 0;
	if (src[pos] == '+')
	{
		sign = '+';
		++pos;
	}
	else if (src[pos] == '-')
	{
		sign = '-';
		++pos;
	}

	//take tot number befor dot
	unsigned partBeforeDot = 0;
	unsigned totalNumBeforDot = 0;
	size_t count = 0;
	while (src[count] != '.')
	{
		++totalNumBeforDot;
		++count;
	}
	//take tot number after dot
	unsigned partAfterDot = 0;
	unsigned totalNumAfterDot = 0;
	++count;
	while (count < srcSize)
	{
		++totalNumAfterDot;
		++count;
	}
	unsigned copyTotalNumAfterDot = totalNumAfterDot;

	//take number the before decimal point
	do
	{
		partBeforeDot += static_cast<int>((src[pos] - '0')*pow(10, totalNumBeforDot - 1));
		--totalNumBeforDot;
		++pos;
	} while (totalNumBeforDot);

	++pos;

	//take number the after decimal point
	do
	{
		partAfterDot += static_cast<int>((src[pos] - '0')*pow(10, totalNumAfterDot - 1));
		--totalNumAfterDot;
		++pos;
	} while (totalNumAfterDot);

	double resAfterDot = partAfterDot / pow(10, copyTotalNumAfterDot);


	///Final result
	number = partBeforeDot + resAfterDot;
	if (sign == '-')
		number *= -1;

	return number;
}

