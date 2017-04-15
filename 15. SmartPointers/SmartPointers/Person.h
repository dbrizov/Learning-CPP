#pragma once
#include <string>
#include <memory>

using std::string;
using std::shared_ptr;
using std::weak_ptr;

class Person
{
public:
	Person(string name);
	~Person();

	string GetName() const;
	void SetName(string name);

	void MakeFriend(shared_ptr<Person> someFriend);
	bool HasFriend() const;

private:
	string name;
	//shared_ptr<Person> someFriend;

	// We need to use a weak_ptr instad of shared_ptr, because:
	// 1. P1 and P2 are shared pointers
	// 2. P1 is friend of P2
	// 3. P2 is friend of P1
	// 4. From (1)(2)(3) => we have cycling referencing, and the shared pointers count will never go below 1, thus P1 and P2 will never be destroyed.
	// 5. The weak pointer doesn't have ownership of an object like the shared pointer. It only allows access to that object.
	//    Also, if the object the weak pointer is pointing too is destroyed, the weak pointer will become empty.
	//    We can check if a weak pointer is empty by the "weakPtr.expired()" function.
	//    If we want to access the methods of the object being pointed to we need to first lock the pointer by the "weakPtr.lock()" function
	//    Which is equivalent to "expired() ? shared_ptr<T>() : shared_ptr<T>(*this)".
	weak_ptr<Person> someFriend;
};

