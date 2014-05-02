#include <iostream>
#include <fstream>
#include <string>
#include "Point3.h"

using namespace std;

int main()
{
	// Write to binary file
	Point3 cube[8];
	cube[0] = Point3(-1.0f, -1.0f, -1.0f);
	cube[1] = Point3(-1.0f, 1.0f, -1.0f);
	cube[2] = Point3(1.0f, 1.0f, -1.0f);
	cube[3] = Point3(1.0f, -1.0f, -1.0f);
	cube[4] = Point3(-1.0f, -1.0f, 1.0f);
	cube[5] = Point3(-1.0f, 1.0f, 1.0f);
	cube[6] = Point3(1.0f, 1.0f, 1.0f);
	cube[7] = Point3(1.0f, -1.0f, 1.0f);

	ofstream fileOutputStream("cube", ios::binary);

	if (fileOutputStream)
	{
		fileOutputStream.write((char*) cube, sizeof(Point3) * 8);

		fileOutputStream.close();
	}

	// Read from binary file
	Point3 copyOfCube[8];
	ifstream fileInputStream("cube", ios::binary);

	if (fileInputStream)
	{
		fileInputStream.read((char*) copyOfCube, sizeof(Point3) * 8);

		fileInputStream.close();
	}

	for (int i = 0; i < 8; i++)
	{
		cout << copyOfCube[i].ToString() << endl;
	}

	// Count the lines of a .txt file
	fileInputStream.open("lines.txt");

	if (fileInputStream)
	{
		int linesCount = 0;
		while (!fileInputStream.eof())
		{
			string line;
			getline(fileInputStream, line);

			linesCount++;
		}

		cout << "Lines count: " << linesCount << endl;

		fileInputStream.close();
	}
}