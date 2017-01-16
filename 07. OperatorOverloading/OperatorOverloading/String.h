#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
	friend std::ostream& operator<<(std::ostream& os, const String& str);

	String();
	String(const char* cstr);
	String(const String& str);
	String(String&& str);
	~String();

	String& operator=(const String& str);
	String& operator=(String&& str);
	char& operator[](int index);

	int Length();

private:
	char* data;
	int length;

	void Create(const char* cstr);
	void Delete();
};

std::ostream& operator<<(std::ostream& os, const String& str);

#endif // STRING_H
