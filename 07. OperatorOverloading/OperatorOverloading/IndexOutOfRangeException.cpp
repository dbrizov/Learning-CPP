#include "IndexOutOfRangeException.h"

IndexOutOfRangeException::IndexOutOfRangeException(const string& message)
{
	this->message = message;
}

string IndexOutOfRangeException::GetMessage()
{
	return this->message;
}
