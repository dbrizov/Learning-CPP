#include "IntList.h"
#include "IndexOutOfRangeException.h"

IntList::IntList() : IntList(IntList::DEFAULT_CAPACITY)
{
}

IntList::IntList(int capacity)
{
	this->items = new int[capacity];
	this->count = 0;
	this->capacity = capacity;
}

IntList::IntList(const IntList& other)
{
	this->capacity = other.capacity;
	this->count = other.count;

	this->items = new int[this->capacity];
	for (int i = 0; i < this->count; i++)
	{
		this->items[i] = other.items[i];
	}
}

IntList::~IntList()
{
	delete [] this->items;
	this->items = 0;
}

IntList& IntList::operator=(const IntList& other)
{
	if (this != &other)
	{
		delete [] this->items;
		this->items = 0;

		this->capacity = other.capacity;
		this->count = other.count;

		this->items = new int[this->capacity];
		for (int i = 0; i < this->count; i++)
		{
			this->items[i] = other.items[i];
		}
	}

	return *this;
}

int& IntList::operator[](int index)
{
	if (index < 0 || index >= this->count)
	{
		throw IndexOutOfRangeException("Invalid index: the index is out of the range ot the list");
	}

	return this->items[index];
}

int IntList::Count()
{
	return this->count;
}

int IntList::Capacity()
{
	return this->capacity;
}

void IntList::Add(int item)
{
	if (this->count == this->capacity)
	{
		this->DoubleCapacity();
	}

	this->items[count] = item;
	this->count++;
}

void IntList::RemoveAt(int index)
{
	if (index < 0 || index >= this->count)
	{
		throw IndexOutOfRangeException("Invalid index: the index is out of the range ot the list");
	}

	int* itemsCopy = new int[this->count];
	for (int i = 0; i < this->count; i++)
	{
		itemsCopy[i] = this->items[i];
	}

	delete [] this->items;
	this->items = new int[this->capacity];

	// copy from [0, index - 1]
	for (int i = 0; i < index; i++)
	{
		this->items[i] = itemsCopy[i];
	}

	// copy from [index + 1, this.Count]
	for (int i = index + 1; i < this->count; i++)
	{
		this->items[i - 1] = itemsCopy[i];
	}

	delete [] itemsCopy;

	this->count--;
}

void IntList::Clear()
{
	*this = IntList();
}

void IntList::TrimExcess()
{
	int* itemsCopy = new int[this->count];
	for (int i = 0; i < this->count; i++)
	{
		itemsCopy[i] = this->items[i];
	}

	delete [] this->items;
	
	this->items = itemsCopy;
}

void IntList::DoubleCapacity()
{
	int* itemsCopy = new int[this->count];
	for (int i = 0; i < this->count; i++)
	{
		itemsCopy[i] = this->items[i];
	}

	this->capacity *= 2;
	
	delete [] this->items;
	this->items = new int[this->capacity];
	for (int i = 0; i < this->count; i++)
	{
		this->items[i] = itemsCopy[i];
	}

	delete [] itemsCopy;
}
