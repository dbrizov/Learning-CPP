#ifndef INDEX_OUT_OF_RANGE_EXCEPTION_H
#define INDEX_OUT_OF_RANGE_EXCEPTION_H

#include <string>

using std::string;

class IndexOutOfRangeException
{
public:
	IndexOutOfRangeException(const string& message);
	string GetMessage();

private:
	string message;
};

#endif // !INDEX_OUT_OF_RANGE_EXCEPTION_H
