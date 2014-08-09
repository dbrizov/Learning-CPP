#include "Person.h"
#include <string>

using std::string;
using std::to_string;

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
	string result = "[Person: Name=" + this->name;
	result += ", Age=" + to_string(this->age) + "]";

	return result;
}
