#include "Circle.h"

const float PI = 3.14159f;

Circle::Circle(float radius)
{
	this->radius = radius;
}

string Circle::GetType()
{
	return "Circle";
}

float Circle::GetArea()
{
	return PI * this->radius * this->radius;
}

float Circle::GetPerimeter()
{
	return 2 * PI * this->radius;
}
