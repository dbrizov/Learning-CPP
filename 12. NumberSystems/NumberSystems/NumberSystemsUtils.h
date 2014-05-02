#ifndef NUMBER_SYSTEMS_UTILS_H
#define NUMBER_SYSTEMS_UTILS_H

#include <string>

using std::string;

class NumberSystemsUtils
{
public:
	static unsigned int BinaryToDecimal(const string& binaryNumber);
	static string DecimalToBinary(unsigned int decimalNumber);
	static unsigned int HexadecimalToDecimal(const string& hexadecimalNumber);
	static string DecimalToHexadecimal(unsigned int decimalNumber);

private:
	NumberSystemsUtils();
};

#endif // NUMBER_SYSTEMS_UTILS_H
