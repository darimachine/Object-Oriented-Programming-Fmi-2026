# Предефиниране на Оператори в C++

---

## Съдържание

1. [Какво е предефиниране на оператори?](#1-какво-е-предефиниране-на-оператори)
2. [Синтаксис](#2-синтаксис)
3. [Оператори като методи vs. свободни функции](#3-оператори-като-методи-vs-свободни-функции)
4. [Приятелски функции и класове (friend)](#4-приятелски-функции-и-класове-friend)
5. [Задължителни оператори — `==` и `<`](#5-задължителни-оператори----и-)
6. [Операторът `<=>` (Spaceship)](#6-операторът--spaceship)
7. [Ключовата дума `auto`](#7-ключовата-дума-auto)
8. [Оператор `<<` и `>>` (вход/изход)](#8-оператор--и--входизход)
9. [Аритметични оператори](#9-аритметични-оператори)
10. [Оператор `[]` (индексиране)](#10-оператор--индексиране)
11. [Пълен пример — клас `Person` (Теми 5 и 6)](#11-пълен-пример--клас-person-теми-5-и-6)
12. [Пълен пример — клас `DynamicArray`](#12-пълен-пример--клас-dynamicarray)
13. [Edge Cases и капани](#13-edge-cases-и-капани)
14. [Кои оператори не могат да се предефинират](#14-кои-оператори-не-могат-да-се-предефинират)
15. [Обобщение](#15-обобщение)

---

## 1. Какво е предефиниране на оператори?

В C++ операторите като `+`, `==`, `<`, `<<` и т.н. са вградени само за примитивни типове (`int`, `double`, `char`...). За собствени класове тези оператори **не съществуват по подразбиране**.

```cpp
class Person {
    char* name;
    int   age;
};

Person p1("Иван", 20);
Person p2("Мария", 21);

if (p1 == p2) { }    // ❌ ГРЕШКА — == не е дефиниран за Person
if (p1 < p2)  { }    // ❌ ГРЕШКА
std::cout << p1;      // ❌ ГРЕШКА
```

**Предефинирането на оператори** позволява да се дефинира поведението на стандартните оператори за собствени класове. Целта е кодът да изглежда естествено и четимо.

```cpp
// След предефиниране:
if (p1 == p2)     std::cout << "Еднакви\n";
if (p1 < p2)      std::cout << "p1 е по-млад\n";
std::cout << p1;  // Иван (20)
```

### Какво всъщност се случва

Когато компилаторът срещне `p1 == p2`, той го преобразува в едно от следните:

```cpp
p1 == p2
// → p1.operator==(p2)      ако е метод на класа
// → operator==(p1, p2)     ако е свободна функция
```

Операторите не са нищо специално — те са **функции с особено синтактично извикване**.

---

## 2. Синтаксис

### Като метод на класа

```cpp
class MyClass {
public:
    ReturnType operatorOP(параметри) const {
        // тяло
    }
};
```

`OP` е символът на оператора — `==`, `<`, `+`, `[]` и т.н.

### Като свободна функция

```cpp
ReturnType operatorOP(const MyClass& lhs, const MyClass& rhs) {
    // тяло
}
```

### Кога `const` е задължително

`const` след параметрите на метода означава „този метод не модифицира обекта (`*this`)". При оператори за сравнение (`==`, `<`, `>`) `const` е **задължително** — сравнението никога не трябва да променя обектите.

```cpp
bool operator==(const Person& other) const {
//                                   ^^^^^
//                          не модифицира *this
    return age == other.age;
}
```

---

## 3. Оператори като методи vs. свободни функции

### Като метод

```cpp
class Person {
public:
    bool operator==(const Person& other) const {
        return age == other.age;
    }
};

p1 == p2;   // → p1.operator==(p2)
            // p1 е *this, p2 е other
```

Лявата страна на оператора винаги е `*this`. Методът има директен достъп до `private` членове.

### Като свободна функция

```cpp
bool operator==(const Person& lhs, const Person& rhs) {
    return lhs.getAge() == rhs.getAge();   // само чрез public интерфейс
}

p1 == p2;   // → operator==(p1, p2)
```

Свободната функция **няма достъп до `private` членове** без `friend` декларация. Затова при оператори, които изискват достъп до вътрешното състояние, се използва `friend`.

### Кога да се използва кое

| Оператор | Форма |
|---|---|
| `=`, `[]`, `()`, `->` | Задължително метод |
| `==`, `<`, `>`, `<=`, `>=`, `!=` | Метод или `friend` функция |
| `<<`, `>>` | Задължително `friend` функция |
| `+`, `-`, `*`, `/` | `friend` функция (симетрия) |

---

## 4. Приятелски функции и класове (`friend`)

### Какво е `friend`?

`friend` е декларация в тялото на клас, която дава на **функция или друг клас** достъп до `private` и `protected` членовете — без да са членове на класа.

```cpp
class Person {
    char* name;   // private
    int   age;    // private

public:
    friend void printSecret(const Person& p);   // декларация на приятелска функция
};

// Дефиниция — извън класа, НО има достъп до private
void printSecret(const Person& p) {
    std::cout << p.name << ", " << p.age << "\n";   // достъп до private!
}
```

`friend` **не е метод** — не се извиква с `.` или `->` и няма `this` указател. Просто получава специален достъп.

### `friend` функции и оператори

Най-честата употреба на `friend` е при предефиниране на оператори, при които лявата страна не е обект от нашия клас — например `operator<<`:

```cpp
class Person {
    char* name;
    int   age;
public:
    // ostream е вляво, Person е вдясно → не може да е метод на Person
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << " (" << p.age << ")";   // достъп до private
    return os;
}

Person ivan("Иван", 20);
std::cout << ivan;   // Иван (20)
```

### `friend` класове

Целен клас може да е обявен за `friend`. Тогава **всички методи** на приятелския клас имат достъп до `private` членовете:

```cpp
class Engine {
    int horsepower;   // private
    friend class Car; // Car има достъп до всичко в Engine
public:
    Engine(int hp) : horsepower(hp) {}
};

class Car {
    Engine engine;
public:
    Car(int hp) : engine(hp) {}

    void showPower() {
        // Достъп до engine.horsepower въпреки че е private!
        std::cout << "Мощност: " << engine.horsepower << " к.с.\n";
    }
};
```

### Важни свойства на `friend`

```
✅ friend функция може да е и свободна, и метод на друг клас
✅ friend дава достъп в едната посока — A приятел на B не означава B приятел на A
✅ friend не се наследява — ако B е приятел на A, наследник на B не е приятел на A
❌ friend нарушава enkapsulацията — трябва да се ползва само при нужда
```

### Кога се използва `friend`

- При `operator<<` и `operator>>` — задължително
- При оператори, при които двете страни са от различни типове
- При тясно свързани класове, където достъпът до `private` е оправдан по дизайн

---

## 5. Задължителни оператори — `==` и `<`

### Оператор `==` — равенство

Проверява дали два обекта са **равни по смисъл**. Какво означава „равни" зависи от логиката на класа.

```cpp
class Person {
    char* name;
    int   age;
public:
    bool operator==(const Person& other) const {
        if (age != other.age) return false;
        if (name == nullptr && other.name == nullptr) return true;
        if (name == nullptr || other.name == nullptr) return false;
        return strcmp(name, other.name) == 0;
    }

    // != се извежда от ==
    bool operator!=(const Person& other) const {
        return !(*this == other);
    }
};
```

```cpp
Person ivan("Иван", 20);
Person ivan2("Иван", 20);
Person maria("Мария", 21);

ivan == ivan2;   // true
ivan == maria;   // false
ivan != maria;   // true
```

### Оператор `<` — наредба

Дефинира **строго наредбено отношение** — кой обект е „по-малък". Задължително изискване за сортиране и за наредените контейнери от стандартната библиотека (`std::set`, `std::map`).

```cpp
// Сравняваме по възраст
bool operator<(const Person& other) const {
    return age < other.age;
}
```

От `operator<` могат да се изведат всички останали оператори за сравнение:

```cpp
bool operator> (const Person& other) const { return other < *this;   }
bool operator<=(const Person& other) const { return !(other < *this); }
bool operator>=(const Person& other) const { return !(*this < other); }
```

### Защо точно `==` и `<` са задължителни

| Оператор | Нужен за |
|---|---|
| `operator==` | `std::find`, `std::count`, `std::unordered_set`, `std::unordered_map` |
| `operator<` | `std::sort`, `std::set`, `std::map`, `std::lower_bound` |

Без тях класът не може да се използва пълноценно в стандартната библиотека.

---

## 6. Операторът `<=>` (Spaceship)

### Какво е `<=>`?

Въведен в **C++20**, операторът `<=>` се нарича **three-way comparison** (тройно сравнение) или **spaceship operator** (изглежда като кораб `<=>`). Едно извикване на `<=>` дава информация за трите възможни отношения между два обекта.

```cpp
auto result = a <=> b;
// result < 0   →   a < b
// result == 0  →   a == b
// result > 0   →   a > b
```

### Типове на резултата от `<include <compare>`

| Тип | Кога се използва |
|---|---|
| `std::strong_ordering` | Пълна наредба — равни обекти са идентични (`int`, `char`) |
| `std::weak_ordering` | Наредба — равни обекти може да се различават по нещо (`std::string` ignore case) |
| `std::partial_ordering` | Някои двойки са несравними (напр. `NaN` при `float`) |

За повечето класове се използва **`std::strong_ordering`**.

### Проблемът преди C++20 — много код

За пълен набор оператори за сравнение трябваха **5 отделни функции**:

```cpp
bool operator==(const Person& o) const { return age == o.age; }
bool operator!=(const Person& o) const { return age != o.age; }
bool operator< (const Person& o) const { return age <  o.age; }
bool operator<=(const Person& o) const { return age <= o.age; }
bool operator> (const Person& o) const { return age >  o.age; }
bool operator>=(const Person& o) const { return age >= o.age; }
// 6 функции за едно и също нещо!
```

### Решението — един оператор вместо шест

С `<=>` се пишат **само два оператора** (`<=>` и `==`) и компилаторът автоматично генерира останалите четири:

```cpp
#include <compare>

class Person {
    char* name;
    int   age;
public:
    // Само тези два са нужни:
    bool operator==(const Person& other) const {
        return age == other.age;
    }

    std::strong_ordering operator<=>(const Person& other) const {
        return age <=> other.age;
    }
};

Person ivan("Иван", 20);
Person maria("Мария", 21);

ivan == maria;   // false  — извиква operator==
ivan != maria;   // true   — генериран от компилатора чрез ==
ivan <  maria;   // true   — генериран от компилатора чрез <=>
ivan <= maria;   // true   — генериран от компилатора чрез <=>
ivan >  maria;   // false  — генериран от компилатора чрез <=>
ivan >= maria;   // false  — генериран от компилатора чрез <=>
```

### `= default` — напълно автоматично

Ако всички полета на класа поддържат `<=>`, може да се използва `= default` и компилаторът генерира **всичко автоматично**:

```cpp
class Point {
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}

    auto operator<=>(const Point&) const = default;
    // Генерира: ==, !=, <, <=, >, >= — всичките!
};

Point a(1, 2), b(1, 3);
a == b;   // false
a <  b;   // true  (сравнява x, после y)
```

### `= default` сравнява полетата **лексикографски**

При `= default` полетата се сравняват в реда, в който са декларирани в класа:

```cpp
class Person {
    int   age;    // 1. Първо се сравнява age
    float grade;  // 2. После grade (само ако age е равно)
public:
    auto operator<=>(const Person&) const = default;
};
```

### Защо `auto` като тип на връщане

`auto` позволява на компилатора сам да определи типа (`strong_ordering`, `weak_ordering` и т.н.) въз основа на типовете на полетата. Ако ръчно пишем логика, задаваме типа изрично:

```cpp
// Ръчна логика — типът е изричен
std::strong_ordering operator<=>(const Person& other) const {
    if (auto cmp = age <=> other.age; cmp != 0)
        return cmp;
    return strcmp(name, other.name) <=> 0;
}

// = default — auto е удобен
auto operator<=>(const Person&) const = default;
```

### Как `<=>` работи с `char*`

`char*` не поддържа `<=>` директно (сравнява указатели, не съдържание). При клас с `char*` трябва ръчна имплементация:

```cpp
std::strong_ordering operator<=>(const Person& other) const {
    // Първо по възраст
    if (auto cmp = age <=> other.age; cmp != 0)
        return cmp;
    // После по име (lexicographic)
    int cmpName = strcmp(name ? name : "", other.name ? other.name : "");
    return cmpName <=> 0;
}
```

---

## 7. Ключовата дума `auto`

### Какво е `auto`?

`auto` казва на компилатора: **„Ти определи типа — аз не искам да го пиша изрично."** Типът се определя по време на компилация въз основа на стойността вдясно от `=`.

```cpp
auto x     = 5;         // int
auto y     = 3.14;      // double
auto z     = true;      // bool
auto s     = std::string("hi");  // std::string
```

### `auto` губи `const` и `&`

Това е най-честата грешка с `auto`. При копиране `auto` премахва квалификаторите:

```cpp
const int x = 10;
auto a = x;        // a е int, НЕ const int — може да се промени!

int y = 5;
int& ref = y;
auto b = ref;      // b е int, НЕ int& — копие, не референция!
b = 99;
std::cout << y;    // 5 — y не е засегнат
```

За да се запазят, трябва да се напишат изрично:

```cpp
const auto  ca = x;    // const int
auto&       rb = ref;  // int&
const auto& cr = x;    // const int& (препоръчително за четене)
```

### `auto` с оператор `<=>`

`auto` е особено полезен като тип на връщане на `operator<=>`, защото типът на резултата (`strong_ordering`, `weak_ordering`...) е дълъг и зависи от полетата:

```cpp
// Без auto — трябва да знаем точния тип:
std::strong_ordering operator<=>(const Person& other) const {
    return age <=> other.age;
}

// С auto — компилаторът сам определя типа:
auto operator<=>(const Person& other) const {
    return age <=> other.age;
}
```

---


## Операторът `<=>` — какво връща?

Операторът `<=>` (spaceship) не връща `bool` и не връща `int`. Той връща специален обект, който носи информация за **три възможни отношения** между двата операнда наведнъж — по-малко, равно или по-голямо.

```cpp
int a = 20;
int b = 21;

auto result = a <=> b;
```

`result` не е `true` или `false`. `result` е обект от тип **`std::strong_ordering`**, който може да има една от три стойности:

```
std::strong_ordering::less     →  a < b
std::strong_ordering::equal    →  a == b
std::strong_ordering::greater  →  a > b
```

### Сравняване с `0`

`std::strong_ordering` не може да се принтира директно, но може да се **сравнява с нула**:

```cpp
auto cmp = a <=> b;  // a = 20, b = 21

if (cmp < 0)   std::cout << "a < b\n";   // ✅ вярно
if (cmp == 0)  std::cout << "a == b\n";  // ❌ невярно
if (cmp > 0)   std::cout << "a > b\n";   // ❌ невярно
if (cmp != 0)  std::cout << "различни\n";// ✅ вярно
```

**сравнява се с `0`, не с `true`/`false` и не с число**.

### `auto` при `<=>`

Типът `std::strong_ordering` е дълъг за писане. `auto` го извежда автоматично:

```cpp
// Без auto — трябва да знаем точния тип:
std::strong_ordering cmp = a <=> b;

// С auto — компилаторът сам определя типа:
auto cmp = a <=> b;   // по-кратко и еквивалентно
```

---

## `std::strong_ordering` — как работи?

`std::strong_ordering` е дефиниран в хедъра `<compare>` и представлява **строго наредбено отношение**. „Строго" означава, че ако два обекта са равни (`equal`), те са **напълно идентични** — няма как да се различават по нещо.

### Трите стойности

```cpp
#include <compare>

std::strong_ordering::less      // "по-малко"
std::strong_ordering::equal     // "равно"
std::strong_ordering::greater   // "по-голямо"
```

### Как се получават

При `int <=> int` компилаторът автоматично определя стойността:

```cpp
5  <=> 10   →  std::strong_ordering::less
10 <=> 10   →  std::strong_ordering::equal
10 <=>  5   →  std::strong_ordering::greater
```

---

## `strcmp` и конвертиране към `strong_ordering`

### Проблемът

`strcmp` сравнява два `char*` низа и връща **`int`**:

```cpp
int result = strcmp("Иван", "Мария");
// result < 0   →  "Иван" е преди "Мария" лексикографски
// result == 0  →  низовете са равни
// result > 0   →  "Иван" е след "Мария" лексикографски
```

Но нашата функция `operator<=>` трябва да върне `std::strong_ordering`, **не `int`**. Не може просто да върнем резултата от `strcmp`.

### Решението — `strcmp(...) <=> 0`

```cpp
return strcmp(n1, n2) <=> 0;
```

Тук се прилага `<=>` между **`int`** (резултатът от `strcmp`) и **`0`** (също `int`). Резултатът е `std::strong_ordering`:

```
strcmp("Иван", "Мария")  →  отрицателно число  (примерно -5)
-5 <=> 0                 →  std::strong_ordering::less

strcmp("Мария", "Мария") →  0
0 <=> 0                  →  std::strong_ordering::equal

strcmp("Мария", "Иван")  →  положително число  (примерно 5)
5 <=> 0                  →  std::strong_ordering::greater
```

Това е **стандартният начин** да се конвертира `int` резултат (от `strcmp`, `memcmp` или друга C функция) към `std::strong_ordering`.

### Защо `<=> 0`, а не нещо друго?

`<=>` с `0` работи защото:
- Ако `strcmp` върне отрицателно → `отрицателно <=> 0` → `less`
- Ако `strcmp` върне `0`         → `0 <=> 0`          → `equal`
- Ако `strcmp` върне положително → `положително <=> 0` → `greater`

Точно това ни трябва.

---

## Целият поток — пример стъпка по стъпка

Разглеждаме пълната имплементация:

```cpp
std::strong_ordering operator<=>(const Person& other) const {
    if (auto cmp = age <=> other.age; cmp != 0)
        return cmp;

    const char* n1 = name        ? name        : "";
    const char* n2 = other.name  ? other.name  : "";
    return strcmp(n1, n2) <=> 0;
}
```

Логиката е: **първо сравнявай по възраст, ако са равни — сравнявай по име**.

---

### Случай 1 — Различни възрасти

```cpp
Person ivan("Иван",  20);
Person maria("Мария", 21);

auto result = ivan <=> maria;
```

```
Стъпка 1: age <=> other.age  →  20 <=> 21
          →  std::strong_ordering::less

Стъпка 2: cmp != 0  →  less != 0  →  true
          →  return cmp  (strong_ordering::less)

Стъпка 3: НЕ се достига до strcmp — вече знаем отговора
```

Резултат: `strong_ordering::less` (Иван е по-млад от Мария)

---

### Случай 2 — Еднакви възрасти, различни имена

```cpp
Person ivan("Иван",  20);
Person alex("Алекс", 20);

auto result = ivan <=> alex;
```

```
Стъпка 1: age <=> other.age  →  20 <=> 20
          →  std::strong_ordering::equal

Стъпка 2: cmp != 0  →  equal != 0  →  false
          →  НЕ се връща, продължаваме

Стъпка 3: n1 = "Иван", n2 = "Алекс"
          strcmp("Иван", "Алекс")  →  положително (И > А)
          положително <=> 0  →  strong_ordering::greater

          return strong_ordering::greater
```

Резултат: `strong_ordering::greater` (Иван е след Алекс по азбучен ред)

---

### Случай 3 — Еднакви възрасти и имена

```cpp
Person ivan("Иван", 20);
Person ivan2("Иван", 20);

auto result = ivan <=> ivan2;
```

```
Стъпка 1: age <=> other.age  →  20 <=> 20
          →  strong_ordering::equal

Стъпка 2: cmp != 0  →  false  →  продължаваме

Стъпка 3: strcmp("Иван", "Иван")  →  0
          0 <=> 0  →  strong_ordering::equal

          return strong_ordering::equal
```

Резултат: `strong_ordering::equal`

---

### Употреба на резултата

```cpp
Person ivan("Иван", 20);
Person maria("Мария", 21);

auto cmp = ivan <=> maria;

if (cmp < 0)        std::cout << "Иван е преди Мария\n";
else if (cmp == 0)  std::cout << "Равни са\n";
else                std::cout << "Иван е след Мария\n";

// Изход: Иван е преди Мария
```

И всичките оператори за сравнение работят автоматично след дефинирането на `<=>`:

```cpp
ivan <  maria;   // true  — компилаторът ползва <=>
ivan <= maria;   // true
ivan >  maria;   // false
ivan >= maria;   // false
ivan == maria;   // false — ако е дефиниран и operator==
```

---

## Обобщение

### Бърза справка

| Израз | Тип на резултата | Значение |
|---|---|---|
| `a <=> b` (int) | `std::strong_ordering` | Сравнение на два `int` |
| `cmp < 0` | `bool` | `a < b` |
| `cmp == 0` | `bool` | `a == b` |
| `cmp > 0` | `bool` | `a > b` |
| `cmp != 0` | `bool` | `a != b` |
| `strcmp(s1,s2) <=> 0` | `std::strong_ordering` | Конвертира `int` → `ordering` |
| `auto cmp = ...` | `std::strong_ordering` | `auto` извежда типа |

### `auto` при съхраняване на резултат от `<=>`

```cpp
Person ivan("Иван", 20);
Person maria("Мария", 21);

auto result = ivan <=> maria;
// result е std::strong_ordering — auto ни спестява писането

if (result < 0)  std::cout << "Иван е по-млад\n";
if (result == 0) std::cout << "Еднакви\n";
if (result > 0)  std::cout << "Мария е по-млада\n";
```

### `auto` в range-based for

```cpp
std::vector<Person> people = { ... };

for (auto p : people)          // копие на всеки елемент
    p.print();

for (auto& p : people)         // референция — може да се модифицира
    p.setAge(p.getAge() + 1);

for (const auto& p : people)   // const референция — само четене
    p.print();
```

---

## 8. Оператор `<<` и `>>` (вход/изход)

### Оператор `<<` — изход

Лявата страна е `std::ostream` — затова **не може да е метод на нашия клас** и трябва да е `friend` функция:

```cpp
class Person {
    char* name;
    int   age;
public:
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << (p.name ? p.name : "???") << " (" << p.age << ")";
    return os;   // връщаме os за верижен запис: cout << p1 << p2
}

Person ivan("Иван", 20);
std::cout << ivan;              // Иван (20)
std::cout << ivan << "\n";      // Иван (20)\n  — верижен запис
```

Операторът връща `std::ostream&` за да работи верижният запис: `std::cout << p1 << p2` е еквивалентно на `(std::cout << p1) << p2`.

### Оператор `>>` — вход

```cpp
class Person {
    char* name;
    int   age;
public:
    friend std::istream& operator>>(std::istream& is, Person& p);
};

std::istream& operator>>(std::istream& is, Person& p) {
    char buffer[256];
    is >> buffer >> p.age;
    p.setName(buffer);
    return is;
}

Person p;
std::cin >> p;   // чете от стандартния вход
```

---

## 9. Аритметични оператори

### Оператор `+`

```cpp
class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x(x), y(y) {}

    // Като метод
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Или като friend функция (за симетрия при смесени типове)
    friend Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
        return Vector2D(lhs.x + rhs.x, lhs.y + rhs.y);
    }
};

Vector2D a(1, 2), b(3, 4);
Vector2D c = a + b;   // Vector2D(4, 6)
```

### Оператор `+=`

```cpp
Vector2D& operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;
    return *this;   // връща *this за верижен запис
}

Vector2D a(1, 2), b(3, 4);
a += b;   // a е (4, 6)
```

### Унарен `operator-` (отрицание)

```cpp
Vector2D operator-() const {
    return Vector2D(-x, -y);
}

Vector2D a(1, -2);
Vector2D b = -a;   // b е (-1, 2)
```

---

## 10. Оператор `[]` (индексиране)

`operator[]` задължително е метод. Трябват **две версии** — за четене и за запис:

```cpp
class DynamicArray {
    int* data;
    int  size;
public:
    // За запис: arr[i] = 5
    int& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Индексът е извън граница!");
        return data[index];
    }

    // За четене от const обект: cout << arr[i]
    const int& operator[](int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Индексът е извън граница!");
        return data[index];
    }
};

DynamicArray arr(5);
arr[0] = 10;            // извиква не-const версията
std::cout << arr[0];    // извиква const версията
```

---

## 11. Пълен пример — клас `Person` 

Класът `Person` от предишните теми, разширен с предефиниране на оператори.  
Прилага **Голямата Четворка** + всички необходими оператори:

```cpp
#include <iostream>
#include <cstring>
#include <compare>

class Person {
public:
    // --- Конструктор с параметри ---
    Person(const char* name, int age) {
        setName(name);
        setAge(age);
    }

    // --- Голямата Четворка ---
    Person() : name(nullptr), age(0) {}

    Person(const Person& other) {
        copyFrom(other);
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~Person() {
        free();
    }

    // --- Setters / Getters ---
    void setName(const char* newName) {
        delete[] name;
        if (newName) {
            name = new char[strlen(newName) + 1];
            strcpy(name, newName);
        } else {
            name = nullptr;
        }
    }

    void        setAge(int a)    { if (a >= 0 && a <= 120) age = a; }
    const char* getName() const  { return name ? name : ""; }
    int         getAge()  const  { return age; }

    // -------------------------------------------------------
    // --- Предефинирани оператори ---
    // -------------------------------------------------------

    // --- operator== ---
    bool operator==(const Person& other) const {
        if (age != other.age) return false;
        const char* n1 = name        ? name        : "";
        const char* n2 = other.name  ? other.name  : "";
        return strcmp(n1, n2) == 0;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    // --- operator< (по възраст, после по име) ---
    bool operator<(const Person& other) const {
        if (age != other.age) return age < other.age;
        const char* n1 = name        ? name        : "";
        const char* n2 = other.name  ? other.name  : "";
        return strcmp(n1, n2) < 0;
    }

    bool operator> (const Person& other) const { return other < *this;    }
    bool operator<=(const Person& other) const { return !(other < *this); }
    bool operator>=(const Person& other) const { return !(*this < other); }

    // --- operator<=> (C++20) ---
    std::strong_ordering operator<=>(const Person& other) const {
        if (auto cmp = age <=> other.age; cmp != 0)
            return cmp;
        const char* n1 = name        ? name        : "";
        const char* n2 = other.name  ? other.name  : "";
        return strcmp(n1, n2) <=> 0;
    }

    // --- operator<< (friend — лявата страна е ostream) ---
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << (p.name ? p.name : "???") << " (" << p.age << ")";
        return os;
    }

    // --- operator>> (friend) ---
    friend std::istream& operator>>(std::istream& is, Person& p) {
        char buffer[256];
        int  a;
        is >> buffer >> a;
        p.setName(buffer);
        p.setAge(a);
        return is;
    }

private:
    char* name = nullptr;
    int   age  = 0;

    void free() {
        delete[] name;
        name = nullptr;
    }

    void copyFrom(const Person& other) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        age = other.age;
    }
};

// -------------------------------------------------------
int main() {
    Person ivan("Иван", 20);
    Person maria("Мария", 21);
    Person ivan2("Иван", 20);

    std::cout << "=== operator<< ===\n";
    std::cout << ivan  << "\n";   // Иван (20)
    std::cout << maria << "\n";   // Мария (21)

    std::cout << "\n=== operator== и != ===\n";
    std::cout << (ivan == ivan2 ? "равни" : "различни") << "\n";  // равни
    std::cout << (ivan == maria ? "равни" : "различни") << "\n";  // различни

    std::cout << "\n=== operator< и > ===\n";
    std::cout << (ivan < maria  ? "Иван е по-млад"  : "Мария е по-млада") << "\n";
    std::cout << (maria > ivan  ? "Мария е по-стара": "Иван е по-стар")  << "\n";

    std::cout << "\n=== operator<=> ===\n";
    auto cmp = ivan <=> maria;
    if (cmp < 0)       std::cout << "Иван е по-млад\n";
    else if (cmp == 0) std::cout << "Еднакви\n";
    else               std::cout << "Иван е по-стар\n";

    std::cout << "\n=== Сортиране с operator< ===\n";
    std::vector<Person> people = {
        Person("Петър", 25),
        Person("Иван",  20),
        Person("Мария", 21)
    };
    std::sort(people.begin(), people.end());
    for (const auto& p : people)
        std::cout << p << "\n";
    // Иван (20)
    // Мария (21)
    // Петър (25)
}
```

---

## 12. Пълен пример — клас `DynamicArray`

```cpp
#include <iostream>
#include <stdexcept>
#include <compare>

class DynamicArray {
public:
    DynamicArray(int n) : size(n) {
        data = new int[n]();
    }

    // --- Голямата Четворка ---
    DynamicArray() : data(nullptr), size(0) {}

    DynamicArray(const DynamicArray& other) {
        copyFrom(other);
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~DynamicArray() { free(); }

    // --- operator[] (две версии!) ---
    int& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Индексът е извън граница!");
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Индексът е извън граница!");
        return data[index];
    }

    // --- operator== ---
    bool operator==(const DynamicArray& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++)
            if (data[i] != other.data[i]) return false;
        return true;
    }

    // --- operator< (лексикографско) ---
    bool operator<(const DynamicArray& other) const {
        int minSize = size < other.size ? size : other.size;
        for (int i = 0; i < minSize; i++) {
            if (data[i] != other.data[i])
                return data[i] < other.data[i];
        }
        return size < other.size;
    }

    // --- operator<=> (C++20) ---
    std::strong_ordering operator<=>(const DynamicArray& other) const {
        int minSize = size < other.size ? size : other.size;
        for (int i = 0; i < minSize; i++) {
            if (auto cmp = data[i] <=> other.data[i]; cmp != 0)
                return cmp;
        }
        return size <=> other.size;
    }

    // --- operator<< ---
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
        os << "[ ";
        for (int i = 0; i < arr.size; i++)
            os << arr.data[i] << " ";
        os << "]";
        return os;
    }

    int getSize() const { return size; }

private:
    int* data = nullptr;
    int  size = 0;

    void free() {
        delete[] data;
        data = nullptr;
    }

    void copyFrom(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
};

int main() {
    DynamicArray a(3);
    a[0] = 10; a[1] = 20; a[2] = 30;

    DynamicArray b = a;     // copy constructor
    std::cout << a << "\n"; // [ 10 20 30 ]
    std::cout << b << "\n"; // [ 10 20 30 ]

    std::cout << (a == b ? "равни" : "различни") << "\n";  // равни

    b[0] = 5;
    std::cout << (a < b ? "a е по-малко" : "b е по-малко") << "\n"; // b е по-малко

    auto cmp = a <=> b;
    std::cout << (cmp > 0 ? "a > b" : "a <= b") << "\n";   // a > b
}
```

---

## 13. Edge Cases и капани

### `operator=` и самоприсвояване

```cpp
Person& operator=(const Person& other) {
    // ❌ БЕЗ проверка:
    free();           // изтриваме name
    copyFrom(other);  // ако other == *this, name е вече изтрит → crash!
    return *this;
}

Person p("Иван", 20);
p = p;   // → crash без проверката
```

Задължителна проверка: `if (this != &other)`.

---

### `operator==` върху `nullptr` имена

```cpp
bool operator==(const Person& other) const {
    // ❌ Наивна имплементация:
    return strcmp(name, other.name) == 0;
    // Ако name е nullptr → CRASH!
}

// ✅ Правилно:
bool operator==(const Person& other) const {
    if (age != other.age) return false;
    const char* n1 = name        ? name        : "";
    const char* n2 = other.name  ? other.name  : "";
    return strcmp(n1, n2) == 0;
}
```

---

### `operator[]` без проверка на граници

```cpp
int& operator[](int index) {
    return data[index];   // ❌ Без проверка — undefined behavior при грешен индекс
}

// ✅ Правилно:
int& operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Индексът е извън граница!");
    return data[index];
}
```

---

### Липсваща `const` версия на `operator[]`

```cpp
// Само не-const версия:
int& operator[](int index) { return data[index]; }

void print(const DynamicArray& arr) {
    std::cout << arr[0];   // ❌ ГРЕШКА — arr е const, но operator[] не е const!
}
```

Задължително се дефинират **и двете версии** — с и без `const`.

---

### `operator<<` не е `friend` → няма достъп до `private`

```cpp
// ❌ Не е friend — не може да достъпи private членове
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name;   // ГРЕШКА: name е private
    return os;
}

// ✅ Декларира се friend в класа
class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
```

---

### `<=>` с `char*` — сравнява указатели, не съдържание

```cpp
// ❌ ГРЕШНО — сравнява адресите, не символите!
auto operator<=>(const Person& other) const = default;
// Ако класът съдържа char*, default не работи правилно!

// ✅ Ръчна имплементация за char*:
std::strong_ordering operator<=>(const Person& other) const {
    if (auto cmp = age <=> other.age; cmp != 0) return cmp;
    return strcmp(name ? name : "", other.name ? other.name : "") <=> 0;
}
```

---

### `auto` и загуба на `&` при `<=>`

```cpp
DynamicArray a(3), b(3);

auto result = a <=> b;
// result е std::strong_ordering — OK

// ❌ Не може:
// int result = a <=> b;   // ГРЕШКА — типът е strong_ordering, не int

// Сравняване:
if (result < 0)  std::cout << "a < b\n";
if (result == 0) std::cout << "a == b\n";
if (result > 0)  std::cout << "a > b\n";
```

---

## 14. Кои оператори не могат да се предефинират

| Оператор | Причина |
|---|---|
| `::` (scope resolution) | Фундаментален за езика |
| `.` (member access) | Фундаментален за езика |
| `.*` (pointer-to-member) | Фундаментален за езика |
| `?:` (ternary) | Не може да е функция |
| `sizeof` | Не е оператор в обичайния смисъл |
| `typeid` | Не е оператор в обичайния смисъл |
| `#`, `##` (preprocessor) | Работят преди компилацията |

---

## 15. Обобщение

### Всички разгледани оператори

```
┌──────────────────────────────────────────────────────────────┐
│  Оператор    │ Форма          │ const │ Връща              │
├──────────────────────────────────────────────────────────────┤
│  ==          │ метод / friend │  ✅   │ bool               │
│  !=          │ метод / friend │  ✅   │ bool               │
│  <           │ метод / friend │  ✅   │ bool               │
│  >           │ метод / friend │  ✅   │ bool               │
│  <=          │ метод / friend │  ✅   │ bool               │
│  >=          │ метод / friend │  ✅   │ bool               │
│  <=>         │ метод / friend │  ✅   │ strong_ordering    │
│  <<          │ friend         │  ✅   │ ostream&           │
│  >>          │ friend         │  ❌   │ istream&           │
│  =           │ задължит. метод│  ❌   │ MyClass&           │
│  []          │ задължит. метод│  двe  │ T& / const T&      │
│  +, -, *, / │ метод / friend │  ✅   │ MyClass (нов обект)│
│  +=, -=     │ метод          │  ❌   │ MyClass&           │
└──────────────────────────────────────────────────────────────┘
```

### `friend` — кратко напомняне

```
✅ Дава достъп до private/protected без да е член
✅ Задължително за operator<< и operator>>
✅ Не се наследява
❌ Нарушава enkapsulацията — ползва се само при нужда
```

### `<=>` vs. ръчни оператори

| | Ръчни (`==`, `<`, ...) | `<=>` (C++20) |
|---|---|---|
| Брой функции | 6 | 2 (`==` + `<=>`) |
| `char*` полета | Работи с `strcmp` | Изисква ръчна имплементация |
| `= default` | Не | Да (само за типове без `char*`) |
| Стандарт | C++11 | C++20 |

### `auto` — кратко напомняне

```
auto x = expr        → копие, губи const и &
auto& x = expr       → референция
const auto& x = expr → const референция (четене)
auto op<=>() const   → компилаторът определя типа на ordering
```

> **Основен извод:** Предефинирането на оператори прави класовете естествено интегрирани с езика и стандартната библиотека. `operator==` и `operator<` са задължителни — без тях класът не може да се използва с `std::sort`, `std::find` и наредените контейнери. `operator<=>` (C++20) замества шестте оператора за сравнение с два. `friend` функциите дават достъп до `private` членове при оператори като `<<`, при които лявата страна не е наш клас.