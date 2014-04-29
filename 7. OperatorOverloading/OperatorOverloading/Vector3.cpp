#include "Vector3.h"
#include <math.h>
#include <string>

using std::string;
using std::to_string;

const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);

Vector3::Vector3() : Vector3(0.0f, 0.0f, 0.0f)
{

}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::Dot(const Vector3& lhs, const Vector3& rhs)
{
	float dotProduct = (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
	return dotProduct;
}

Vector3 Vector3::Cross(const Vector3& lhs, const Vector3& rhs)
{
	float x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	float y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	float z = (lhs.x * rhs.y) - (lhs.y * rhs.x);

	return Vector3(x, y, z);
}

float Vector3::Magnitude()
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::Normalized()
{
	Vector3 normalized;

	float magnitude = this->Magnitude();
	normalized.x = this->x / magnitude;
	normalized.y = this->y / magnitude;
	normalized.z = this->z / magnitude;

	return normalized;
}

string Vector3::ToString()
{
	string xAsString = to_string(this->x);
	string yAsString = to_string(this->y);
	string zAsString = to_string(this->z);

	int bufferLength = xAsString.length() + yAsString.length() + yAsString.length() + 7;
	char* buffer = new char[bufferLength];
	sprintf_s(buffer, bufferLength, "(%.2f, %.2f, %.2f)", this->x, this->y, this->z);

	string result = buffer;
	delete buffer;

	return result;
}

float* Vector3::ToFloatArray()
{
	return &(this->x);
}

Vector3::operator float *()
{
	return this->ToFloatArray();
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;

	return result;
}

Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;

	return result;
}

Vector3 Vector3::operator*(float scalar)
{
	Vector3 result;
	result.x = this->x * scalar;
	result.y = this->y * scalar;
	result.z = this->z * scalar;

	return result;
}

Vector3 Vector3::operator/(float scalar)
{
	Vector3 result;
	result.x = this->x / scalar;
	result.y = this->y / scalar;
	result.z = this->z / scalar;

	return result;
}

Vector3 operator*(float scalar, const Vector3& vector)
{
	Vector3 result;
	result.x = vector.x * scalar;
	result.y = vector.y * scalar;
	result.z = vector.z * scalar;

	return result;
}

bool Vector3::operator==(const Vector3& rhs)
{
	bool areEqual =
		this->x == rhs.x &&
		this->y == rhs.y &&
		this->z == rhs.z;

	return areEqual;
}

bool Vector3::operator!=(const Vector3& rhs)
{
	bool notEqual = !(*this == rhs);
	return notEqual;
}
