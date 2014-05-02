#include <iostream>
#include "Vector3.h"
#include "RationalNumber.h"
#include "DivideByZeroException.h"
#include "IntList.h";
#include "IndexOutOfRangeException.h";

using namespace std;

void PrintIntList(IntList& list)
{
	for (int i = 0; i < list.Count(); i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
}

int main()
{
	cout.setf(ios::boolalpha);

	// -- RationalNumber --
	cout << "-- RationalNumber -- " << endl;

	try
	{
		RationalNumber rat1(2, 4);
		RationalNumber rat2(3, 4);
		RationalNumber rat3(1, 2);

		cout << "rat1 = " << rat1.ToString() << endl;
		cout << "rat2 = " << rat2.ToString() << endl;
		cout << "rat3 = " << rat3.ToString() << endl;
		cout << "(float)rat1 = " << (float) rat1 << endl;
		cout << "(double)rat2 = " << (double) rat2 << endl;
		cout << endl;

		cout << "rat1 + rat2 = " << (rat1 + rat2).ToString() << endl;
		cout << "rat1 - rat2 = " << (rat1 - rat2).ToString() << endl;
		cout << "rat1 * rat2 = " << (rat1 * rat2).ToString() << endl;
		cout << "rat1 / rat2 = " << (rat1 / rat2).ToString() << endl;
		cout << "rat1 == rat3 ? " << (rat1 == rat3) << endl;
		cout << "rat1 != rat3 ? " << (rat1 != rat3) << endl;
		cout << "rat1 < rat2 ? " << (rat1 < rat2) << endl;
		cout << "rat1 > rat2 ? " << (rat1 > rat2) << endl;
		cout << "rat1 <= rat3 ? " << (rat1 <= rat3) << endl;
		cout << "rat1 >= rat3 ? " << (rat1 >= rat3) << endl;
		cout << "rat1 <= rat2 ? " << (rat1 <= rat2) << endl;
		cout << "rat1 >= rat2 ? " << (rat1 >= rat2) << endl << endl;;
	}
	catch (DivideByZeroException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// -- Vector 3 --
	cout << "-- Vector3 --" << endl;

	Vector3 vector1(1, 2, 3);
	Vector3 vector2(5, 6, 7);
	Vector3 vector3(5, 6, 7);

	cout << "v1 = " << vector1.ToString() << endl;
	cout << "v2 = " << vector2.ToString() << endl;
	cout << "v3 = " << vector3.ToString() << endl;
	cout << endl;

	cout << "v1 + v2 = " << (vector1 + vector2).ToString() << endl;
	cout << "v1 - v2 = " << (vector1 - vector2).ToString() << endl;
	cout << "v2 + v1 = " << (vector2 + vector1).ToString() << endl;
	cout << "v2 - v1 = " << (vector2 - vector1).ToString() << endl;
	cout << "v1 * 10.0f = " << (vector1 * 10.0f).ToString() << endl;
	cout << "10.0f * v1 = " << (10.0f * vector1).ToString() << endl;
	cout << "v1 / 10.0f = " << (vector1 / 10.0f).ToString() << endl;
	cout << "v1 == v2: " << (vector1 == vector2) << endl;
	cout << "v2 == v3: " << (vector2 == vector3) << endl;
	cout << "v1 != v2: " << (vector1 != vector2) << endl;
	cout << "v2 != v3: " << (vector2 != vector3) << endl;
	cout << "Dot(v1, v2) = " << Vector3::Dot(vector1, vector2) << endl;
	cout << "Cross(v1, v2) = " << Vector3::Cross(vector1, vector2).ToString() << endl << endl;

	// -- IntList --
	cout << "-- IntList --" << endl;

	try
	{
		IntList list1 = IntList();
		cout << "Count: " << list1.Count() << endl;
		cout << "Capacity: " << list1.Capacity() << endl;

		cout << "Adding 5 items..." << endl;
		for (int i = 0; i < 5; i++)
		{
			list1.Add(i);
		}

		cout << "Count: " << list1.Count() << endl;
		cout << "Capacity: " << list1.Capacity() << endl;
		PrintIntList(list1);

		cout << "Remove item at index = 2" << endl;
		list1.RemoveAt(2);
		cout << "Count: " << list1.Count() << endl;
		cout << "Capacity: " << list1.Capacity() << endl;
		PrintIntList(list1);
	}
	catch (IndexOutOfRangeException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
}