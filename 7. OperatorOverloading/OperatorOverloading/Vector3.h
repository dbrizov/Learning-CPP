#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

using std::string;

class Vector3
{
public:
	static const Vector3 ZERO;

	float x;
	float y;
	float z;

	Vector3();
	Vector3(float x, float y, float z);

	static float Dot(const Vector3& v1, const Vector3& v2);
	static Vector3 Cross(const Vector3& v1, const Vector3& v2);

	float Magnitude();
	Vector3 Normalized();
	string ToString();
};

#endif // VECTOR3_H
