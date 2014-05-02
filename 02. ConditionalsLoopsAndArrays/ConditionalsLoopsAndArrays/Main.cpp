#include <iostream>

using namespace std;

float getAverage(float *arr, int arrLength);
long getFactorial(int number);
void outputASCII();
void printArray(int *arr, int arrLength);
int linearSearch(int *arr, int arrLength, int element);
void selectionSort(int *arr, int arrLength);

int main()
{
	cout.setf(ios::boolalpha);

	// -- Exercise 1 (Average) --
	cout << "-- Exercise 1 (Average) --" << endl;
	float arr [] = { 1, 2, 3, 4, 5 };
	float average = getAverage(arr, 5);
	cout << "Average: " << average << endl << endl;

	// -- Exercise 2 (Factorial) --
	cout << "-- Exercise 2 (Factorial) --" << endl;
	int number = 5;
	cout << "Factorial: " << getFactorial(number) << endl << endl;

	// -- Exercise 3 (ASCII) --
	cout << "-- Exercise 3 (ASCII) --" << endl;
	outputASCII();
	cout << endl;

	// -- Exercise 4 (Linear Search) --
	cout << "-- Exercise 4 (Linear Search) --" << endl;
	int elements [] = { 7, 3, 32, 2, 55, 34, 6, 13, 29, 22, 11, 9, 1, 5, 42, 39, 8 };
	int elementsCount = 17;

	printArray(elements, elementsCount);

	int searchElement;
	cout << "Search for element: ";
	cin >> searchElement;
	cout << "Index: " << linearSearch(elements, elementsCount, searchElement) << endl << endl;

	// -- Exercise 5 (Selection Sort) --
	cout << "-- Exercise 5 (Selection Sort) --" << endl;
	int unsortedArray [] = { 1, 5, 2, 4, 3 };
	int unsortedArrayLength = 5;

	cout << "Unsorted: ";
	printArray(unsortedArray, unsortedArrayLength);

	selectionSort(unsortedArray, unsortedArrayLength);

	cout << "Sorted: ";
	printArray(unsortedArray, unsortedArrayLength);
}

float getAverage(float *arr, int arrLength)
{
	float sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		sum += arr[i];
	}

	float average = sum / arrLength;
	return average;
}

long getFactorial(int number)
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

void outputASCII()
{
	for (int i = 0; i <= 255; i++)
	{
		cout << i << ": " << (char) i << endl;
	}
}

void printArray(int* arr, int arrLength)
{
	cout << "[ ";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << "]" << endl;
}

int linearSearch(int *arr, int arrLength, int element)
{
	int index = -1;

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == element)
		{
			index = i;
			break;
		}
	}

	return index;
}

void selectionSort(int *arr, int arrLength)
{
	for (int i = 0; i < arrLength - 1; i++)
	{
		int indexOfMinElement = i;
		for (int j = i + 1; j < arrLength; j++)
		{
			if (arr[j] < arr[indexOfMinElement])
			{
				indexOfMinElement = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[indexOfMinElement];
		arr[indexOfMinElement] = temp;
	}
}