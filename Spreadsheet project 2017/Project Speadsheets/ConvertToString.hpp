

/// template for conversion to String from any no floating number
template<typename T>
String to_string(T val)
{
	String buffer;
	if (val == 0)
	{
		buffer += '0';
		return buffer;
	}
	char sign = NULL;
	if (val < 0)
	{
		sign = '-';
		val *= -1;
	}

	//save number on the reverse part
	while (val)
	{
		T rest = val % 10;
		val /= 10;
		char singleNum = rest + '0';
		buffer += singleNum;
	}
	//reverse number
	buffer.reverse();

	return (sign == NULL) ? buffer : sign + buffer;
}
