#include <iostream>
#include <memory>
#include "Person.h"

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
using std::cout;
using std::endl;

void main()
{
	// Shared pointers
	shared_ptr<Person> person1 = shared_ptr<Person>(new Person("Person 1")); // The shared_ptr managed the raw Person pointer, so it can be auto destroyed
	person1.use_count(); // The number of pointers pointing to person1. When the count becomes 0, person1 will be destroyed
	person1.get(); // The raw pointer of person1

	shared_ptr<Person> person2 = make_shared<Person>("Person 2"); // The same as the above but exception safe

	//person1 = nullptr; // person1 will be destroyed
	//person1 = person2; // person1 will be destroyed
	//person1.reset();   // person1 will be destroyed

	shared_ptr<int> arr = shared_ptr<int>(new int[3]); // The shared_ptr will delete only arr[0]. arr[1] and arr[2] will leak
	shared_ptr<int> arr2 = shared_ptr<int>(new int[3], [](int* ptr) { delete[] ptr; }); // Custome deleter that will delete the whole array

	// Weak pointers
	{
		shared_ptr<Person> person3 = make_shared<Person>("Person 3");
		person1->MakeFriend(person3);
		person1->HasFriend();
	}

	person1->HasFriend();

	// Unique pointers - unique pointer is the same as shared, but the object can be owned by only 1 unique pointer. It is also more lightweight
	unique_ptr<Person> person4 = make_unique<Person>("Person 4");
	unique_ptr<Person> person5 = make_unique<Person>("Person 5");

	cout << person4->GetName() << endl;
	person4 = std::move(person5);
	// We moved the ownership of person5 to person4 thus:
	// 1. Person 5 is destroyed
	// 2. person5 is empty pointer
	// 2. person4 now owns Person 5
	cout << person4->GetName() << endl;

	// Unique pointers also don't need custom deleters
	unique_ptr<Person[]> people = unique_ptr<Person[]>(new Person[3]);
}
