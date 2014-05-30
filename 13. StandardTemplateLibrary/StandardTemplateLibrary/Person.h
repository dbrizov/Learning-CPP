#pragma once

#include <string>

class Person
{
public:
	Person(std::string name, int age);
	Person(const Person& other);
	~Person();

	Person& operator=(const Person& other);

	std::string GetName() const;
	void SetName(std::string name);
	int GetAge() const;
	void SetAge(int age);

	std::string ToString() const;

private:
	std::string name;
	int age;
};

