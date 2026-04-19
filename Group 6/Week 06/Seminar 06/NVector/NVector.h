#pragma once
#include <iostream>
#include <functional>
#include <compare>

using namespace std;
class NVector
{
	int* data=nullptr;
	int size = 0;

	void free();
	void copyFrom(const NVector& other);
	void resize(int newSize);

	NVector& calculate(const NVector& other, const std::function<int(int, int)>& f);

public:
	NVector();
	explicit NVector(int size);
	NVector(const int* data, int size);

	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	NVector& operator+=(const NVector& other);
	NVector& operator-=(const NVector& other);

	//scalar
	NVector& operator*=(int scalar);

	const int& operator[](int index) const;
	int& operator[](int index);

	int operator~() const;

	operator bool() const;

	NVector& operator++();

	NVector operator++(int dummy);

	NVector operator()(const std::function<int(int)>& func) const;

	friend ostream& operator<<(ostream& os, const NVector& v);
	friend istream& operator>>(istream& is, NVector& v);

	std::strong_ordering operator<=>(const NVector& other) const;

	
};


//bool operator<(const NVector& lhs, const NVector& rhs);
//bool operator==(const NVector& lhs, const NVector& rhs);
//bool operator!=(const NVector& lhs, const NVector& rhs);

NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);

NVector operator*(const NVector& v, int scalar);
NVector operator*(int scalar, const NVector& v);

int operator%(const NVector& lhs, const NVector& rhs);

bool operator|(const NVector& lhs, const NVector& rhs);

bool operator||(const NVector& lhs, const NVector& rhs);
