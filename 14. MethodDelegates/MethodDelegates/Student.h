#pragma once

#include <string>
#include "Person.h"

using std::string;

class Student : public Person
{
public:
	Student(string name, int age, float grade);
	Student(const Student& other);
	virtual ~Student();

	Student& operator=(const Student& other);

	float GetGrade() const;
	void SetGrade(float grade);

	virtual string ToString() const override;

private:
	float grade;
};
