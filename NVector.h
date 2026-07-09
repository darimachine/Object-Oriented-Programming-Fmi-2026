#pragma once
#include <functional>
#include <iostream>
#include <compare>

class NVector
{
private:
	int* data = nullptr;
	int size;

	void copyFrom(const NVector&);
	void free();
	void resize(int);

public:

	NVector();
	NVector(int);
	NVector(const int*, int);

	NVector(const NVector&);
	NVector& operator=(const NVector&);
	~NVector();

	NVector& operator+=(const NVector&);
	NVector& operator-=(const NVector&);
	NVector& operator*=(int);

	int operator~() const;

	const int& operator[](int)const;
	int& operator[](int);

	operator bool()const;

	NVector& operator++();
	NVector operator++(int dummy);

	NVector operator()(const std::function<int(int)>&) const;

	friend std::ostream& operator<<(std::ostream&, const NVector&);
	friend std::istream& operator>>(std::istream&, NVector&);

	std::strong_ordering operator<=>(const NVector&) const;
};

NVector operator+(const NVector&, const NVector&);
NVector operator-(const NVector&, const NVector&);
NVector operator*(const NVector&, int);
NVector operator*(int, const NVector&);

int operator%(const NVector&, const NVector&);

bool operator|(const NVector&, const NVector&);

bool operator||(const NVector&, const NVector&);

bool operator==(const NVector&, const NVector&);
bool operator<(const NVector&, const NVector&);

bool operator!=(const NVector&, const NVector&);
bool operator> (const NVector&, const NVector&);
bool operator<=(const NVector&, const NVector&);
bool operator>=(const NVector&, const NVector&);


