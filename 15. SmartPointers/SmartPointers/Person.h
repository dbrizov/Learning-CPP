#pragma once
#include <string>

using std::string;

class Person
{
public:
	Person(string name);
	~Person();

	string GetName() const;
	void SetName(string name);

private:
	string name;
};

