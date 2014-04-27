#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	Person* person = new Person("Denis", 22);
	Person* person2 = new Person(*person);

	cout << person << endl;
	cout << person2 << endl;

	person->SetName("Rizov");

	cout << person->ToString() << endl;
	cout << person2->ToString() << endl;

	delete person;
	person = NULL;
	delete person2;
	person2 = NULL;
}