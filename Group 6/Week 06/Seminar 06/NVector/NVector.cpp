#include "NVector.h"

NVector NVector::operator()(const std::function<int(int)>& f) const {
    NVector result(size);
    //Example:  NVector squares = v([](int x) { return x * x; });
    for (int i = 0; i < size; i++)
    {
        result[i] = f(data[i]);
    }
    return result;
    
}

std::strong_ordering NVector::operator<=>(const NVector& other) const
{
    int minSize = min(size, other.size);
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
NVector& NVector::operator*=(int scalar)
{
    for (int i = 0; i < ~(*this); i++) // same as the size
    {
        data[i] *= scalar;
    }
    return *this;
}

const int& NVector::operator[](int index) const
{
    return data[index];
}

int& NVector::operator[](int index)
{
    return data[index];
}

int NVector::operator~() const
{
    return size;
}
NVector::operator bool() const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] != 0) return true;
    }
    return false;
}

void NVector::free()
{
    delete[] data;
    data=nullptr;
}

NVector& NVector::operator++() {
    for (int i = 0; i < size; i++)
    {
        data[i]++;
    }
    return *this;
}

NVector NVector::operator++(int dummy) {
    NVector temp(*this);
    ++(*this);
    return temp;
}

void NVector::copyFrom(const NVector& other)
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }
}

void NVector::resize(int newSize)
{
    
    int* temp = new int[newSize] {0};
    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }
    delete[] data;
    size = newSize;
    data = temp;

}

NVector& NVector::calculate(const NVector& other, const std::function<int(int, int)>& f)
{
    if (other.size > size)
        resize(other.size);

    for (int i = 0; i < other.size; i++)
        data[i] = f(data[i], other.data[i]);

    return *this;
}


NVector::NVector()
{
    size = 3;
    data = new int[size] {0};
}

NVector::NVector(int size)
{
    this->size = size;
    data = new int[size] {0};
}

NVector::NVector(const int* data, int size)
{
    this->size = size;
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

NVector& NVector::operator=(const NVector& other)
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
    return calculate(other, [](int a, int b) {return a + b; });
}

NVector& NVector::operator-=(const NVector& other)
{
    return calculate(other, [](int a, int b) {return a - b; });
}

ostream& operator<<(ostream& os, const NVector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        os << v.data[i]<<" ";
    }
    os << endl;
    return os;
}

istream& operator>>(istream& is, NVector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        is >> v.data[i];
    }
    
    return is;
 
}

bool operator<(const NVector& lhs, const NVector& rhs)
{
    int minSize = std::min(~lhs, ~rhs);
    for (int i = 0; i < minSize; i++)
    {
        if (lhs[i] == rhs[i]) continue;
        if (lhs[i] < rhs[i]) return true;
        return false;
    }
    return ~lhs<~rhs;
}

bool operator==(const NVector& lhs, const NVector& rhs)
{
    if (~lhs != ~rhs) {
        return false;
    }
    for (int i = 0; i < ~lhs; i++)
    {
        if (lhs[i] != rhs[i]) return false;
    }
    return true;
}

bool operator!=(const NVector& lhs, const NVector& rhs)
{
    return !(lhs==rhs);
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{
    NVector result(lhs);
    result += rhs;
    return result;
}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
    NVector result(lhs);
    result -= rhs;
    return result;
}

NVector operator*(const NVector& v, int scalar)
{
    NVector result(v);
    result*= scalar;
    return result;
}

NVector operator*(int scalar, const NVector& v)
{
    return v * scalar;
}

int operator%(const NVector& lhs, const NVector& rhs)
{
    if (~lhs != ~rhs) {
        return -1;
    }
    int result = 0;
    for (int i = 0; i < ~lhs; i++)
    {
        result += lhs[i] * rhs[i];
    }
    return result;
}

bool operator|(const NVector& lhs, const NVector& rhs)
{
    return (lhs%rhs) == 0;
}

bool operator||(const NVector& lhs, const NVector& rhs)
{
    if (~lhs != ~rhs) {
        return false;
    }
    double ratio = 0;
    bool isFirstRatioSet = false;
    for (int i = 0; i < ~lhs; i++)
    {
        if (lhs[i] == 0 && rhs[i] == 0) {
            continue;
        }
        if (lhs[i] == 0 || rhs[i] == 0) {
            return false;
        }
        double currentRatio = std::abs(lhs[i] / rhs[i]);
        if (!isFirstRatioSet) {
            ratio = currentRatio;
            isFirstRatioSet = true;
            continue;
        }

        if (abs(currentRatio - ratio) > 0.0001) {
            return false;
        }
    }
    return true;
}
