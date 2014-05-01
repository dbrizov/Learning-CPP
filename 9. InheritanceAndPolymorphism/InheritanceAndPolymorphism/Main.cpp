#include <iostream>
#include <vector>
#include <string>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
	vector<IShape*> shapes;

	// Add 5 circles
	int circlesCount = 5;
	for (int i = 0; i < circlesCount; i++)
	{
		shapes.push_back(new Circle(i + 1));
	}

	// Add 5 Rectangles
	int rectanglesCount = 5;
	for (int i = 0; i < rectanglesCount; i++)
	{
		shapes.push_back(new Rectangle((i + 1) * 2, (i + 1) * 3));
	}

	// Test polymorphism
	for (int i = 0; i < shapes.size(); i++)
	{
		cout << "Type: " << shapes[i]->GetType() << endl;
		cout << "Area: " << shapes[i]->GetArea() << endl;
		cout << "Perimeter: " << shapes[i]->GetPerimeter() << endl;
		cout << endl;
	}

	// Delete the shapes
	for (int i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}