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

float Vector3::Dot(const Vector3& v1, const Vector3& v2)
{
	float dotProduct = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return dotProduct;
}

Vector3 Vector3::Cross(const Vector3& v1, const Vector3& v2)
{
	float x = (v1.y * v2.z) - (v1.z * v2.y);
	float y = (v1.z * v2.x) - (v1.x * v2.z);
	float z = (v1.x * v2.y) - (v1.y * v2.x);

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
