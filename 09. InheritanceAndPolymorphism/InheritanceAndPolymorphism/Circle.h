#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h";

class Circle : public IShape
{
public:
	Circle(float radius);
	virtual ~Circle();

	virtual string GetType() override;
	virtual float GetArea() override;
	virtual float GetPerimeter() override;

private:
	float radius;
};

#endif // CIRCLE_H
