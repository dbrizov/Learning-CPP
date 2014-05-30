#include "Person.h"
#include <string>
#include <iostream>

Person::Person(std::string name, int age)
{
	this->SetName(name);
	this->SetAge(age);
}

Person::Person(const Person& other)
	: Person(other.name, other.age)
{
}

Person::~Person()
{
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->SetName(other.name);
		this->SetAge(other.age);
	}

	return *this;
}

std::string Person::GetName() const
{
	return this->name;
}

void Person::SetName(std::string name)
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

std::string Person::ToString() const
{
	std::string result = "[Name: " + this->name;
	result += ", Age: " + std::to_string(this->age) + "]";

	return result;
}
