#include "IndexOutOfRangeException.h"

IndexOutOfRangeException::IndexOutOfRangeException()
	: IndexOutOfRangeException("Index out of range")
{
}

IndexOutOfRangeException::IndexOutOfRangeException(const string& message)
{
	this->message = message;
}

string IndexOutOfRangeException::GetMessage() const
{
	return this->message;
}
