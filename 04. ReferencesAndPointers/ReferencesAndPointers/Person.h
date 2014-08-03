#pragma once

#include <string>

using std::string;

class Person
{
public:
	static void StaticFunction();

	Person(string name, int age);
	Person(const Person& other);
	virtual ~Person();

	Person& operator=(const Person& other);

	string GetName() const;
	void SetName(string name);
	int GetAge() const;
	void SetAge(int age);

	virtual string ToString() const;

private:
	string name;
	int age;
};
