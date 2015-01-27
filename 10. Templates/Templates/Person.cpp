#include "Person.h"

Person::Person()
	: Person("")
{
}

Person::Person(string name)
{
	this->name = name;
}

Person::~Person()
{
}

string Person::GetName() const
{
	return this->name;
}

void Person::SetName(string name)
{
	this->name = name;
}

