#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include <string>

class RationalNumber
{
public:
	RationalNumber();
	RationalNumber(int numerator, int denominator);

	RationalNumber operator+(RationalNumber fraction);
	RationalNumber operator-(RationalNumber fraction);
	RationalNumber operator*(RationalNumber fraction);
	RationalNumber operator/(RationalNumber fraction);
	bool operator==(RationalNumber fraction);
	bool operator!=(RationalNumber fraction);
	bool operator<(RationalNumber fraction);
	bool operator>(RationalNumber fraction);
	bool operator<=(RationalNumber fraction);
	bool operator>=(RationalNumber fraction);
	operator float();
	operator double();

	std::string ToString();

private:
	int numerator;
	int denominator;
};

#endif // RATIONAL_NUMBER_H
