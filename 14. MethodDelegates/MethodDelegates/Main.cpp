#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "MethodDelegate.h"

using namespace std;

/** Pointer to method of class Person that has no parameters and returns string */
typedef TMethodDelegate<Person>::NoParams<string>::TMethodPtr_Const GetStringMethodPtr_Const;

/** Pointer to method of class Person that has one string parameter and returns void */
typedef TMethodDelegate<Person>::OneParam<void, string>::TMethodPtr SetStringMethodPtr;

/** Pointer to method of class Person that has no parameters and returns int */
typedef TMethodDelegate<Person>::NoParams<int>::TMethodPtr_Const GetIntMethodPtr_Const;

/** Pointer to method of class Person that has one integer parameter and returns void */
typedef TMethodDelegate<Person>::OneParam<void, int>::TMethodPtr SetIntMethodPtr;

/** Pointer to method of class Student that has no parameters and returns float */
typedef TMethodDelegate<Student>::NoParams<float>::TMethodPtr_Const GetFloatMethodPtr_Const;

/** Pointer to method of class Student that has one float parameter and returns void */
typedef TMethodDelegate<Student>::OneParam<void, float>::TMethodPtr SetFloatMethodPtr;

void main()
{
	// -- Initialize the delegates --
	GetStringMethodPtr_Const GetNameMethodPtr_Const = &Person::GetName;
	SetStringMethodPtr SetNameMethodPtr = &Person::SetName;

	GetIntMethodPtr_Const GetAgeMethodPtr_Const = &Person::GetAge;
	SetIntMethodPtr SetAgeMethodPtr = &Person::SetAge;

	GetFloatMethodPtr_Const GetGradeMethodPtr_Const = &Student::GetGrade;
	SetFloatMethodPtr SetGradeMethodPtr = &Student::SetGrade;

	GetStringMethodPtr_Const ToStringMethodPtr_Const = &Person::ToString;

	// The code below does not compile:
	// cannot convert from 'float (__thiscall Student::* )(void) const' to 'float (__thiscall Person::* )(void) const
	// cannot convert from 'void (__thiscall Student::* )(float)' to 'void (__thiscall Person::* )(TParam0)
	//TMethodDelegate<Person>::NoParams<float>::TMethodPtr_Const AnotherGetGradeMethodPtr_Const = &Student::GetGrade;
	//TMethodDelegate<Person>::OneParam<void, float>::TMethodPtr AnotherSetGradeMethodPtr = &Student::SetGrade;

	// -- Create a student and test the delegates --
	Student* student = new Student("Name", 20, 6.0f); // The student is a person

	// ToString is virtual
	cout << (student->*ToStringMethodPtr_Const)() << endl;

	(student->*SetNameMethodPtr)("Denis Rizov");
	(student->*SetAgeMethodPtr)(22);
	(student->*SetGradeMethodPtr)(2.0f);

	cout << (student->*GetNameMethodPtr_Const)() << endl;
	cout << (student->*GetAgeMethodPtr_Const)() << endl;
	cout << (student->*GetGradeMethodPtr_Const)() << endl;

	cout << (student->*ToStringMethodPtr_Const)() << endl;

	delete student;

	// The code below works regardless of the fact that the
	// GetStringMethodPtr_Const is of type string(Person::*)() const
	// and we are assigning it to type of string(Student::*)() const
	// This is possible because the addresses of Person::GetName and Student::Getname
	// are actually one and the same.
	// However this is valid only for non-virtual methods, and it's not a very good
	// idea such code to be writen in production. DON'T DO THIS AT HOME!!!
	// The initializations on lines 44 and 45 don't compile, bacause class
	// Person does not have a method "float GetGrade() const" - this is another situation
	GetStringMethodPtr_Const AnotherGetNameMethodPtr_Const = &Student::GetName;
	//GetStringMethodPtr_Const AnotherToStringMethodPtr_Const = &Student::ToString; // This does not compile, because ToString is virtual and has been overriden.
	                                                                                // Cannot convert from 'std::string (__thiscall Student::* )(void) const' to 'std::string (__thiscall Person::* )(void) const'
	                                                                                // This is the third situation

	string* PersonGetNamePtr = (string*&) GetNameMethodPtr_Const; // Pointer to Person::GetName
	string* StudentGetNamePtr = (string*&) AnotherGetNameMethodPtr_Const; // Pointer to Student::GetName

	// The pointers are equal
	cout << PersonGetNamePtr << endl;
	cout << StudentGetNamePtr << endl;

	Person person("Chris", 22);
	cout << (person.*AnotherGetNameMethodPtr_Const)() << endl;
}