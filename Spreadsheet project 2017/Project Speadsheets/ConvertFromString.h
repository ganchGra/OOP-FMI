/// Description of the help functions
/**
 * Help functions:
 *      -  checks the string if it is a specific type
 *      -  convert from String to number
 */

#pragma once

#include"stdafx.h"

///Checks the string if it is a specific type
bool isInt(const String src);
bool isFloat(const String src);

///
///Formula can contain:
///      - cell - R<value>C<value> 
///      - integer
///      - double
///      - sign - '+', '-', '/' , '*'
///
bool isFormula(const String src);

/// String is surrounded with ""
bool isString(const String src);

///Convert from String to number
double convertToNum(const String src);
int convertToInt(const String src);
double convertToFloat(const String src);

