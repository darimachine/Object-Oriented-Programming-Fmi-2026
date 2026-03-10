# `std::function` и Ламбда функции в C++


## 1. Защо ни трябват функции като стойности?

Искаме да сортираме списък от хора — понякога по име, понякога по възраст. Без ламбди трябва да пишем отделна функция за всеки случай:

```cpp
bool byName(const Person& a, const Person& b) { return a.name < b.name; }
bool byAge (const Person& a, const Person& b) { return a.age  < b.age;  }

std::sort(people.begin(), people.end(), byName);
std::sort(people.begin(), people.end(), byAge);
```

С ламбди го пише, директно на място — без да именуваш функцията:

```cpp
std::sort(people.begin(), people.end(),
    [](const Person& a, const Person& b) { return a.name < b.name; });
```

> **Идея:** Ламбдата е „безименна функция" която можеш да напишеш точно там, където ти трябва.

---

## 2. Ламбда функции — основи

### Анатомия на ламбдата

```
[ capture ] ( параметри ) -> тип_връщане { тяло }
    ^              ^              ^            ^
    |              |              |            |
  какво         входни         какво        код
 захваща       данни          връща
от средата
```

Типът на връщане е **незадължителен** — компилаторът сам го разбира.

### Най-простата ламбда

```cpp
auto sayHello = []() {
    std::cout << "Здравей!\n";
};

sayHello();  // Здравей!
```

### Ламбда с параметри

```cpp
auto add = [](int a, int b) {
    return a + b;
};

std::cout << add(3, 4);  // 7
```

### Ламбда с изричен тип на връщане

```cpp
auto divide = [](double a, double b) -> double {
    if (b == 0) return 0.0;
    return a / b;
};

std::cout << divide(10.0, 3.0);  // 3.333...
```

### Ламбдата е обект!

Ламбдата **не е просто функция** — тя е обект от специален анонимен клас, създаден от компилатора. Затова можем да я пазим в `auto` или `std::function`.

```cpp
auto myLambda = [](int x) { return x * 2; };
// компилаторът създава нещо като:
// class __anonymous__ {
//     int operator()(int x) const { return x * 2; }
// };
```

---

## 3. Capture list — как ламбдата вижда външия свят

Ламбдата живее в „балон" — тя не вижда автоматично променливите около нея. Трябва изрично да кажем кое да „захване" (capture).

### `[]` — Не захваща нищо

```cpp
int x = 10;

auto f = []() {
    std::cout << x;  // ❌ ГРЕШКА — x не е захванато!
};
```

### `[x]` — Захваща `x` по стойност (копие)

```cpp
int x = 10;

auto f = [x]() {
    std::cout << x;  // ✅ вижда копие на x = 10
};

x = 99;   // променяме x отвън
f();      // печата 10 — ламбдата има КОПИЕ от момента на създаване
```

### `[&x]` — Захваща `x` по референция

```cpp
int x = 10;

auto f = [&x]() {
    std::cout << x;  // вижда ОРИГИНАЛНИЯ x
};

x = 99;
f();  // печата 99 — вижда промяната!
```

### `[=]` — Захваща ВСИЧКО по стойност

```cpp
int a = 1, b = 2, c = 3;

auto f = [=]() {
    std::cout << a + b + c;  // копия на всичко
};

f();  // 6
```

### `[&]` — Захваща ВСИЧКО по референция

```cpp
int total = 0;

auto addToTotal = [&](int x) {
    total += x;  // директно променя total
};

addToTotal(5);
addToTotal(3);
std::cout << total;  // 8
```

### Смесено захващане

```cpp
int base = 100;
int bonus = 20;

auto calc = [base, &bonus](int salary) {
    bonus += 5;          // може да промени bonus (по референция)
    return base + bonus + salary;  // base е копие
};
```

### Таблица с capture опциите

| Capture | Значение |
|---|---|
| `[]` | Нищо не захваща |
| `[x]` | `x` по стойност (копие) |
| `[&x]` | `x` по референция |
| `[=]` | Всичко по стойност |
| `[&]` | Всичко по референция |
| `[=, &x]` | Всичко по стойност, освен `x` по референция |
| `[&, x]` | Всичко по референция, освен `x` по стойност |

---

## 4. `std::function` — пазим функции в променливи

### Проблемът с `auto`

`auto` работи когато знаем типа веднага:

```cpp
auto f = [](int x) { return x * 2; };  // OK
```

Но какво ако искаме да пазим **различни функции** в един и същи контейнер, или да подаваме функция като параметър на клас?

```cpp
std::vector<auto> functions;  // ❌ не работи!
```

### Решението: `std::function`

