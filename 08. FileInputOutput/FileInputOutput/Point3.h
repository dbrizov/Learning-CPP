#ifndef POINT3_H
#define POINT3_H

#include <string>

using std::string;

struct Point3
{
	float x;
	float y;
	float z;

	Point3();
	Point3(float x, float y, float z);

	string ToString();
};

#endif //POINT3_H