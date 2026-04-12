#pragma once
#include "StringPool.h"
class ImmutableString
{
	const char* data;
	int size = 0;

	static StringPool pool;
	void free();
	void copyFrom(const ImmutableString& other);
public:

	ImmutableString(const char* text);
	ImmutableString(const ImmutableString& other);
	ImmutableString& operator=(const ImmutableString& other);

	char operator[](int index) const;

	const char* c_str() const;
	int getSize() const;

	int getRefCount() const;
	static void print();
	friend bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
	friend ostream& operator<<(std::ostream& os, const ImmutableString& im);
	~ImmutableString();

};
ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
// >=
// <

