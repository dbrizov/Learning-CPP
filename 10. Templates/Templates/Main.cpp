#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "Table.h"

using namespace std;

template <typename T>
void SelectionSort(T* arr, int arrLength)
{
	for (int i = 0; i < arrLength - 1; i++)
	{
		int indexOfMinItem = i;

		for (int j = i + 1; j < arrLength; j++)
		{
			if (arr[j] < arr[indexOfMinItem])
			{
				indexOfMinItem = j;
			}
		}

		T temp = arr[i];
		arr[i] = arr[indexOfMinItem];
		arr[indexOfMinItem] = temp;
	}
}

int main()
{
	srand(time(0));

	Table<int>* table = new Table<int>(5, 10);

	for (int row = 0; row < table->GetRows(); row++)
	{
		for (int col = 0; col < table->GetColumns(); col++)
		{
			(*table)(row, col) = rand() % 100;
		}
	}

	// Output the table
	cout << "Original table" << endl;
	for (int row = 0; row < table->GetRows(); row++)
	{
		for (int col = 0; col < table->GetColumns(); col++)
		{
			cout << setw(4) << (*table)(row, col);
		}

		cout << endl;
	}

	// Sort the rows and output the table again
	for (int row = 0; row < table->GetRows(); row++)
	{
		SelectionSort(&(*table)(row, 0), table->GetColumns());
	}

	cout << endl;
	cout << "With sorted rows" << endl;

	for (int row = 0; row < table->GetRows(); row++)
	{
		for (int col = 0; col < table->GetColumns(); col++)
		{
			cout << setw(4) << (*table)(row, col);
		}

		cout << endl;
	}

	delete table;
}