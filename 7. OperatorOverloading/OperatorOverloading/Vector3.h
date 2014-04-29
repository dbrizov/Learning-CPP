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

	static float Dot(const Vector3& lhs, const Vector3& rhs);
	static Vector3 Cross(const Vector3& lhs, const Vector3& rhs);

	float Magnitude();
	Vector3 Normalized();
	string ToString();
	float* ToFloatArray();
	operator float*();
	Vector3 operator+(const Vector3& rhs);
	Vector3 operator-(const Vector3& rhs);
	Vector3 operator*(float scalar);
	Vector3 operator/(float scalar);
	bool operator==(const Vector3& rhs);
	bool operator!=(const Vector3& rhs);
};

Vector3 operator*(float scalar, const Vector3& vector);

#endif // VECTOR3_H
