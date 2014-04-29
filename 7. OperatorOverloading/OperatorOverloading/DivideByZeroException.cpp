#include "DivideByZeroException.h"

DivideByZeroException::DivideByZeroException(const string& message)
{
	this->message = message;
}

string DivideByZeroException::GetMessage()
{
	return this->message;
}
