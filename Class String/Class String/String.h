#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

class String
{
private:
	char * pStr;
	size_t size;
public:
	String();
	String(const char * str);
	~String();
	String(const String & other);
	String operator=(const String & other);

	const char * getString() const;
	void setString(const char * str);
};

#endif //STRING_H_INCLUDED