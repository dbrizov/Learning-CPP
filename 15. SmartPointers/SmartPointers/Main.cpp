#include <iostream>
#include <memory>
#include "Person.h"

using std::shared_ptr;
using std::make_shared;

void main()
{
	// Shared pointers
	shared_ptr<Person> person1 = shared_ptr<Person>(new Person("Person 1")); // The shared_ptr managed the raw Person pointer, so it can be auto destroyed
	person1.use_count(); // The number of pointers pointing to person1. When the count becomes 0, person1 will be destroyed
	person1.get(); // The raw pointer of person1

	shared_ptr<Person> person2 = make_shared<Person>("Person 2"); // The same as the above but exception safe

	shared_ptr<int> arr = shared_ptr<int>(new int[3]); // The shared_ptr will delete only arr[0]. arr[1] and arr[2] will leak
	shared_ptr<int> arr2 = shared_ptr<int>(new int[3], [](int* ptr) { delete[] ptr; }); // Custome deleted that will delete the whole array

	// Weak pointers
	{
		shared_ptr<Person> person3 = make_shared<Person>("Person 3");
		person1->MakeFriend(person3);
		person1->HasFriend();
	}

	person1->HasFriend();
}
