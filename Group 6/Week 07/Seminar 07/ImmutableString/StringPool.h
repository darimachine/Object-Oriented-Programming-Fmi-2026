#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
class StringPool
{

	struct StringRecord {
		char* str = nullptr;
		int refCount = 0;
	
	};

	StringRecord* records=nullptr;
	int size = 0;
	int capacity = 8;
	
	void free();
	void resize(int newCap);

	void allocateString(const char* str);

	int findString(const char* str) const;

	void removeRecord(int index);
public:

	StringPool();
	const char* getString(const char* str);
	void removeString(const char* str);

	//test
	int getRefCount(const char* str);

	void print() const;


	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();
};

