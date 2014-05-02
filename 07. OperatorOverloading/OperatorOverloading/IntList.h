#ifndef INT_LIST_H
#define INT_LIST_H

class IntList
{
public:
	IntList();
	IntList(int capacity);
	IntList(const IntList& other);
	~IntList();

	IntList& operator=(const IntList& other);
	int& operator[](int index);

	int Count();
	int Capacity();

	void Add(int item);
	void RemoveAt(int index);
	void Clear();
	void TrimExcess();

private:
	static const int DEFAULT_CAPACITY = 4;

	int* items;
	int count;
	int capacity;

	void DoubleCapacity();
};

#endif // INT_LIST_H
