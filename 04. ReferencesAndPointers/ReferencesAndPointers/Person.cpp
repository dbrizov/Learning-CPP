#include "Person.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::to_string;

void Person::StaticFunction()
{
	cout << "StaticFunction executed!" << endl;
}

Person::Person(string name, int age)
{
	this->SetName(name);
	this->SetAge(age);
}

Person::Person(const Person& other)
{
	this->SetName(other.GetName());
	this->SetAge(other.GetAge());
}

Person::~Person()
{
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->SetName(other.GetName());
		this->SetAge(other.GetAge());
	}

	return *this;
}

string Person::GetName() const
{
	return this->name;
}

void Person::SetName(string name)
{
	this->name = name;
}

int Person::GetAge() const
{
	return this->age;
}

void Person::SetAge(int age)
{
	this->age = age;
}

string Person::ToString() const
{
	string result = "[Person: Name=";
	result += this->name;
	result += ", Age=" + to_string(this->age) + "]";

	return result;
}
