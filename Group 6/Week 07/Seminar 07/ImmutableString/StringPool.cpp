#include "StringPool.h"

void StringPool::free()
{
	for (int i = 0; i < capacity; i++)
	{
		delete[] records[i].str; //if the class is used correctly all strings will be deleted by this point.
	}
	delete[] records;
}

void StringPool::resize(int newCap)
{
	StringRecord* temp = new StringRecord[newCap];
	for (int i = 0; i < size; i++)
	{
		temp[i] = records[i]; //here a shallow copy is made (so we don't reallocate the strings)
	}
	delete[] records; //the array is deleted, but not the strings (the constructor of the StringRecord doesn't delete the string)
	records = temp;
	capacity = newCap;
}

void StringPool::allocateString(const char* str)
{
	if (size == capacity) {
		resize(capacity * 2);
	}

	int length = strlen(str);
	records[size].str = new char[length + 1];
	strcpy(records[size].str, str);
	records[size].refCount = 1;
	size++;
	
}

int StringPool::findString(const char* str) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(records[i].str, str) == 0) {
			return i;
		}
	}
	return -1; //not such string!!
}

void StringPool::removeRecord(int index)
{
	std::swap(records[index], records[size - 1]);
	delete[] records[size - 1].str;
	records[size - 1].str = nullptr;
	records[size - 1].refCount = 0;
	size--;
}

StringPool::StringPool()
{
	records = new StringRecord[capacity];
}

const char* StringPool::getString(const char* str)
{
	int index = findString(str);
	if (index == -1) { //no such string in the collection -> we should allocate
		allocateString(str);
		return records[size - 1].str;
	}
	else { //the string is found
		records[index].refCount++;
		return records[index].str;
	}
}

void StringPool::removeString(const char* str)
{
	int index = findString(str); // already in pool

	records[index].refCount--;
	if (records[index].refCount == 0) {
		removeRecord(index);
	}
}

int StringPool::getRefCount(const char* str)
{
	int index = findString(str);
	return records[index].refCount;
}

void StringPool::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << records[i].str << " " << records[i].refCount<<endl;
	}
}

StringPool::~StringPool()
{
	free();
}
