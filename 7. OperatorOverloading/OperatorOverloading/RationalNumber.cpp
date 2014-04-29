#include "RationalNumber.h"
#include "DivideByZeroException.h"
#include <iostream>

RationalNumber::RationalNumber() : RationalNumber(0, 1)
{
}

RationalNumber::RationalNumber(int numerator, int denominator)
{
	try
	{
		if (denominator == 0)
		{
			throw DivideByZeroException("Divide by zero: result undefined");
		}

		this->numerator = numerator;
		this->denominator = denominator;
	}
	catch (DivideByZeroException& ex)
	{
		std::cout << ex.GetMessage() << std::endl;
	}
}
