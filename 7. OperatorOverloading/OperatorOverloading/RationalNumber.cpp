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

	this->Reduce();
}

RationalNumber RationalNumber::operator+(const RationalNumber& other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	result.Reduce();

	return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber& other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
	result.denominator = this->denominator * other.denominator;

	result.Reduce();

	return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber& other)
{
	RationalNumber result;
	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;

	result.Reduce();

	return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber& other)
{
	if (other.numerator == 0)
	{
		throw DivideByZeroException("Divide by zero: result undefined");
	}

	RationalNumber result;
	result.numerator = this->numerator * other.denominator;
	result.denominator = this->denominator * other.numerator;

	result.Reduce();

	return result;
}

bool RationalNumber::operator==(const RationalNumber& other)
{
	bool areEqual =
		this->numerator == other.numerator &&
		this->denominator == other.denominator;

	return areEqual;
}

bool RationalNumber::operator!=(const RationalNumber& other)
{
	return !(*this == other);
}

bool RationalNumber::operator<(const RationalNumber& other)
{
	float thisAsFloat = (float) (*this);
	float otherAsFloat = (float) other.numerator / other.denominator;

	return thisAsFloat < otherAsFloat;
}

bool RationalNumber::operator>(const RationalNumber& other)
{
	float thisAsFloat = (float) (*this);
	float otherAsFloat = (float) other.numerator / other.denominator;

	return thisAsFloat > otherAsFloat;
}

bool RationalNumber::operator<=(const RationalNumber& other)
{
	return !(*this > other);
}

bool RationalNumber::operator>=(const RationalNumber& other)
{
	return !(*this < other);
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

void RationalNumber::Reduce()
{
	int gcd = RationalNumber::FindGreatestCommonDivisor(this->numerator, this->denominator);
	this->numerator /= gcd;
	this->denominator /= gcd;
}
