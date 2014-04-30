#include "RationalNumber.h"
#include "DivideByZeroException.h"
#include <iostream>
#include <math.h>

using std::to_string;

RationalNumber::RationalNumber() : RationalNumber(0, 1)
{
}

RationalNumber::RationalNumber(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw DivideByZeroException("Divide by zero: result undefined");
	}

	this->numerator = numerator;
	this->denominator = denominator;

	RationalNumber::Reduce(*this);
}

RationalNumber RationalNumber::operator+(RationalNumber other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	RationalNumber::Reduce(result);

	return result;
}

RationalNumber RationalNumber::operator-(RationalNumber other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	RationalNumber::Reduce(result);

	return result;
}

RationalNumber RationalNumber::operator*(RationalNumber other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;

	RationalNumber::Reduce(result);

	return result;
}

RationalNumber RationalNumber::operator/(RationalNumber other)
{
	if (other.numerator == 0)
	{
		throw DivideByZeroException("Divide by zero: result undefined");
	}

	RationalNumber result;
	result.numerator = this->numerator * other.denominator;
	result.denominator = this->denominator * other.numerator;

	RationalNumber::Reduce(result);

	return result;
}

RationalNumber::operator float()
{
	return (float)this->numerator / this->denominator;
}

RationalNumber::operator double()
{
	return (double)this->numerator / this->denominator;
}

string RationalNumber::ToString()
{
	string result = to_string(this->numerator) + "/" + to_string(this->denominator);
	return result;
}

int RationalNumber::FindGreatestCommonDivisor(int number1, int number2)
{
	number1 = abs(number1);
	number2 = abs(number2);

	if (number1 == 0)
	{
		return number2;
	}

	if (number2 == 0)
	{
		return number1;
	}

	// Euclid's algorithm for GCD.
	while (number1 != number2)
	{
		if (number1 > number2)
		{
			number1 -= number2;
		}
		else
		{
			number2 -= number1;
		}
	}

	return number1;
}

void RationalNumber::Reduce(RationalNumber& rational)
{
	int gcd = RationalNumber::FindGreatestCommonDivisor(rational.numerator, rational.denominator);
	rational.numerator /= gcd;
	rational.denominator /= gcd;
}
