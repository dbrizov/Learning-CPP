#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;

Person::Person(string name)
{
	cout << "Person Created" << endl;
	this->name = name;
}

Person::~Person()
{
	cout << "Person Destroyed" << endl;
}

string Person::GetName() const
{
	return this->name;
}

void Person::SetName(string name)
{
	this->name = name;
}