`std::function<тип_връщане(параметри)>` е универсална „кутия" в която можем да сложим **всякакъв вид функция** с дадена сигнатура.

```cpp
#include <functional>

// Кутия за функция която приема int и връща int
std::function<int(int)> myFunc;

// Можем да сложим ламбда:
myFunc = [](int x) { return x * 2; };
std::cout << myFunc(5);  // 10

// Можем да сложим обикновена функция:
int triple(int x) { return x * 3; }
myFunc = triple;
std::cout << myFunc(5);  // 15

// Можем да сменяме по всяко време:
myFunc = [](int x) { return x + 100; };
std::cout << myFunc(5);  // 105
```

### Четене на сигнатурата

```cpp
std::function< int ( int, double ) >
//             ^        ^
//          връща    параметри
```

| Сигнатура | Значение |
|---|---|
| `std::function<void()>` | Не приема нищо, не връща нищо |
| `std::function<int(int)>` | Приема `int`, връща `int` |
| `std::function<bool(int, int)>` | Приема два `int`, връща `bool` |
| `std::function<std::string(double)>` | Приема `double`, връща `string` |

### `std::function` в клас

```cpp
#include <functional>

class Button {
public:
    std::string label;
    std::function<void()> onClick;  // пазим функцията като поле

    Button(std::string l, std::function<void()> action)
        : label(l), onClick(action) {}

    void press() {
        std::cout << "Бутон '" << label << "' натиснат!\n";
        if (onClick) onClick();  // проверяваме дали е зададена
    }
};

int main() {
    Button saveBtn("Запази", []() {
        std::cout << "Файлът е запазен!\n";
    });

    Button exitBtn("Изход", []() {
        std::cout << "Довиждане!\n";
    });

    saveBtn.press();
    exitBtn.press();
}
// Изход:
// Бутон 'Запази' натиснат!
// Файлът е запазен!
// Бутон 'Изход' натиснат!
// Довиждане!
```

---

## 5. Подаване на функции като параметри

Едно от честите приложения — подаване на функция като аргумент.

### С `std::function`

```cpp
#include <functional>
#include <vector>

void applyToAll(std::vector<int>& nums, std::function<void(int&)> action) {
    for (auto& n : nums) {
        action(n);
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // Удвояваме всяко число
    applyToAll(nums, [](int& n) { n *= 2; });
    // nums = {2, 4, 6, 8, 10}

    // Добавяме 10 към всяко
    applyToAll(nums, [](int& n) { n += 10; });
    // nums = {12, 14, 16, 18, 20}

    for (int n : nums) std::cout << n << " ";
    // 12 14 16 18 20
}
```

### Функция която връща функция

```cpp
std::function<int(int)> makeMultiplier(int factor) {
    return [factor](int x) {
        return x * factor;  // захващаме factor
    };
}

auto times3 = makeMultiplier(3);
auto times5 = makeMultiplier(5);

std::cout << times3(4);   // 12
std::cout << times5(4);   // 20
```

> 💡Тази техника се казва **затваряне (closure)** — ламбдата „затваря" в себе си стойността на `factor`.

---

## 6. Ламбди с STL алгоритми

Ламбдите са идеални за STL алгоритмите в `<algorithm>`.

### `std::sort` — сортиране по критерий

```cpp
#include <algorithm>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;
};

std::vector<Person> people = {
    {"Иван", 25}, {"Мария", 30}, {"Петър", 20}
};

// Сортиране по възраст (нарастващо)
std::sort(people.begin(), people.end(),
    [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
// Петър(20), Иван(25), Мария(30)

// Сортиране по име
std::sort(people.begin(), people.end(),
    [](const Person& a, const Person& b) {
        return a.name < b.name;
    });
```

### `std::find_if` — намиране по условие

```cpp
auto it = std::find_if(people.begin(), people.end(),
    [](const Person& p) {
        return p.age > 24;  // търсим първия над 24 год.
    });

if (it != people.end())
    std::cout << "Намерен: " << it->name;
```

### `std::count_if` — броене по условие

```cpp
int adults = std::count_if(people.begin(), people.end(),
    [](const Person& p) { return p.age >= 18; });

std::cout << "Пълнолетни: " << adults;
```

### `std::transform` — трансформиране

```cpp
std::vector<int> nums = {1, 2, 3, 4, 5};
std::vector<int> squared(nums.size());

std::transform(nums.begin(), nums.end(), squared.begin(),
    [](int x) { return x * x; });
// squared = {1, 4, 9, 16, 25}
```

---

## 7. Пълен пример — Калкулатор

