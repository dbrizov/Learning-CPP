#include <string.h>
#include "String.h"

String::String() : String("")
{
}

String::String(const char* cstr)
{
	this->Create(cstr);
}

String::String(const String& str)
{
	this->Create(str.data);
}

String::String(String&& str)
{
	this->data = str.data;
	this->length = str.length;

	str.data = nullptr;
	str.length = 0;
}

String::~String()
{
	this->Delete();
}

String& String::operator=(const String& str)
{
	if (this != &str)
	{
		this->Delete();
		this->Create(str.data);
	}

	return *this;
}

String& String::operator=(String&& str)
{
	this->data = str.data;
	this->length = str.length;

	str.data = nullptr;
	str.length = 0;

	return *this;
}

char& String::operator[](int index)
{
	return this->data[index];
}

int String::Length()
{
	return this->length;
}

void String::Create(const char* cstr)
{
	this->length = strlen(cstr);
	this->data = new char[this->length + 1];
	
	for (int i = 0; i < this->length; i++)
	{
		this->data[i] = cstr[i];
	}

	this->data[this->length] = '\0';
}

void String::Delete()
{
	delete [] this->data;
	this->data = NULL;

	this->length = 0;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.data;
	return os;
}
