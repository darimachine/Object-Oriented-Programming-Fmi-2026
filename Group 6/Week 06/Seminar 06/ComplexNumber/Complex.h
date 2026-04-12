#pragma once
#include <iostream>
class Complex
{
public:
    Complex();
    Complex(double real, double im);

    double getReal() const;
    double getImaginary() const;

    void setReal(double real);
    void setImaginary(double im);

    Complex getConjugated() const;

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    friend std::istream& operator>>(std::istream& is, Complex& complex);
    friend std::ostream& operator<<(std::ostream& os, const Complex& complex);
private:
    double real;
    double imaginary;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);