#include "Student.h"
#include <string>

using std::string;
using std::to_string;


Student::Student(string name, int age, float grade)
: Person(name, age)
{
	this->SetGrade(grade);
}

Student::Student(const Student& other)
	: Student(other.GetName(), other.GetAge(), other.GetGrade())
{

}

Student::~Student()
{

}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		Person::operator=(other);

		this->SetGrade(other.GetGrade());
	}

	return *this;
}

float Student::GetGrade() const
{
	return this->grade;
}

void Student::SetGrade(float grade)
{
	this->grade = grade;
}

string Student::ToString() const
{
	string result = "[Student: Name=" + this->GetName();
	result += ", Age=" + to_string(this->GetAge());
	result += ", Grade=" + to_string(this->GetGrade()) + "]";

	return result;
}
