#include "Person.h"

Person::Person() : Person("", 0)
{
}

Person::Person(string name, int age)
{
	this->SetName(name);
	this->SetAge(age);
}

Person::~Person()
{
}

string Person::GetName()
{
	return this->name;
}

void Person::SetName(string name)
{
	this->name = name;
}

int Person::GetAge()
{
	return this->age;
}

void Person::SetAge(int age)
{
	if (age >= 0)
	{
		this->age = age;
	}
	else
	{
		throw "The age must have a zero or positive value";
	}
}

string Person::ToString()
{
	string result = "[Name: " + this->name + ", Age: " + to_string(this->age) + "]";
	return result;
}
