#include"stdafx.h"

School::School()
{
}

School::~School()
{
	delete[] m_name;
}