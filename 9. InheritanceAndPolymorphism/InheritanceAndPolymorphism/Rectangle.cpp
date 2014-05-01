#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
{
	this->width = width;
	this->height = height;
}

string Rectangle::GetType()
{
	return "Rectangle";
}

float Rectangle::GetArea()
{
	return this->width * this->height;
}

float Rectangle::GetPerimeter()
{
	return 2 * (this->width + this->height);
}
