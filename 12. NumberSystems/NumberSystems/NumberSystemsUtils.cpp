#include "NumberSystemsUtils.h"
#include <math.h>
#include <sstream>

unsigned int NumberSystemsUtils::BinaryToDecimal(const string& binaryNumber)
{
	unsigned int decimalNumber = 0;

	for (int i = 0; i < binaryNumber.length(); i++)
	{
		if (binaryNumber[i] == '1')
		{
			decimalNumber += powf(2.0f, binaryNumber.length() - 1 - i);
		}
	}

	return decimalNumber;
}

string NumberSystemsUtils::DecimalToBinary(unsigned int decimalNumber)
{
	string binaryNumber = "";

	while (decimalNumber != 0)
	{
		string nextBit = std::to_string(decimalNumber % 2);
		binaryNumber = nextBit + binaryNumber;

		decimalNumber /= 2;
	}

	return binaryNumber;
}

unsigned int NumberSystemsUtils::HexadecimalToDecimal(const string& hexadecimalNumber)
{
	int hexNumLength = hexadecimalNumber.length();
	int decimalNumber = 0;

	for (int i = 0; i < hexNumLength; i++)
	{
		if (hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9')
		{
			decimalNumber += (hexadecimalNumber[i] - '0') * (int) powf(16.0f, hexNumLength - i - 1);
		}
		else if (hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f')
		{
			decimalNumber += (hexadecimalNumber[i] - 87) * (int) powf(16.0f, hexNumLength - i - 1);
		}
		else if (hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F')
		{
			decimalNumber += (hexadecimalNumber[i] - 55) * (int) powf(16.0f, hexNumLength - i - 1);
		}
	}

	return decimalNumber;
}

string NumberSystemsUtils::DecimalToHexadecimal(unsigned int decimalNumber)
{
	string hexadecimalNumber = "";

	while (decimalNumber != 0)
	{
		int remainder = decimalNumber % 16;

		std::stringstream stringStream;

		if (remainder >= 0 && remainder <= 9)
		{
			stringStream << (char) (remainder + 48);
		}
		else if (remainder >= 10 && remainder <= 15)
		{
			stringStream << (char) (remainder + 55);
		}

		string nextChar;
		stringStream >> nextChar;

		hexadecimalNumber = nextChar + hexadecimalNumber;

		decimalNumber /= 16;
	}

	return hexadecimalNumber;
}
