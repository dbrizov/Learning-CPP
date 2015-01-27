#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "Table.h"
#include "Student.h"

using namespace std;

// Template function
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

// Template constraints
// For more info: http://www.stroustrup.com/bs_faq2.html#constraints
template <class TDerived, class TBase>
struct DerivedFrom
{
	static void Constraints(TDerived* derived)
	{
		// Checks if TDerived* can be implicitly cast to TBase*
		// If at compile time the cast is successful, that means that TDerived is really derived from TBase
		TBase* base = derived; 
	}

	DerivedFrom()
	{
		// In the constructor by assigning a function pointer, we trigger the check of the constraints
		void(*func)(TDerived*) = &Constraints;
	}
};

template <typename TPerson>
void PrintNameOfPerson(TPerson object)
{
	DerivedFrom<TPerson, Person> isTPersonDerivedFromPerson; // This triggers the check if TPerson is derived from Person

	cout << object.GetName() << endl;
}

int main()
{
	// --- Some operations with the Table class ---
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

	// --- Template constraints ---
	Person person("Denis Rizov");
	Student student("Chris Rizov");

	PrintNameOfPerson(person);
	PrintNameOfPerson(student);

	int number = 9;
	//PrintNameOfPerson(number); // This line does not compile, because "int" is not derived from "Person"
}