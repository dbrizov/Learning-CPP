#ifndef DIVIDE_BY_ZERO_EXCEPTION_H
#define DIVIDE_BY_ZERO_EXCEPTION_H

#include <string>
using namespace std;

class DivideByZeroException
{
public:
	DivideByZeroException(const string& message);
	string GetMessage();

private:
	string message;
};

#endif // DIVIDE_BY_ZERO_EXCEPTION_H
