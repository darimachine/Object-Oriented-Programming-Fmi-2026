#pragma once
#include<print>

class MultiSet
{
private:
	static constexpr size_t DEFAULT_N = 0;
	unsigned char* data{0};
	size_t n=0;

	void copyFrom(const MultiSet& other);
	void free();
	void resize(size_t newN);

public:
	MultiSet();

	MultiSet(size_t n);

	MultiSet(const MultiSet& other);

	MultiSet& operator=(const MultiSet& other);

	~MultiSet();

	void addNum(unsigned num);

	void removeNum(unsigned num);

	unsigned countNum(unsigned num)const;

	void printAll()const;

	static MultiSet getUnion(const MultiSet& first, const MultiSet& second);

	static MultiSet getIntersection(const MultiSet& first, const MultiSet& second);
};

