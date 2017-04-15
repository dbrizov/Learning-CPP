#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;

Person::Person(string name)
{
	cout << "Person Created: " << name << endl;
	this->name = name;
}

Person::~Person()
{
	cout << "Person Destroyed: " << name << endl;
}

string Person::GetName() const
{
	return this->name;
}

void Person::SetName(string name)
{
	this->name = name;
}

void Person::MakeFriend(shared_ptr<Person> someFriend)
{
	this->someFriend = someFriend;
}

bool Person::HasFriend() const
{
	if (!this->someFriend.expired())
	{
		cout << this->GetName() << " has a friend named " << this->someFriend.lock()->GetName() << endl;
		return true;
	}
	else
	{
		cout << this->GetName() << " doens't have a friend" << endl;
		return false;
	}
}
