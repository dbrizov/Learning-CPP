#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include "Person.h"

using namespace std;

class RandomInt
{
public:
	RandomInt(int minInclusive, int maxExclusive)
	{
		this->minInclusive = minInclusive;
		this->maxExclusive = maxExclusive;
	}

	int operator()()
	{
		return this->minInclusive + rand() % (this->maxExclusive - this->minInclusive);
	}

private:
	int minInclusive;
	int maxExclusive;
};

template <typename T>
class DoubleValue
{
public:
	void operator()(T& item)
	{
		item *= 2;
	}
};

template <typename T>
class Print
{
public:
	void operator()(const T& item)
	{
		cout << item << " ";
	}
};

template <typename T>
class DescendingComparer
{
public:
	bool operator()(const T& leftItem, const T& rightItem)
	{
		return leftItem > rightItem;
	}
};

template <typename T>
class AscendingComparer
{
public: 
	bool operator()(const T& leftItem, const T& rightItem)
	{
		return leftItem < rightItem;
	}
};

template <typename T>
class PrintHashCode
{
public:
	void operator()(const T& item)
	{
		cout << item << " -> " << this->hashFunction(item) << endl;
	}

private:
	hash<T> hashFunction;
};

class PersonComparer
{
public:
	bool operator()(const Person& lhs, const Person& rhs)
	{
		return lhs.GetAge() - rhs.GetAge() < 0;
	}
};

int main()
{
	cout << "-- FUNCTORS USAGE --" << endl;
	srand(time(0));

	vector<int> vec;
	vec.resize(10);

	// Generate the vector
	RandomInt randomInt(0, 51);
	generate(vec.begin(), vec.end(), randomInt);

	// Print it
	cout << "Generated:" << endl;
	Print<int> print;
	for_each(vec.begin(), vec.end(), print);
	cout << endl << endl;

	// Double it's values
	DoubleValue<int> doubleValue;
	for_each(vec.begin(), vec.end(), doubleValue);

	// Print it
	cout << "Doubled values:" << endl;
	for_each(vec.begin(), vec.end(), print);
	cout << endl << endl;

	// Reverse it
	reverse(vec.begin(), vec.end());

	// Print it
	cout << "Reversed:" << endl;
	for_each(vec.begin(), vec.end(), print);
	cout << endl << endl;

	// Sort descending
	DescendingComparer<int> descending;
	sort(vec.begin(), vec.end(), descending);

	// Print it
	cout << "Sorted descending:" << endl;
	for_each(vec.begin(), vec.end(), print);
	cout << endl << endl;

	// Sort ascending
	AscendingComparer<int> ascending;
	sort(vec.begin(), vec.end(), ascending);

	// Print it
	cout << "Sorted ascending:" << endl;
	for_each(vec.begin(), vec.end(), print);
	cout << endl << endl;

	// Print the hash codes of all items
	cout << "Hash codes of all items:" << endl;
	PrintHashCode<int> printHashCode;
	for_each(vec.begin(), vec.end(), printHashCode);
	cout << endl;


	// -- Some set operations --
	cout << "-- SET --" << endl;
	set<Person, PersonComparer> mySet; // Use custom comparer

	Person* p1 = new Person("Denis", 4);
	Person* p2 = new Person("Meri", 1);
	Person* p3 = new Person("Kriso", 3);
	Person* p4 = new Person("Bobi", 2);

	mySet.insert(*p1);
	mySet.insert(*p2);
	mySet.insert(*p3);
	mySet.insert(*p4);

	for (set<Person>::iterator i = mySet.begin(); i != mySet.end(); i++)
	{
		cout << i->ToString() << endl;
	}

	delete p1;
	delete p2;
	delete p3;
	delete p4;

	// -- Some map operations --
	cout << endl << "-- MAP --" << endl;

	map<string, int> myMap; // use default comparer for string
	myMap["Tim"] = 23;
	myMap["Vanessa"] = 18;
	myMap["Adam"] = 25;
	myMap["Jennifer"] = 27;
	myMap["Denis"] = 22;
	myMap["Kriso"] = 22;
	
	for (map<string, int>::iterator i = myMap.begin(); i != myMap.end(); ++i)
	{
		cout << "Key = " << i->first << ", ";
		cout << "Age = " << i->second << endl;
	}

	cout << "Denis is " << myMap.find("Denis")->second << " years old" << endl;
}