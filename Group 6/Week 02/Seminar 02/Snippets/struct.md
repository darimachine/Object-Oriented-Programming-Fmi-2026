```c++
struct A{};
struct B {
    A e;
    int32_t age;
    char ch;
};
struct C {
    int16_t a;
    B b;
    B (*func)(int);
};
```