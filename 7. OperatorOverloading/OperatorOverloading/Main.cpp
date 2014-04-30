#include <iostream>
#include "Vector3.h"
#include "String.h"
#include "RationalNumber.h"
#include "DivideByZeroException.h"

using namespace std;

int main()
{
	cout.setf(ios::boolalpha);

	try
	{
		RationalNumber rat1(2, 4);
		RationalNumber rat2(3, 4);

		cout << "rat1 = " << rat1.ToString() << endl;
		cout << "rat2 = " << rat2.ToString() << endl;
		cout << "(float)rat1 = " << (float) rat1 << endl;
		cout << "(double)rat2 = " << (double) rat2 << endl;
		cout << endl;

		cout << "rat1 + rat2 = " << (rat1 + rat2).ToString() << endl;
		cout << "rat1 - rat2 = " << (rat1 - rat2).ToString() << endl;
		cout << "rat1 * rat2 = " << (rat1 * rat2).ToString() << endl;
		cout << "rat1 / rat2 = " << (rat1 / rat2).ToString() << endl;
	}
	catch (DivideByZeroException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	//Vector3 vector(1, 2, 3);
	//Vector3 vector2(5, 6, 7);
	//Vector3 vector3(5, 6, 7);

	//cout << "v1 = " << vector.ToString() << endl;
	//cout << "v2 = " << vector2.ToString() << endl;
	//cout << "v3 = " << vector3.ToString() << endl;
	//cout << endl;

	//cout << "v1 + v2 = " << (vector + vector2).ToString() << endl;
	//cout << "v1 - v2 = " << (vector - vector2).ToString() << endl;
	//cout << "v2 + v1 = " << (vector2 + vector).ToString() << endl;
	//cout << "v2 - v1 = " << (vector2 - vector).ToString() << endl;
	//cout << "v1 * 10.0f = " << (vector * 10.0f).ToString() << endl;
	//cout << "10.0f * v1 = " << (10.0f * vector).ToString() << endl;
	//cout << "v1 / 10.0f = " << (vector / 10.0f).ToString() << endl;
	//cout << "v1 == v2: " << (vector == vector2) << endl;
	//cout << "v2 == v3: " << (vector2 == vector3) << endl;
	//cout << "v1 != v2: " << (vector != vector2) << endl;
	//cout << "v2 != v3: " << (vector2 != vector3) << endl;
}