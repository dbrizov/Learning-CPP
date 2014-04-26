#include <iostream>
#include <string>
#include <math.h>
#include "ArithmeticOperators.h"

using namespace std;

void main()
{
	// -- Exercise 1 - Arithmetic Operators --
	float firstNum;
	cout << "First number = ";
	cin >> firstNum;
	
	float secondNum;
	cout << "Second number = ";
	cin >> secondNum;

	cout << firstNum << " + " << secondNum << " = " << ArithmeticOperators::SumNumbers(firstNum, secondNum) << endl;
	cout << firstNum << " - " << secondNum << " = " << ArithmeticOperators::DifferenceNumbers(firstNum, secondNum) << endl;
	cout << firstNum << " * " << secondNum << " = " << ArithmeticOperators::MultiplyNumbers(firstNum, secondNum) << endl;
	cout << firstNum << " / " << secondNum << " = " << ArithmeticOperators::DivideNumbers(firstNum, secondNum) << endl;

	// -- Exercise 2 --
	string firstName;
	string lastName;

	cout << "Enter first and last name: ";
	cin >> firstName >> lastName;
	cout << "Your name: " << firstName + " " + lastName << endl;

	// -- Exercise 3 --
	float number;
	cout << "Enter real number: ";
	cin >> number;
	cout << number << "^3 = " << pow(number, 3) << endl;

	// -- Exercise 4 --
	const float PI = acos(-1);
	float radius;
	cout << "Radius: ";
	cin >> radius;
	cout << "Area: " << PI * radius * radius << endl;
	cout << "Perimeter: " << 2 * PI * radius << endl;
}