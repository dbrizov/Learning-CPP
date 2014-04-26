#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int Random(int from, int to);
void ThrowDice(int& die1, int& die2);
void ThrowDice(int* die1, int* die2);
void RandomArrayFill(int* arr, int size);
void RandomArrayFill(vector<int>& vec, int size);
void PrintArray(int* arr, int size);
void PrintVector(vector<int> vec);

int main()
{
	srand(time(0));

	// -- Exercise 1 (Random Dice) --
	cout << "-- Exercise 1 (Random Dice)--" << endl;
	int die1 = 0;
	int die2 = 0;

	ThrowDice(die1, die2);
	cout << die1 << " & " << die2 << endl;

	ThrowDice(&die1, &die2);
	cout << die1 << " & " << die2 << endl << endl;

	// -- Exercise 2 (Random Array Fill) --
	cout << "-- Exercise 2 (Random Array Fill) --" << endl;

	int arrSize = 10;
	int* arr = new int[arrSize];
	RandomArrayFill(arr, arrSize);

	PrintArray(arr, arrSize);
	delete [] arr;

	vector<int> vec;
	int vecSize = 10;
	RandomArrayFill(vec, vecSize);

	PrintVector(vec);
}

int Random(int from, int to)
{
	return from + rand() % (to - from);
}

void ThrowDice(int& die1, int& die2)
{
	die1 = Random(1, 7);
	die2 = Random(1, 7);
}

void ThrowDice(int* die1, int* die2)
{
	*die1 = Random(1, 7);
	*die2 = Random(1, 7);
}

void RandomArrayFill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = Random(0, 101);
	}
}

void RandomArrayFill(vector<int>& vec, int size)
{
	for (int i = 0; i < size; i++)
	{
		vec.push_back(Random(0, 101));
	}
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void PrintVector(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;
}