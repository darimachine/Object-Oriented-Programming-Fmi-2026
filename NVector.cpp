#include "NVector.h"
#include <cmath>

void NVector::copyFrom(const NVector& other)
{
	size = other.size;
	data = new int[size];

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void NVector::free()
{
	delete[] data;
	data = nullptr;
}

void NVector::resize(int newSize)
{
	int* temp = new int[newSize] {0};

	if (newSize < size) {
		return;
	}

	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;
	size = newSize;
}

NVector::NVector() : size(3)
{
	data = new int[size] {0};
}

NVector::NVector(int size): size(size)
{
	if (size <= 0) {
		data = nullptr;
		return;
	}

	data = new int[size] {0};
}

NVector::NVector(const int* data, int size):size(size)
{
	if (size <= 0) {
		this->data = nullptr;
		return;
	}

	this->data = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->data[i] = data[i];
	}
}

NVector::NVector(const NVector& other)
{
	copyFrom(other);
}

NVector& NVector::operator=(const NVector&other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

NVector::~NVector()
{
	free();
}

NVector& NVector::operator+=(const NVector& other)
{
	if (other.size > size) {
		resize(other.size);
	}

	for (int i = 0; i < other.size; i++)
	{
		data[i] += other.data[i];
	}

	return *this;

}

NVector& NVector::operator-=(const NVector& other)
{
	if (other.size > size) {
		resize(other.size);
	}

	for (int i = 0; i < other.size; i++)
	{
		data[i] -= other.data[i];
	}

	return *this;

}

NVector& NVector::operator*=(int scalar)
{
	for (int i = 0; i < size; i++)
	{
		data[i] *= scalar;
	}

	return *this;
}

int NVector::operator~() const
{
	return size;
}

const int& NVector::operator[](int index) const
{
	return data[index];
}

int& NVector::operator[](int index)
{
	return data[index];
}

NVector::operator bool() const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] != 0) {
			return true;
		}
	}
	return false;
}

NVector& NVector::operator++()
{
	for (int i = 0; i < size; i++)
	{
		data[i]++;
	}
	return *this;
}

NVector NVector::operator++(int dummy)
{
	NVector temp(*this);
	++(*this);
	return temp;
}

NVector NVector::operator()(const std::function<int(int)>& f) const
{
	NVector result(size);
	
	for (int i = 0; i < size; i++)
	{
		result[i] = f(data[i]);
	}
	return result;
}

std::strong_ordering NVector::operator<=>(const NVector& other) const
{
	int minSize = std::min(size, other.size);

	for (int i = 0; i < minSize; i++)
	{
		auto cmp = data[i] <=> other.data[i];
		if (cmp == 0) {
			continue;
		}
		return cmp;

	}
	return size <=> other.size;
}


std::ostream& operator<<(std::ostream& os, const NVector& v)
{
	for (int i = 0; i < ~v; i++)
	{
		os << v[i];

		if (i + 1 < ~v) {
			os << ' ';
		}
	}

	return os;
}

std::istream& operator>>(std::istream& is, NVector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		is >> v[i];
	}

	return is;
}

NVector operator+(const NVector& v1, const NVector& v2)
{
	NVector result(v1);
	result += v2;
	return result;
}

NVector operator-(const NVector& v1, const NVector& v2)
{
	NVector result(v1);
	result -= v2;
	return result;
}

NVector operator*(const NVector& v1, int scalar)
{
	NVector result(v1);
	result *= scalar;
	return result;
}

NVector operator*(int scalar, const NVector& v1)
{
	return v1 * scalar;
}

int operator%(const NVector& v1, const NVector& v2)
{
	if (~v1 != ~v2) {
		return -1;
	}

	int result = 0;

	for (int i = 0; i < ~v1; i++)
	{
		result += v1[i] * v2[i];
	}

	return result;
}

bool operator|(const NVector& v1, const NVector& v2)
{
	return (v1%v2)==0;
}

bool operator||(const NVector& v1, const NVector& v2)
{
	if (~v1 != ~v2) {
		return false;
	}

	double ratio = 0;
	bool isFirstRatioSet = false;

	for (int i = 0; i < ~v1; i++)
	{
		if (v1[i] == 0 && v2[i] == 0) {
			continue;
		}
		if (v1[i] == 0 || v2[i] == 0) {
			return false;
		}

		double currentRatio = std::abs(v1[i] / v2[i]);

		if (!isFirstRatioSet) {
			ratio = currentRatio;
			isFirstRatioSet = true;
			continue;
		}

		if (std::abs(currentRatio - ratio) > 0.0001) {
			return false;
		}
	}

	return true;
}

bool operator==(const NVector& v1, const NVector& v2)
{
	if (~v1 != ~v2) {
		return false;
	}

	for (int i = 0; i < ~v1; i++)
	{
		if (v1[i] != v2[i]) {
			return false;
		}
	}

	return true;
}

bool operator<(const NVector& v1, const NVector& v2)
{
	int minSize = std::min(~v1, ~v2);

	for (int i = 0; i < minSize; i++)
	{
		if (v1[i] == v2[i]) {
			continue;
		}

		if (v1[i] < v2[i]) {
			return true;
		}

		return false;
	}

	return ~v1 < ~v2;
	
}

bool operator!=(const NVector& v1, const NVector& v2)
{
	return !(v1==v2);
}

bool operator>(const NVector& v1, const NVector& v2)
{
	return v2<v1;
}

bool operator<=(const NVector& v1, const NVector& v2)
{
	return !(v2<v1);
}

bool operator>=(const NVector& v1, const NVector& v2)
{
	return !(v1<v2);
}