```cpp
#include <iostream>
#include <functional>
#include <map>
#include <string>

class Calculator {
private:
    // Речник: символ → функция
    std::map<std::string, std::function<double(double, double)>> operations;

public:
    Calculator() {
        // Регистрираме операциите с ламбди
        operations["+"] = [](double a, double b) { return a + b; };
        operations["-"] = [](double a, double b) { return a - b; };
        operations["*"] = [](double a, double b) { return a * b; };
        operations["/"] = [](double a, double b) -> double {
            if (b == 0) {
                std::cout << "Грешка: деление на нула!\n";
                return 0;
            }
            return a / b;
        };
    }

    // Добавяне на нова операция отвън
    void addOperation(const std::string& symbol,
                      std::function<double(double, double)> op) {
        operations[symbol] = op;
    }

    double calculate(double a, const std::string& op, double b) {
        if (operations.count(op) == 0) {
            std::cout << "Непозната операция: " << op << "\n";
            return 0;
        }
        return operations[op](a, b);
    }

    void printResult(double a, const std::string& op, double b) {
        std::cout << a << " " << op << " " << b
                  << " = " << calculate(a, op, b) << "\n";
    }
};

int main() {
    Calculator calc;

    calc.printResult(10, "+", 5);   // 10 + 5 = 15
    calc.printResult(10, "-", 3);   // 10 - 3 = 7
    calc.printResult(4,  "*", 6);   // 4 * 6 = 24
    calc.printResult(15, "/", 4);   // 15 / 4 = 3.75
    calc.printResult(5,  "/", 0);   // Грешка: деление на нула!

    // Добавяме нова операция — степенуване
    calc.addOperation("^", [](double a, double b) {
        double result = 1;
        for (int i = 0; i < (int)b; i++) result *= a;
        return result;
    });

    calc.printResult(2, "^", 8);   // 2 ^ 8 = 256

    return 0;
}
```

### Изход:
```
10 + 5 = 15
10 - 3 = 7
4 * 6 = 24
15 / 4 = 3.75
Грешка: деление на нула!
5 / 0 = 0
2 ^ 8 = 256
```

---

## 8. Чести грешки

###  Грешка 1: Dangling reference в capture

```cpp
std::function<int()> makeCounter() {
    int count = 0;

    return [&count]() {   // ❌ захващаме локалната count по референция
        return ++count;
    };
}  // count е унищожена тук!

auto counter = makeCounter();
counter();  // ❌ undefined behavior — count вече не съществува!
```

**Решение:** Захвати по стойност когато ламбдата живее по-дълго от променливата:

```cpp
std::function<int()> makeCounter() {
    int count = 0;
    return [count]() mutable {  // ✅ копие на count
        return ++count;
    };
}
```

###  Грешка 2: Забравена `mutable` при промяна на копие

```cpp
int x = 10;
auto f = [x]() {
    x++;  // ❌ ГРЕШКА — копието е const по подразбиране!
};
```

**Решение:** Добави `mutable`:

```cpp
auto f = [x]() mutable {
    x++;  // ✅ сега може да се промени (само копието, не оригинала)
};
```

### ❌Грешка 3: Празна `std::function` се вика

```cpp
std::function<void()> f;  // празна!

f();  // ❌ хвърля std::bad_function_call exception!
```

**Решение:** Проверявай преди извикване:

```cpp
if (f) {
    f();  // ✅ безопасно
}
```

---

## 9. Обобщение

### Ламбда функция

```
[capture](параметри) { тяло }
```

- Безименна функция дефинирана на място
- Може да „захваща" променливи от обкръжаващия код
- `[=]` — всичко по стойност, `[&]` — всичко по референция

### `std::function`

```cpp
std::function<ТипВръщане(Параметри)> f;
```

- Универсална „кутия" за всякакви функции с дадена сигнатура
- Може да съдържа: ламбди, обикновени функции, методи
- Позволява да пазим функции в полета на класове и контейнери

### Кога какво да ползваш

| Ситуация | Препоръка |
|---|---|
| Еднократна употреба на място | `auto f = [...](...){...}` |
| Подаване като параметър за шаблонна функция | `auto` параметър или template |
| Пазене в клас или контейнер | `std::function<...>` |
| Функцията трябва да вижда локални променливи | Capture list `[=]` или `[&]` |
| Функцията живее по-дълго от локалните й | Capture по стойност `[=]` |

> **Накратко:**
> - **Ламбда** = безименна функция, пишеш я там където ти трябва
> - **Capture** = казваш на ламбдата кои променливи да „погледне" отвън
> - **`std::function`** = кутия в която можеш да сложим всякаква функция и да я пазим колкото искаме
