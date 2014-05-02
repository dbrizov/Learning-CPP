#include <iostream>
#include <string>
#include "NumberSystemsUtils.h"

using namespace std;

int main()
{
	// Binary To Decimal
	string binaryNumber;
	cout << "Enter binary number: ";
	cin >> binaryNumber;

	cout << binaryNumber + " in decimal: " << NumberSystemsUtils::BinaryToDecimal(binaryNumber) << endl;
	cout << endl;

	// Decimal To Binary
	unsigned int decimalNumber;
	cout << "Enter decimal number: ";
	cin >> decimalNumber;

	cout << decimalNumber << " in binary: " << NumberSystemsUtils::DecimalToBinary(decimalNumber) << endl;
	cout << endl;

	// Hexadecimal To Decimal
	string hexadecimalNumber;
	cout << "Enter hexadecimal number: ";
	cin >> hexadecimalNumber;

	cout << hexadecimalNumber + " in decimal: " << NumberSystemsUtils::HexadecimalToDecimal(hexadecimalNumber) << endl;
	cout << endl;

	// Decimal To Hexadecimal
	cout << "Enter decimal number: ";
	cin >> decimalNumber;

	cout << decimalNumber << " in hexadecimal: " << NumberSystemsUtils::DecimalToHexadecimal(decimalNumber) << endl;
	cout << endl;
}