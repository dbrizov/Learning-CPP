#pragma once

#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string name, int age);
	~Person();

	string GetName();
	void SetName(string name);
	int GetAge();
	void SetAge(int age);
	string ToString();

private:
	string name;
	int age;
};
