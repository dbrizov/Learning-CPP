#ifndef ISHAPE_H
#define ISHAPE_H

#include <string>

using std::string;

class IShape
{
public:
	virtual string GetType() = 0;
	virtual float GetArea() = 0;
	virtual float GetPerimeter() = 0;
};

#endif ISHAPE_H