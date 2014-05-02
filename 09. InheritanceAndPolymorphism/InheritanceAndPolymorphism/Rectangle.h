#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle(float width, float height);

	string GetType();
	float GetArea();
	float GetPerimeter();

private:
	float width;
	float height;
};

#endif // RECTANGLE_H
