#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Point
{
	float x;
	float y;
	float z;

	Point(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int Random(int from, int to);
long GetFactorial(int number);
char ToUpperCase(char input);
char ToLowerCase(char input);
float Distance3D(Point from, Point to);
float DegreesToRadians(float degrees);
float RadiansToDegrees(float radians);
float ArcTangent(float y, float x);
int BinarySearch(int arr [], int arrLength, int searchElement);
void PrintArray(int arr [], int arrLength);

int main()
{
	// -- Exercise 1 (Factorial) --
	cout << "-- Exercise 1 (Factorial) --" << endl;
	int number = 5;
	cout << GetFactorial(number) << endl << endl;

	// -- Exercise 2 (ToUpper/ToLower Case) --
	cout << "-- Exercise 2 (ToUpper/ToLower Case) --" << endl;
	char input;
	cout << "Enter an alphabetic character: ";
	cin >> input;
	cout << "Upper case: " << ToUpperCase(input) << endl;
	cout << "Lower case: " << ToLowerCase(input) << endl << endl;

	// -- Exercise 3 (Distance between 3D points) --
	cout << "-- Exercise 3 (Distance between 3D points) --" << endl;
	Point from = Point(3, 4, 0);
	Point to = Point(0, 0, 0);
	cout << "Distance: " << Distance3D(from, to) << endl << endl;

	// -- Exercise 4 (Arc Tangent) --
	cout << "-- Exercise 4 (Arc Tangent) --" << endl;
	cout << ArcTangent(4, 2) << endl;
	cout << ArcTangent(5, -1) << endl;
	cout << ArcTangent(-4, -6) << endl;
	cout << ArcTangent(-6, 4) << endl << endl;

	// -- Exercise 5 (Random) --
	// Random numbers in range [2, 10]
	cout << "-- Exercise 5 (Random) --" << endl;
	srand(time(0));
	int randomNumbersCount = 5;

	for (int i = 0; i < randomNumbersCount; i++)
	{
		cout << Random(2, 11) << endl;
	}

	cout << endl;

	// -- Exercise 5 (Binary Search) --
	cout << "-- Exercise 5 (Binary Search) --" << endl;
	int elements [] = { 1, 4, 5, 6, 9, 14, 21, 23, 28, 31 };
	int elementsCount = 10;
	PrintArray(elements, elementsCount);

	int searchElement;
	cout << "Element to search for: ";
	cin >> searchElement;

	cout << "Index: " << BinarySearch(elements, elementsCount, searchElement) << endl;
}

int Random(int from, int to)
{
	return from + rand() % (to - from);
}

long GetFactorial(int number)
{
	long factorial = 1;

	if (number == 0)
	{
		return factorial;
	}

	for (int i = 1; i <= number; i++)
	{
		factorial *= i;
	}

	return factorial;
}

char ToUpperCase(char input)
{
	char a = 'a';
	char z = 'z';
	char A = 'A';
	char Z = 'Z';
	char upperChar;

	if (input >= A && input <= Z)
	{
		upperChar = input;
	}
	else if (input >= a && input <= z)
	{
		upperChar = input - a + A;
	}
	else
	{
		throw "Not an alphabetic character";
	}

	return upperChar;
}

char ToLowerCase(char input)
{
	char a = 'a';
	char z = 'z';
	char A = 'A';
	char Z = 'Z';
	char lowerChar;

	if (input >= a && input <= z)
	{
		lowerChar = input;
	}
	else if (input >= A && input <= Z)
	{
		lowerChar = input - A + a;
	}
	else
	{
		throw "Not an alphabetic character";
	}

	return lowerChar;
}

float Distance3D(Point from, Point to)
{
	float deltaX = to.x - from.x;
	float deltaY = to.y - from.y;
	float deltaZ = to.z - from.z;

	float distance = sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
	return distance;
}

float DegreesToRadians(float degrees)
{
	const float PI = 3.14159f;
	float radians = (degrees * PI) / 180;
	return radians;
}

float RadiansToDegrees(float radians)
{
	const float PI = 3.14159f;
	float degrees = (radians * 180) / PI;
	return degrees;
}

float ArcTangent(float y, float x)
{
	if (x < 0)
	{
		return RadiansToDegrees(atanf(y / x)) + 180;
	}
	else
	{
		return RadiansToDegrees(atanf(y / x));
	}

	return 0;
}

int BinarySearch(int arr [], int arrLength, int searchElement)
{
	int leftIndex = 0;
	int rightIndex = arrLength - 1;
	int middleIndex;

	while (rightIndex >= leftIndex)
	{
		middleIndex = (rightIndex + leftIndex) / 2;

		if (arr[middleIndex] < searchElement)
		{
			leftIndex = middleIndex + 1;
		}
		else if (arr[middleIndex] > searchElement)
		{
			rightIndex = middleIndex - 1;
		}
		else
		{
			return middleIndex;
		}
	}

	return -1;
}

void PrintArray(int arr [], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;
}