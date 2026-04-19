# Темплейти. Необходими функции в темплейтен клас/ функция. Темплейтни специализации. SFINAE. Concepts. Вариадични темплейти и std::tuple (C++ 11).

---

## Съдържание

1. [Защо темплейти?](#1-защо-темплейти)
2. [Темплейтна функция](#2-темплейтна-функция)
3. [Темплейтен клас](#3-темплейтен-клас)
4. [Проблемът с разделната компилация — защо `.hpp`?](#4-проблемът-с-разделната-компилация--защо-hpp)
5. [Необходими функции в темплейтен клас](#5-необходими-функции-в-темплейтен-клас)
6. [Темплейтни специализации](#6-темплейтни-специализации)
7. [SFINAE](#7-sfinae)
8. [Concepts (C++20)](#8-concepts-c20)
9. [Вариадични темплейти](#9-вариадични-темплейти)
10. [std::forward и Perfect Forwarding](#10-stdforward-и-perfect-forwarding)
11. [std::tuple](#11-stdtuple)
12. [Дизайн патърн Итератор](#12-дизайн-патърн-итератор)
13. [Edge Cases и капани](#13-edge-cases-и-капани)
14. [Обобщение](#14-обобщение)

---

## 1. Защо темплейти?

Разгледайте функция, която намира максимума на две числа:

```cpp
int    maxInt   (int    a, int    b) { return a > b ? a : b; }
double maxDouble(double a, double b) { return a > b ? a : b; }
float  maxFloat (float  a, float  b) { return a > b ? a : b; }
```

Трите функции са **идентични** — разлика само в типа. При промяна на логиката трябва да се поправят три места. Темплейтът решава това:

```cpp
template <typename T>
T myMax(const T& a, const T& b) {
    return a > b ? a : b;
}
```

Компилаторът **генерира** версията за нужния тип при употреба:

```cpp
myMax(3, 5);       // компилаторът генерира myMax<int>
myMax(3.14, 2.7);  // компилаторът генерира myMax<double>
myMax('a', 'z');   // компилаторът генерира myMax<char>
```

Това е **полиморфизъм по време на компилация** — за разлика от виртуалните функции, които работят по време на изпълнение, темплейтите се разрешават преди програмата да е стартирала.

---

## 2. Темплейтна функция

### Синтаксис

```cpp
template <typename T>   // T е параметър на типа
T add(const T& a, const T& b) {
    return a + b;
}
```

`typename` и `class` са еквивалентни в темплейтния контекст — `typename` е предпочитан стил.

### Дедукция на типа

Компилаторът може сам да определи `T` от подадените аргументи:

```cpp
add(1, 2);          // T → int   (дедуцирано от аргументите)
add(1.5, 2.5);      // T → double
add<int>(1, 2);     // T = int   (изрично)
```

### Кога дедукцията се проваля

```cpp
add(1, 2.5);   // ❌ 1 е int, 2.5 е double — T е двусмислен
               //    компилаторът не може да реши

// ✅ Решения:
add<double>(1, 2.5);   // изрично — 1 се конвертира към double

template <typename T, typename U>   // два отделни параметъра
auto add(const T& a, const U& b) {
    return a + b;
}
add(1, 2.5);   // T=int, U=double, резултатът е double
```

### Не-типов параметър

Темплейтен параметър може да е и **стойност**, не само тип:

```cpp
template <typename T, int SIZE>
class FixedArray {
    T data[SIZE];   // SIZE е известен по компилация
public:
    T&  operator[](int i) { return data[i]; }
    int size() const      { return SIZE; }
};

FixedArray<int, 5>    arr1;   // масив от 5 int-а — SIZE=5 е вградено в типа
FixedArray<double, 3> arr2;   // масив от 3 double-а — различен тип от arr1!
```

`FixedArray<int, 5>` и `FixedArray<int, 10>` са **различни типове** — компилаторът генерира отделен клас за всяка комбинация.

### Пример — намиране на минимум в масив

```cpp
template <typename T>
T minElement(const T* arr, int size) {
    T result = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < result)
            result = arr[i];
    return result;
}

int    ints[]    = {3, 1, 4, 1, 5};
double doubles[] = {2.7, 1.4, 3.1};

std::cout << minElement(ints,    5) << "\n";   // 1
std::cout << minElement(doubles, 3) << "\n";   // 1.4
```

---

## 3. Темплейтен клас

Темплейтният клас позволява контейнер или структура да работи с произволен тип.

### Деклариране

```cpp
template <typename T>
class Stack {
    T*  data;
    int top;
    int capacity;
public:
    explicit Stack(int cap = 16);
    ~Stack();
    void      push(const T& value);
    T         pop();
    const T&  peek() const;
    bool      isEmpty() const;
    int       size()    const;
};
```

### Дефиниране на методите

Всеки метод дефиниран извън класа изисква `template <typename T>` и `Stack<T>::`:

```cpp
template <typename T>
Stack<T>::Stack(int cap) : top(-1), capacity(cap) {
    data = new T[capacity];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (top + 1 >= capacity)
        throw std::overflow_error("Stack е пълен");
    data[++top] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty())
        throw std::underflow_error("Stack е празен");
    return data[top--];
}

template <typename T>
const T& Stack<T>::peek() const {
    if (isEmpty())
        throw std::underflow_error("Stack е празен");
    return data[top];
}

template <typename T>
bool Stack<T>::isEmpty() const { return top == -1; }

template <typename T>
int Stack<T>::size() const { return top + 1; }
```

### Употреба

```cpp
Stack<int> intStack(10);
intStack.push(1);
intStack.push(2);
intStack.push(3);
std::cout << intStack.pop()  << "\n";   // 3
std::cout << intStack.peek() << "\n";   // 2 — не маха
std::cout << intStack.size() << "\n";   // 2

Stack<std::string> strStack;
strStack.push("hello");
strStack.push("world");
std::cout << strStack.pop() << "\n";    // world
```

---

## 4. Проблемът с разделната компилация — защо `.hpp`?

Това е един от най-честите въпроси при темплейтите. За да се разбере защо дефинициите **не** могат да са в `.cpp` файл, трябва да се знае как работи компилацията.

### Как работи обикновената разделна компилация

```
math.h   → декларация:  int add(int a, int b);
math.cpp → дефиниция:   int add(int a, int b) { return a + b; }
main.cpp → употреба:    add(1, 2);
```

```
Стъпка 1 — Компилация:
  math.cpp → math.o   (съдържа машинния код на add)
  main.cpp → main.o   (съдържа call към add — адресът е неизвестен)

Стъпка 2 — Линкване:
  main.o + math.o → executable
  линкерът свързва call с адреса на add ✅
```

### Защо темплейтите се чупят при разделна компилация

```
stack.h   → декларация:  template <typename T> class Stack { void push(T); };
stack.cpp → дефиниция:   template <typename T> void Stack<T>::push(T v) { ... }
main.cpp  → употреба:    Stack<int> s; s.push(1);
```

```
Стъпка 1 — Компилация:
  stack.cpp → stack.o
    Компилаторът вижда шаблона, но НИКОЙ не е поискал Stack<int> тук.
    Не генерира нищо! stack.o е практически празен за темплейтния код.

  main.cpp → main.o
    Компилаторът вижда Stack<int>::push(1).
    Трябва да генерира код, но вижда само ДЕКЛАРАЦИЯТА от stack.h.
    Не може да генерира Stack<int>::push — дефиницията е в stack.cpp!
    Генерира call към Stack<int>::push с неизвестен адрес.

Стъпка 2 — Линкване:
  main.o + stack.o → ГРЕШКА!
  undefined reference to Stack<int>::push(int)
  ↑ Кодът за Stack<int>::push никога не е генериран!
```

### Разликата от обикновените функции

При обикновена функция `add(int, int)` компилаторът на `math.cpp` генерира **конкретния машинен код** веднъж. Линкерът само свързва адреса.

При темплейт `Stack<T>::push` кодът **не може да се генерира предварително** — типът `T` е неизвестен. Кодът се генерира **само когато се знае T**, т.е. при употреба в `main.cpp`. За да стане това — дефиницията трябва да е видима в `main.cpp`.

### Решението — дефиниция в хедъра

```cpp
// stack.hpp  ← цялото съдържание е тук

template <typename T>
class Stack {
    T*  data;
    int top;
    int capacity;
public:
    Stack(int cap = 16);
    ~Stack();
    void push(const T& value);
    T    pop();
};

// Дефинициите са в СЪЩИЯ файл:
template <typename T>
Stack<T>::Stack(int cap) : top(-1), capacity(cap) {
    data = new T[capacity];
}

template <typename T>
void Stack<T>::push(const T& value) {
    data[++top] = value;
}
// ...
```

```
Сега при компилация на main.cpp:
  #include "stack.hpp"   ← дефиницията е видима
  Stack<int> s;          ← компилаторът генерира Stack<int>
  s.push(1);             ← компилаторът генерира Stack<int>::push(int)
  ✅ Всичко е OK
```

### `.h` vs `.hpp`

Конвенцията е:

| Разширение | Употреба |
|---|---|
| `.h` | C хедъри или C++ хедъри само с декларации |
| `.hpp` | C++ хедъри, съдържащи темплейтни дефиниции |

`.hpp` не е задължение на езика — компилаторът не прави разлика. Това е **конвенция**, която сигнализира „този хедър съдържа и дефиниции".

---

## 5. Необходими функции в темплейтен клас

Темплейтният клас налага изисквания към типа `T`, с който се инстанцира. Ако `T` не поддържа нужната операция — **грешка при компилация**.

### Какво изисква `Stack<T>`?

```cpp
template <typename T>
class Stack {
    T* data;
    // ...
public:
    void push(const T& value) {
        data[++top] = value;   // ← изисква T да има operator= (copy assignable)
    }

    T pop() {
        return data[top--];    // ← изисква T да може да се връща по стойност
                               //   (copy constructible или move constructible)
    }
};
```

### Какво трябва да поддържа `T`

За всяка темплейтна функция важат различни изисквания:

```cpp
// myMax изисква operator>
template <typename T>
T myMax(const T& a, const T& b) {
    return a > b ? a : b;   // T трябва да има operator>
}

// minElement изисква operator<
template <typename T>
T minElement(const T* arr, int size) {
    if (arr[i] < result) ...   // T трябва да има operator<
}

// sort изисква operator<
// print изисква operator<<
```

### Грешка при неподходящ тип

```cpp
struct Point { int x, y; };   // няма operator<

int arr[3] = {3, 1, 2};
minElement(arr, 3);     // ✅ int има operator<

Point pts[3] = { {1,2}, {3,4}, {0,0} };
minElement(pts, 3);     // ❌ ГРЕШКА: no match for operator< (Point, Point)
```

Грешката показва **точно къде** е нарушено изискването. При SFINAE и Concepts (вж. секции 7 и 8) може да се даде по-ясна грешка.

### Правило — документирай изискванията

```cpp
// Изисква: T поддържа operator<, operator=, copy constructor
template <typename T>
class SortedList {
    // ...
};
```

---

## 6. Темплейтни специализации

### Пълна специализация — за точно един тип

Общата версия се ползва за всички типове. Специализацията я **заменя** за конкретен тип:

```cpp
// Обща версия — за всеки T
template <typename T>
void print(const T& value) {
    std::cout << value << "\n";
}

// Пълна специализация за bool
template <>
void print<bool>(bool value) {
    std::cout << (value ? "true" : "false") << "\n";
}

// Пълна специализация за const char*
template <>
void print<const char*>(const char* value) {
    std::cout << "\"" << value << "\"" << "\n";
}

print(42);        // Обща:          42
print(3.14);      // Обща:          3.14
print(true);      // Специализация: true
print("hello");   // Специализация: "hello"
```

### Пълна специализация на клас

```cpp
// Обща версия
template <typename T>
class Serializer {
public:
    std::string serialize(const T& value) {
        return std::to_string(value);
    }
};

// Специализация за std::string — to_string не работи за string
template <>
class Serializer<std::string> {
public:
    std::string serialize(const std::string& value) {
        return "\"" + value + "\"";
    }
};

Serializer<int>         intSer;
Serializer<std::string> strSer;

std::cout << intSer.serialize(42)      << "\n";  // 42
std::cout << strSer.serialize("hello") << "\n";  // "hello"
```

### Частична специализация — само за класове!

Специализира **само някои** параметри. **Работи единствено за класове**, не за функции.

```cpp
// Обща версия — два параметъра
template <typename T, typename U>
class Converter {
public:
    void info() { std::cout << "Общ Converter\n"; }
};

// Частична специализация — когато двата типа съвпадат
template <typename T>
class Converter<T, T> {
public:
    void info() { std::cout << "Converter с еднакви типове\n"; }
};

// Частична специализация — когато T е указател
template <typename T, typename U>
class Converter<T*, U> {
public:
    void info() { std::cout << "Converter с указател вляво\n"; }
};

Converter<int, double> c1; c1.info();  // Общ Converter
Converter<int, int>    c2; c2.info();  // Converter с еднакви типове
Converter<int*, double> c3; c3.info(); // Converter с указател вляво
```

### Кой вариант се избира?

Компилаторът избира **най-специфичния** съвпадащ вариант:

```
За Converter<int, int>:
  Обща версия              → съвпада (T=int, U=int)
  Частична <T, T>          → съвпада (T=int) — по-специфична
  → Избира се частичната
```

---

## 7. SFINAE

### Какво е SFINAE?

**Substitution Failure Is Not An Error** — при опит за инстанциране, ако заместването се провали, тази версия **тихо се изключва** и компилаторът търси следваща. Грешка настъпва само ако **никоя** версия не е подходяща.

```
Компилаторът вижда: square("hello")

  → Опитва версията за integral:
    enable_if<is_integral_v<const char*>> → false → провал → ИЗКЛЮЧВА
  → Опитва версията за floating_point:
    enable_if<is_floating_point_v<const char*>> → false → провал → ИЗКЛЮЧВА
  → Няма повече версии → ГРЕШКА (но ясна: no matching function)
```

### `std::enable_if`

```cpp
#include <type_traits>

// Активира се само за целочислени типове
template <typename T>
std::enable_if_t<std::is_integral_v<T>, T>
square(const T& x) {
    std::cout << "integral: ";
    return x * x;
}

// Активира се само за дробни типове
template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, T>
square(const T& x) {
    std::cout << "floating: ";
    return x * x;
}

std::cout << square(5)   << "\n";   // integral: 25
std::cout << square(2.5) << "\n";   // floating: 6.25
// square("hi");                     // ❌ нито integral, нито floating
```

### Как работи `enable_if`

```cpp
template <bool Condition, typename T = void>
struct enable_if {};   // при Condition=false — няма type!

template <typename T>
struct enable_if<true, T> {
    using type = T;    // при Condition=true — type съществува
};
```

При `Condition=false`, `enable_if<false, T>::type` не съществува → заместването се проваля → SFINAE изключва версията.

### Полезни `type_traits`

```cpp
std::is_integral_v<T>          // int, char, bool, long...
std::is_floating_point_v<T>    // float, double, long double
std::is_pointer_v<T>           // T*
std::is_class_v<T>             // клас или struct
std::is_same_v<T, U>           // T и U са един и същ тип
std::is_base_of_v<Base, T>     // T наследява Base
std::is_copy_constructible_v<T>
std::is_default_constructible_v<T>
```

### Проблемът — нечетими грешки

```cpp
square("hello");
// error: no type named 'type' in 'struct std::enable_if<false, const char*>'
// error: no type named 'type' in 'struct std::enable_if<false, const char*>'
// ... 30 реда нечетим шум
```

Точно за това в C++20 се въвеждат Concepts.

---

## 8. Concepts (C++20)

Concept е **именувано ограничение** върху темплейтен параметър. При нарушение — кратка и ясна грешка.

### Дефиниране

```cpp
#include <concepts>

template <typename T>
concept Numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <typename T>
concept Printable = requires(T x) {
    { std::cout << x };   // трябва да поддържа operator<<
};

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b }  -> std::convertible_to<bool>;
    { a == b } -> std::convertible_to<bool>;
};
```

### Четири начина за прилагане

```cpp
// 1. Concept вместо typename (най-четимо)
template <Numeric T>
T square(const T& x) { return x * x; }

// 2. requires след параметрите
template <typename T>
T square(const T& x) requires Numeric<T>;

// 3. requires клауза преди тялото
template <typename T>
    requires Numeric<T>
T square(const T& x);

// 4. Съкратен синтаксис
T square(Numeric auto x);
```

### SFINAE vs. Concepts — сравнение на грешките

```cpp
// SFINAE — при square("hello"):
// error: no type named 'type' in 'struct std::enable_if<false, ...>'
// ... 30 реда

// Concepts — при square("hello"):
// error: 'const char*' does not satisfy 'Numeric'
// note: because 'std::is_integral_v<const char*>' evaluated to false
// ← едно изречение, ясно
```

### Стандартни Concepts от `<concepts>`

```cpp
std::integral<T>              // целочислен тип
std::floating_point<T>        // дробен тип
std::same_as<T, U>            // T е точно U
std::derived_from<T, Base>    // T наследява Base
std::convertible_to<T, U>     // T може да се конвертира към U
std::equality_comparable<T>   // T поддържа ==
std::totally_ordered<T>       // T поддържа <, >, <=, >=
std::copy_constructible<T>    // T(const T&)
std::default_initializable<T> // T()
```

### Пълен пример — Concept за контейнер

```cpp
template <typename T>
concept Container = requires(T c) {
    c.begin();
    c.end();
    c.size();
    typename T::value_type;
};

template <Container C>
void printAll(const C& container) {
    for (const auto& el : container)
        std::cout << el << " ";
    std::cout << "\n";
}

printAll(std::vector<int>{1, 2, 3});   // ✅
printAll(std::string("hello"));        // ✅
// printAll(42);                        // ❌ Ясна грешка: int не е Container
```

---

## 9. Вариадични темплейти

Вариадичните темплейти приемат **произволен брой параметри** от произволни типове.

```cpp
template <typename... Args>   // parameter pack
void f(Args... args);         // argument pack

// sizeof... дава броя параметри
template <typename... Args>
void count(const Args&... args) {
    std::cout << sizeof...(args) << "\n";
}

count(1, 2, 3);       // 3
count("a", true);     // 2
count();              // 0
```

### Рекурсия — класическият начин

```cpp
// Base case — без аргументи (задължително!)
void print() {
    std::cout << "\n";
}

// Рекурсивен случай
template <typename T, typename... Rest>
void print(const T& first, const Rest&... rest) {
    std::cout << first << " ";
    print(rest...);   // рекурсия с останалите
}

print(1, 2.5, "hello", true);
// 1 2.5 hello 1
```

Разгъването работи така:

```
print(1, 2.5, "hello", true)
  → first=1,      rest={2.5, "hello", true}  → печата 1
  → first=2.5,    rest={"hello", true}        → печата 2.5
  → first="hello",rest={true}                 → печата hello
  → first=true,   rest={}                     → печата 1
  → print()                                   → печата \n
```

### Fold expressions (C++17) — без рекурсия

```cpp
template <typename... Args>
auto sum(const Args&... args) {
    return (... + args);
    // разгъва се като: args[0] + args[1] + args[2] + ...
}

template <typename... Args>
void print(const Args&... args) {
    ((std::cout << args << " "), ...);
    // разгъва се като: (cout << args[0]), (cout << args[1]), ...
    std::cout << "\n";
}

std::cout << sum(1, 2, 3, 4, 5) << "\n";  // 15
print(1, "hello", 3.14, true);            // 1 hello 3.14 1
```

### Видове fold expressions

```cpp
(... op pack)       // ((a op b) op c)   — ляво сгъване
(pack op ...)       // (a op (b op c))   — дясно сгъване
(init op ... op pack)  // ((init op a) op b)
(pack op ... op init)  // (a op (b op init))
```

### Практически пример — функция с произволен брой аргументи

```cpp
template <typename... Args>
void log(const std::string& level, const Args&... args) {
    std::cout << "[" << level << "] ";
    ((std::cout << args << " "), ...);
    std::cout << "\n";
}

log("INFO",  "Потребител", "Иван", "влезе в системата");
log("ERROR", "Код:", 404, "Страницата не е намерена");
```

```
[INFO]  Потребител Иван влезе в системата
[ERROR] Код: 404 Страницата не е намерена
```

---

## 11. `std::tuple`

`std::tuple` е хетерогенен контейнер — съдържа фиксиран брой елементи от **различни типове**. Генерализация на `std::pair` за произволен брой.

```cpp
#include <tuple>

std::tuple<int, std::string, double> student(25, "Иван", 5.5);
```

### Създаване

```cpp
// Изрично с типовете
std::tuple<int, std::string, bool> t1(1, "Иван", true);

// С make_tuple — типовете се дедуцират
auto t2 = std::make_tuple(42, 3.14, "world");
```

### Достъп — само с compile-time индекс

```cpp
auto t = std::make_tuple(25, std::string("Мария"), 6.0);

std::cout << std::get<0>(t) << "\n";   // 25
std::cout << std::get<1>(t) << "\n";   // Мария
std::cout << std::get<2>(t) << "\n";   // 6

// По тип — само ако типовете са уникални:
std::cout << std::get<int>(t)         << "\n";  // 25
std::cout << std::get<std::string>(t) << "\n";  // Мария
```

### Разпакетиране

```cpp
// С std::tie
int age; std::string name; double grade;
std::tie(age, name, grade) = t;

// С structured bindings (C++17) — предпочитан начин
auto [a, n, g] = t;
std::cout << a << " " << n << " " << g << "\n";  // 25 Мария 6
```

### Функция, връщаща множество стойности

```cpp
std::tuple<int, int, int> stats(const int* arr, int size) {
    int mn = arr[0], mx = arr[0], sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
        sum += arr[i];
    }
    return {mn, mx, sum};
}

int data[] = {3, 1, 4, 1, 5, 9};
auto [mn, mx, sum] = stats(data, 6);
std::cout << mn << " " << mx << " " << sum << "\n";  // 1 9 23
```

### Итерация с вариадични темплейти

`std::tuple` няма вграден итератор — итерацията изисква `index_sequence`:

```cpp
template <typename Tuple, std::size_t... I>
void printTupleImpl(const Tuple& t, std::index_sequence<I...>) {
    ((std::cout << std::get<I>(t) << " "), ...);
    std::cout << "\n";
}

template <typename... Args>
void printTuple(const std::tuple<Args...>& t) {
    printTupleImpl(t, std::index_sequence_for<Args...>{});
}

auto t = std::make_tuple(1, "hello", 3.14);
printTuple(t);   // 1 hello 3.14
```

### `tuple_size` и `tuple_element`

```cpp
using T = std::tuple<int, double, std::string>;

std::cout << std::tuple_size<T>::value << "\n";  // 3

using SecondType = std::tuple_element<1, T>::type;
// SecondType е double
```

---

## 10. `std::forward` и Perfect Forwarding

### Проблемът

Вътре в темплейтна функция всеки именуван параметър е **lvalue** — независимо как е подаден отвън. Ако функцията делегира към друга, категорията се губи:

```cpp
void process(const std::string& s) { std::cout << "lvalue\n"; }
void process(std::string&& s)      { std::cout << "rvalue\n"; }

template <typename T>
void wrapper(T&& arg) {
    process(arg);   // ❌ arg е именуван → винаги lvalue!
}

std::string s = "hello";
wrapper(s);             // lvalue → process("lvalue") ✅
wrapper(std::string("hello")); // rvalue → process("lvalue") ❌ трябваше rvalue!
```

### Forwarding reference (`T&&`)

`T&&` в темплейтен контекст **не е rvalue референция** — тя е **forwarding reference** (universal reference). Компилаторът дедуцира `T` различно в зависимост от аргумента:

```
wrapper(lvalue)  → T = std::string&  → T&& = std::string& && = std::string&
wrapper(rvalue)  → T = std::string   → T&& = std::string&&
```

Информацията за категорията е закодирана в `T` — `std::forward` я използва:

### `std::forward` — решението

```cpp
template <typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg));   // ✅ запазва оригиналната категория
}

std::string s = "hello";
wrapper(s);                    // T=string&  → forward връща lvalue → "lvalue"
wrapper(std::string("hello")); // T=string   → forward връща rvalue → "rvalue"
```

`std::forward<T>(arg)` е еквивалентно на:
- `static_cast<T&>(arg)`  ако `T` е `string&`  (lvalue случай)
- `static_cast<T&&>(arg)` ако `T` е `string`   (rvalue случай)

### `std::move` vs `std::forward`

```
std::move(x)        → ВИНАГИ rvalue  — „вземи ресурсите"
std::forward<T>(x)  → запазва категорията — „предай нататък без промяна"
```

```cpp
// move — при конструктори/оператори, знаеш че искаш rvalue
String(String&& other) noexcept : data(other.data) {
    other.data = nullptr;
}

// forward — при wrapper функции, не знаеш какво е дошло
template <typename T>
void wrapper(T&& arg) {
    process(std::forward<T>(arg));
}
```

---

## 12. Дизайн патърн Итератор

### Какво е итератор?

Итераторът е обект, който позволява **обхождане на контейнер** без да се знае вътрешната му структура. Отделя логиката на обхождане от логиката на контейнера.

Без итератор всеки, който иска да обходи `Stack`, трябва да знае, че данните са в `data[]` и `top` е последният индекс — вътрешни детайли, които не трябва да изтичат навън:

```cpp
// ❌ Обхождане с директен достъп до вътрешностите:
for (int i = 0; i <= stack.top; i++)
    std::cout << stack.data[i];
// stack.top и stack.data са private — не работи!
// Дори да са public — обвързваме се с имплементацията
```

С итератор:

```cpp
// ✅ Обхождане без знание за вътрешността:
for (auto it = stack.begin(); it != stack.end(); ++it)
    std::cout << *it;

// Или с range-based for (изисква begin() и end()):
for (const auto& el : stack)
    std::cout << el;
```

### Защо е нужен?

Итераторът позволява контейнерът да работи с **цялата стандартна библиотека**:

```cpp
std::vector<int> v = myStack.toVector();   // ❌ излишна конверсия

// ✅ Директно с алгоритмите:
std::sort(myStack.begin(), myStack.end());
std::find(myStack.begin(), myStack.end(), 42);
for (const auto& el : myStack) { ... }
```

### Минималният интерфейс на итератор

За да работи `for (auto& el : container)` и `std::sort`, итераторът трябва да поддържа:

```
operator*   — дереференциране (достъп до елемента)
operator++  — преместване напред (prefix)
operator!=  — проверка за край
```

За `std::sort` допълнително:

```
operator+, operator-, operator[]    — random access
operator<                           — сравнение
```

### Реализация — итератор за темплейтен масив

```cpp
template <typename T>
class DynamicArray {
    T*  data;
    int size;
    int capacity;

public:
    // ─── Вложен клас Iterator ───
    class Iterator {
        T* ptr;   // указател към текущия елемент
    public:
        explicit Iterator(T* p) : ptr(p) {}

        // Дереференциране — достъп до стойността
        T& operator*() const { return *ptr; }

        // Адресен оператор
        T* operator->() const { return ptr; }

        // Преместване напред (prefix: ++it)
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Преместване напред (postfix: it++)
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        // Сравнение — за края на цикъла
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    // ─── begin и end ───
    Iterator begin() { return Iterator(data); }
    Iterator end()   { return Iterator(data + size); }

    // ─── const версии (за const обекти) ───
    Iterator begin() const { return Iterator(data); }
    Iterator end()   const { return Iterator(data + size); }

    // ... останалите методи
};
```

### Как работи range-based for

```cpp
for (auto& el : arr) { ... }
// Компилаторът го превежда на:
{
    auto it  = arr.begin();
    auto end = arr.end();
    for (; it != end; ++it) {
        auto& el = *it;
        { ... }
    }
}
```

Точно затова са нужни `begin()`, `end()`, `operator*` и `operator!=`.

### БОНУС: Как работи `std::sort` с итератор

`std::sort` изисква **random access iterator** — итератор, при който може да се скача директно на произволна позиция:

```cpp
// За std::sort итераторът трябва да поддържа и:
Iterator operator+(int n) const { return Iterator(ptr + n); }
Iterator operator-(int n) const { return Iterator(ptr - n); }
int      operator-(const Iterator& other) const { return ptr - other.ptr; }
bool     operator<(const Iterator& other)  const { return ptr < other.ptr; }
T&       operator[](int n) const { return ptr[n]; }
```

```cpp
DynamicArray<int> arr;
arr.push_back(3); arr.push_back(1); arr.push_back(4);

std::sort(arr.begin(), arr.end());   // ✅ работи с random access iterator
// arr = {1, 3, 4}
```

### Пълен пример

```cpp
#include <iostream>
#include <algorithm>

template <typename T>
class DynamicArray {
    T*  data;
    int sz;
    int cap;

    void resize() {
        cap *= 2;
        T* newData = new T[cap];
        for (int i = 0; i < sz; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() : sz(0), cap(4) {
        data = new T[cap];
    }

    ~DynamicArray() { delete[] data; }

    void push_back(const T& val) {
        if (sz == cap) resize();
        data[sz++] = val;
    }

    int  size()              const { return sz; }
    T&   operator[](int i)         { return data[i]; }
    const T& operator[](int i) const { return data[i]; }

    // ─── Iterator ───
    class Iterator {
        T* ptr;
    public:
        explicit Iterator(T* p) : ptr(p) {}

        T&       operator*()  const { return *ptr; }
        T*       operator->() const { return ptr; }

        Iterator& operator++()    { ++ptr; return *this; }
        Iterator  operator++(int) { Iterator t=*this; ++ptr; return t; }

        Iterator  operator+(int n)              const { return Iterator(ptr + n); }
        Iterator  operator-(int n)              const { return Iterator(ptr - n); }
        int       operator-(const Iterator& o)  const { return ptr - o.ptr; }
        T&        operator[](int n)             const { return ptr[n]; }

        bool operator==(const Iterator& o) const { return ptr == o.ptr; }
        bool operator!=(const Iterator& o) const { return ptr != o.ptr; }
        bool operator< (const Iterator& o) const { return ptr <  o.ptr; }
        bool operator> (const Iterator& o) const { return ptr >  o.ptr; }
        bool operator<=(const Iterator& o) const { return ptr <= o.ptr; }
        bool operator>=(const Iterator& o) const { return ptr >= o.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end()   { return Iterator(data + sz); }
    Iterator begin() const { return Iterator(data); }
    Iterator end()   const { return Iterator(data + sz); }
};

int main() {
    DynamicArray<int> arr;
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(8);
    arr.push_back(1);

    // range-based for
    std::cout << "Преди сортиране: ";
    for (const auto& el : arr)
        std::cout << el << " ";
    std::cout << "\n";

    // std::sort
    std::sort(arr.begin(), arr.end());

    std::cout << "След сортиране: ";
    for (const auto& el : arr)
        std::cout << el << " ";
    std::cout << "\n";

    // std::find
    auto it = std::find(arr.begin(), arr.end(), 5);
    if (it != arr.end())
        std::cout << "Намерено: " << *it << "\n";
}
```

```
Преди сортиране: 5 2 8 1
След сортиране:  1 2 5 8
Намерено: 5
```

### `iterator_traits` — правилната интеграция

За пълна съвместимост с STL алгоритмите итераторът трябва да дефинира типове, по които алгоритмите се ориентират:

```cpp
class Iterator {
    T* ptr;
public:
    // Типове, изисквани от STL
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = T;
    using difference_type   = std::ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

    // ... операторите
};
```

Без тях `std::sort` и повечето алгоритми **работят** (компилаторът може да дедуцира), но при определени алгоритми може да се получи грешка или неоптимален избор.

### Видове итератори

```
Input Iterator       — само четене, само напред (>>)
Output Iterator      — само писане, само напред
Forward Iterator     — четене/писане, само напред (std::list)
Bidirectional        — напред и назад (operator--)
Random Access        — скок на произволна позиция (std::vector, масив)
                       изисква: +, -, [], <, >, <=, >=
```

`std::sort` изисква **Random Access**. `std::find` работи с всеки.

---

## 13. Edge Cases и капани

### Дефиниция в `.cpp` → линк грешка

```cpp
// stack.h
template <typename T>
class Stack { void push(const T& v); };

// stack.cpp
template <typename T>
void Stack<T>::push(const T& v) { ... }   // ❌ дефиниция в .cpp

// main.cpp
Stack<int> s;
s.push(1);
// ❌ undefined reference to Stack<int>::push(int const&)

// ✅ Дефиницията трябва да е в stack.hpp
```

---

### Частична специализация на функция — не е специализация!

```cpp
template <typename T>
void f(const T& x) { std::cout << "обща\n"; }

template <typename T>
void f(T* x) { std::cout << "указател\n"; }  // ← overload, НЕ специализация!
```

Функциите нямат частична специализация — само overloading. За частична специализация на функционалност — използвай клас:

```cpp
// ✅ Частична специализация само за класове:
template <typename T>
class F { void call(const T& x) { std::cout << "обща\n"; } };

template <typename T>
class F<T*> { void call(T* x) { std::cout << "указател\n"; } };
```

---

### `std::get` изисква compile-time индекс

```cpp
auto t = std::make_tuple(1, "hello", 3.14);

int i = 1;
std::get<i>(t);   // ❌ ГРЕШКА: i трябва да е compile-time константа

std::get<1>(t);          // ✅
constexpr int j = 1;
std::get<j>(t);          // ✅ constexpr е compile-time
```

---

### Вариадични темплейти без base case → безкрайна рекурсия

```cpp
// ❌ Без base case:
template <typename T, typename... Rest>
void print(const T& first, const Rest&... rest) {
    std::cout << first << " ";
    print(rest...);   // при Rest={} → print() → не съществува → ГРЕШКА
}

// ✅ Задължителен base case:
void print() {}   // приема нула аргументи

template <typename T, typename... Rest>
void print(const T& first, const Rest&... rest) {
    std::cout << first << " ";
    print(rest...);
}
```

---

### SFINAE с припокриващи се условия → двусмислие

```cpp
template <typename T>
std::enable_if_t<std::is_integral_v<T>> f(T x) { ... }

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>> f(T x) { ... }
// is_arithmetic включва is_integral!

f(5);   // ⚠️ int е и integral, и arithmetic → ambiguous!

// ✅ Условията трябва да са взаимноизключващи:
std::enable_if_t<std::is_integral_v<T>>       // само integral
std::enable_if_t<std::is_floating_point_v<T>> // само floating_point
```

---

### Concept не проверява стойности — само типове

```cpp
template <std::integral T>
T divide(const T& a, const T& b) {
    return a / b;   // ⚠️ Concept гарантира T е int, НЕ че b != 0
}

divide(10, 0);   // компилира се → runtime грешка (деление на нула)
```

---

## 14. Обобщение

### Какво генерира компилаторът

```
template <typename T>     T=int   → Stack<int>  (отделен клас)
class Stack { ... };      T=double→ Stack<double>(отделен клас)
                          T=string→ Stack<string>(отделен клас)
```

Всяка инстанция е **независим тип** — `Stack<int>` и `Stack<double>` нямат нищо общо.

### Видове темплейти

```
┌────────────────────────┬───────────────────────────────────┐
│  Вид                   │  Синтаксис                        │
├────────────────────────┼───────────────────────────────────┤
│  Функция               │  template <typename T> T f(T)     │
│  Клас                  │  template <typename T> class C {} │
│  Пълна специализация   │  template <> class C<int> {}      │
│  Частична специализация│  template <typename T> class C<T*>│
│  Вариадичен            │  template <typename... Args>      │
└────────────────────────┴───────────────────────────────────┘
```

### SFINAE vs. Concepts

| | SFINAE | Concepts |
|---|---|---|
| Стандарт | C++11 | C++20 |
| Четимост на грешки | Лоша | Отлична |
| Синтаксис | Сложен | Чист |
| Гъвкавост | Висока | Висока |
| Препоръчан при | Стар код, C++11/14 | Нов код, C++20 |

### Разделна компилация

```
❌ Темплейт дефиниция в .cpp → линк грешка
✅ Темплейт дефиниция в .hpp (или в края на .h)
```

### `std::tuple` — бърза справка

```
make_tuple(a, b, c)           създава tuple
get<N>(t)                     достъп по индекс (compile-time!)
get<Type>(t)                  достъп по тип (само при уникални типове)
tie(a, b, c) = t              разпакетиране
auto [a, b, c] = t            structured binding (C++17)
tuple_size<T>::value          брой елементи
tuple_element<N, T>::type     тип на N-тия елемент
```

### Правила

```
✅ Дефиницията на темплейт е в .hpp — не в .cpp
✅ Документирай какво трябва да поддържа T
✅ Ползвай Concepts вместо SFINAE при C++20
✅ Частична специализация — само за класове
✅ При вариадични с рекурсия — задължителен base case
✅ Fold expressions (C++17) заменят рекурсията

❌ Темплейт в .cpp → undefined reference при линкване
❌ Частична специализация на функция → overload, не специализация
❌ std::get с runtime индекс → грешка при компилация
❌ SFINAE с припокриващи се условия → ambiguous overload
❌ Concept не проверява стойности — само типове
```

> **Основен извод:** Темплейтите са инструмент за генериране на код от компилатора. Цялата дефиниция трябва да е видима в хедъра — иначе компилаторът не може да генерира конкретната версия при употреба. SFINAE позволява ограничаване по тип, но с нечетими грешки. Concepts (C++20) решават това с именувани ограничения и ясни съобщения. Вариадичните темплейти и `std::tuple` позволяват работа с произволен брой разнотипни стойности.
