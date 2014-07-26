#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle(float width, float height);
	virtual ~Rectangle();

	virtual string GetType();
	virtual float GetArea();
	virtual float GetPerimeter();

private:
	float width;
	float height;
};

#endif // RECTANGLE_H
