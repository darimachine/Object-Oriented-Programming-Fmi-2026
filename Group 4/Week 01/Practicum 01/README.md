## Задача

Напишете програма, която в безкраен цикъл чете двойки фигури на всяка своя итерация и сравнява лицата им. Използвайте namespaces, enums и structs за представяне и обработка на данните.

- можете да добавите и функционалност, която сравнява фигурите по "компактност", т.е. коя има по-малко отношение лице/периметър

Например:

```c++
enum class ShapeType {
    CIRCLE,
    TRIANGLE,
    RECTANGLE
    //... използвайте поне тези 3 типа фигури
};

namespace CircleNs {
    struct Circle {
        double radius;
    };

    void read(Circle& circle) {
        // ...
    }

    double getArea(const Circle& circle) {
        // ...
    }
}

// ...

```
