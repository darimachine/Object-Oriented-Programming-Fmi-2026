# Семинар 7

На лекции 7 е взимано:

---

## Задачи

1. Да се напише class `Imaginary`, който описва имагинерно число и поддържа следните методи и функционалности:

    - Конструктор по подразбиране със стойност 1 за реалната част пред имагинерната единица.
    - Параметричен конструктор, който приема реално число.
	- Getter & Setter за реалната част пред имагинерната единица.
	- Предефинирани следните оператори:
        | Ляв аргумент | Оператор  | Десен аргумент | Резултат     |
        |--------------|-----------|----------------|--------------|
        | Three        | way       | comparison     | <=>          |
        | Imaginary    | +=        | Imaginary      | Imaginary    |
        | Imaginary    | -=        | Imaginary      | Imaginary    |
        | Imaginary    | *=        | double         | Imaginary    |
        | Imaginary    | /=        | double         | Imaginary    |
        | std::ostream | <<        | Imaginary      | std::ostream |
        | std::istream | >>        | Imaginary      | std::istream |
        | Imaginary    | +         | Imaginary      | Imaginary    |
        | Imaginary    | -         | Imaginary      | Imaginary    |
        | Imaginary    | *         | Imaginary      | double       |
        | Imaginary    | /         | Imaginary      | double       |
        | Следните     | оператори | трябва да са   | комутативни: |
        | Imaginary    | *         | double         | Imaginary    |
        | Imaginary    | *         | double         | Imaginary    |
        | Imaginary    | +         | double         | Complex      |
        | Imaginary    | -         | double         | Complex      |

    <details>
    <summary>Решение</summary>

    ```c++
    #include "Imaginary.h"

    Imaginary::Imaginary(double value) : value(value)
    {
    }

    double Imaginary::getValue() const
    {
        return value;
    }

    double& Imaginary::getValue()
    {
        return value;
    }

    Imaginary& Imaginary::operator*=(double value)
    {
        this->value *= value;
        return *this;
    }

    Imaginary& Imaginary::operator/=(double value)
    {
        this->value /= value;
        return *this;
    }

    Imaginary& Imaginary::operator+=(const Imaginary& other)
    {
        value += other.value;
        return *this;
    }

    Imaginary& Imaginary::operator-=(const Imaginary& other)
    {
        value -= other.value;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Imaginary& im)
    {
        return os << im.value << 'i';
    }

    std::istream& operator>>(std::istream& is, Imaginary& im)
    {
        return is >> im.value;
    }

    Imaginary operator*(const Imaginary& im, double value)
    {
        Imaginary imCopy(im);
        imCopy *= value;
        return imCopy;
    }

    Imaginary operator*(double value, const Imaginary& im)
    {
        return operator*(im, value); // varian 1
    }

    Imaginary operator/(const Imaginary& im, double value)
    {
        Imaginary imCopy(im);
        imCopy /= value;
        return imCopy;
    }

    Imaginary operator/(double value, const Imaginary& im)
    {
        return im / value;  // varian 2
    }

    Imaginary operator+(const Imaginary& lhs, const Imaginary& rhs)
    {
        Imaginary imCopy(lhs);
        imCopy += rhs;
        return imCopy;
    }

    Imaginary operator-(const Imaginary& lhs, const Imaginary& rhs)
    {
        Imaginary imCopy(lhs);
        imCopy -= rhs;
        return imCopy;
    }

    double operator*(const Imaginary& lhs, const Imaginary& rhs)
    {
        return -1 * lhs.getValue() * rhs.getValue();
    }

    double operator/(const Imaginary& lhs, const Imaginary& rhs)
    {
        return lhs.getValue() / rhs.getValue();
    }

    Complex operator+(const Imaginary& im, double value)
    {
        return Complex(); // !
    }

    Complex operator+(double value, const Imaginary& im)
    {
        return Complex(); // !
    }

    Complex operator-(const Imaginary& im, double value)
    {
        return Complex(); // !
    }

    Complex operator-(double value, const Imaginary& im)
    {
        return Complex(); // !
    }
    ```

    </details>
