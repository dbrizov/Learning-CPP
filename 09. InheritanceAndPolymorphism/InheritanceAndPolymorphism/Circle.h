#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h";

class Circle : public IShape
{
public:
	Circle(float radius);
	virtual ~Circle();

	virtual string GetType();
	virtual float GetArea();
	virtual float GetPerimeter();

private:
	float radius;
};

#endif // CIRCLE_H
