#include "Point3.h"

using std::to_string;

Point3::Point3() : Point3(0.0f, 0.0f, 0.0f)
{
}

Point3::Point3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

string Point3::ToString()
{
	string result = "";
	result += "(";
	result += to_string(this->x) + ", ";
	result += to_string(this->y) + ", ";
	result += to_string(this->z) + ")";

	return result;
}
