#include "MultiSet.h"

MultiSet::MultiSet() :n(DEFAULT_N)
{
	data = new unsigned char[DEFAULT_N] {};
}

MultiSet::MultiSet(size_t n) :n(n)
{
	data = new unsigned char[n] {};
}

void MultiSet::copyFrom(const MultiSet& other)
{
	n = other.n;
	data = new unsigned char[n] {};

	for (size_t i = 0; i < n; i++)
	{
		data[i] = other.data[i];
	}
}

MultiSet::MultiSet(const MultiSet& other)
{
	copyFrom(other);
}

void MultiSet::free()
{
	delete[]data;
	data = nullptr;
	n = DEFAULT_N;
}

MultiSet& MultiSet::operator=(const MultiSet& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);
	
	return *this;
}

MultiSet::~MultiSet()
{
	delete[]data;
	data = nullptr;
}

void MultiSet::resize(size_t newN)
{
	unsigned char* newData = new unsigned char[newN] {};

	size_t minSize = (n < newN) ? n : newN;

	for (size_t i = 0; i < minSize; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	n = newN;
}

void MultiSet::addNum(unsigned num)
{
	if (num >= n)
	{
		resize(num + 1);
	}

	if (data[num] < 3)
	{
		data[num]++;
	}
	else
	{
		std::println("Max count reached for {}", num);
	}

}

void MultiSet::removeNum(unsigned num)
{
	if (num >= n)
	{
		return;
	}

	if (data[num] > 0)
	{
		data[num]--;
	}
}

unsigned MultiSet::countNum(unsigned num)const
{
	if (num >= n)
	{
		return 0;
	}

	return data[num];
}

void MultiSet::printAll()const
{
	for (size_t i = 0;i < n;i++)
	{
		for (size_t j = 0;j < data[i];j++)
		{
			std::print("{} ", i);
		}
	}
}

MultiSet MultiSet::getUnion(const MultiSet& first, const MultiSet& second)
{
	size_t newN = (first.n < second.n) ? second.n : first.n;
	
	MultiSet result(newN);

	for (size_t i = 0;i < newN;i++)
	{
		unsigned char a = (i < first.n) ? first.data[i] : 0;
		unsigned char b = (i < second.n) ? second.data[i] : 0;

		if (a + b > 3)
		{
			result.data[i] = 3;
		}
		else
		{
			result.data[i] = a + b;
		}
	}

	return result;
}

MultiSet MultiSet::getIntersection(const MultiSet& first, const MultiSet& second)
{
	size_t newN= (first.n < second.n) ? first.n : second.n;

	MultiSet result(newN);

	for (size_t i = 0;i < newN;i++)
	{
		if (first.data[i] < second.data[i])
		{
			result.data[i] = first.data[i];
		}
		else
		{
			result.data[i] = second.data[i];
		}
	}

	return result;
}