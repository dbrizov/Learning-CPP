#include <iostream>
#include "Vector3.h"

using namespace std;

int main()
{
	Vector3* vector = new Vector3(3, 4, 0);

	cout << vector->Magnitude() << endl;
	cout << vector->Normalized().Magnitude() << endl;
	cout << vector->Magnitude() << endl;

	delete vector;
}