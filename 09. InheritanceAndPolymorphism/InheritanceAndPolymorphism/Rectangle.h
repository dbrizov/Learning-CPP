#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape
{
public:
	Rectangle(float width, float height);
	virtual ~Rectangle();

	virtual string GetType() override;
	virtual float GetArea() override;
	virtual float GetPerimeter() override;

private:
	float width;
	float height;
};

#endif // RECTANGLE_H
