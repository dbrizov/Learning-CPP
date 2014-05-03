#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

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

int main()
{
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
}