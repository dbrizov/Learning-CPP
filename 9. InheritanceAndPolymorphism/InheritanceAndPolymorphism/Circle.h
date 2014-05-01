#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h";

class Circle : public IShape
{
public:
	Circle(float radius);

	string GetType();
	float GetArea();
	float GetPerimeter();

private:
	float radius;
};

#endif // CIRCLE_H
