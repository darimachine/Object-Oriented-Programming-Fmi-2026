#include "Complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double im) : real(real), imaginary(im) {}

double Complex::getReal() const
{
    return real;
}

double Complex::getImaginary() const
{
    return imaginary;
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setImaginary(double im)
{
    imaginary = im;
}

Complex Complex::getConjugated() const
{
    return Complex(real, -imaginary);
}

Complex& Complex::operator+=(const Complex& other)
{
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    double currentReal = real;
    real = real * other.real - imaginary * other.imaginary;
    imaginary = currentReal * other.imaginary + imaginary * other.real;
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    Complex conjugated = other.getConjugated();
    Complex otherCopy(other);

    *this *= conjugated;
    otherCopy *= conjugated;

    if (otherCopy.real != 0) {
        real /= otherCopy.real;
        imaginary /= otherCopy.real;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
    return is >> complex.real >> complex.imaginary;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
    return os << complex.real << ' ' << complex.imaginary << 'i';
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result += rhs;
    return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result -= rhs;
    return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result *= rhs;
    return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex result(lhs);
    result /= rhs;
    return result;
}

bool operator==(const Complex& lhs, const Complex& rhs)
{
    return lhs.getReal() == rhs.getReal() && lhs.getImaginary() == rhs.getImaginary();
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
    return !(lhs == rhs);
}
