#include <iostream>
#include <vector>
#include "IndexOutOfRangeException.h";

using namespace std;

int main()
{
	try
	{
		vector<int> vector;
		vector.push_back(1);
		vector.push_back(2);
		vector.push_back(3);
		vector.push_back(4);
		vector.push_back(5);

		for (int i = 0; i < vector.size(); i++)
		{
			cout << vector[i] << " ";
		}

		cout << endl << endl;;
		
		int index;
		cout << "index: ";
		cin >> index;

		if (index < 0 || index >= vector.size())
		{
			throw IndexOutOfRangeException();
		}
		else
		{
			cout << vector[index] << endl;;
		}
	}
	catch (IndexOutOfRangeException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
}