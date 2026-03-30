# Задача: Универсален вектор от цели числа – `NVector`

---

## Описание

Реализирайте клас `NVector`, който представя математически вектор от цели числа с произволен размер. Класът трябва да управлява динамично заделена памет и да поддържа:

- Аритметични операции между вектори
- Скаларни операции
- Проверки за перпендикулярност и успоредност
- Сравнение между вектори
- Достъп до елементи
- Проверка дали векторът е ненулев
- Прилагане на функция върху всеки елемент
- Вход/изход от потоци

---

##  Член-данни

- `int* data` — динамичен масив с елементите на вектора
- `int size` — текущият размер на вектора

---

## Конструктори и деструктор

| Конструктор | Описание |
|---|---|
| `NVector()` | Създава тримерен нулев вектор `{0, 0, 0}` |
| `NVector(int size)` | Създава нулев вектор с подаден размер |
| `NVector(const int* data, int size)` | Конструктор с масив от стойности и размер |
| `NVector(const NVector& other)` | Копиращ конструктор |
| `NVector& operator=(const NVector& other)` | Оператор за присвояване |
| `~NVector()` | Деструктор |

---

##  Оператори

| Оператор | Описание |
|---|---|
| `operator+` | Събиране на два вектора |
| `operator-` | Изваждане на два вектора |
| `operator*` | Умножение на вектор и скалар (отляво и отдясно) |
| `operator%` | Скаларно произведение между два вектора |
| `operator\|` | Проверка за перпендикулярност (`v1 % v2 == 0`) |
| `operator\|\|` | Проверка за успоредност |
| `operator+=` | Събира и модифицира текущия обект |
| `operator-=` | Изважда и модифицира текущия обект |
| `operator*=` | Умножава текущия вектор по скалар |
| `operator[]` | Достъп до елемент по индекс (с и без `const`) |
| `operator~` | Връща размера на вектора |
| `operator bool` | Връща `true` ако поне един елемент е различен от нула |
| `operator()` | Прилага `std::function<int(int)>` върху всеки елемент, връща нов `NVector` |
| `operator<<` | Извежда вектора в поток |
| `operator>>` | Чете вектора от поток |

---

### Оператори за сравнение — Част 1 (ръчна имплементация)

| Оператор | Описание |
|---|---|
| `operator==` | Два вектора са равни ако имат еднакъв размер и еднакви елементи |
| `operator!=` | Изведен от `operator==` |
| `operator<` | Лексикографско сравнение |
| `operator>` | Изведен от `operator<` |
| `operator<=` | Изведен от `operator<` |
| `operator>=` | Изведен от `operator<` |

### Оператори за сравнение — Част 2 (с `operator<=>`)

| Оператор | Описание |
|---|---|
| `operator<=>` | Замества всичките шест оператора с един |

---

## Допълнителни методи Подсказки
<details>

<summary> Hint </summary>

- **`void resize(int newSize)`**
  Преоразмерява вектора. Запазва текущите елементи и добавя `0` за новите позиции.

- **`NVector& calculate(const NVector& other, std::function<int(int, int)> operation)`**
  Изпълнява универсално аритметично действие елемент по елемент между два вектора.
  Използва се вътрешно от `operator+=` и `operator-=`.

</details>
---

## Бележки по имплементацията

### `operator bool`

Връща `true` ако поне един елемент е ненулев. Нулевият вектор се оценява като `false`.

```cpp
NVector v1({0, 0, 0}, 3);
NVector v2({1, 0, 0}, 3);

if (!v1) std::cout << "v1 е нулев вектор\n";   // печата
if (v2)  std::cout << "v2 е ненулев\n";         // печата
```

### `operator()`

Приема `std::function<int(int)>` и прилага функцията върху всеки елемент. Връща **нов** `NVector` — не модифицира текущия.

```cpp
NVector v({1, 2, 3, 4}, 4);

NVector doubled = v([](int x) { return x * 2; });
// doubled = {2, 4, 6, 8}

NVector squared = v([](int x) { return x * x; });
// squared = {1, 4, 9, 16}
```


<details>
<summary> Hint </summary>

### `calculate` и `std::function`

`calculate` приема `std::function<int(int, int)>` — по-гъвкаво от указател към функция, тъй като приема обикновени функции, ламбди и функционални обекти.

```cpp
// Вътрешна употреба:
NVector& NVector::operator+=(const NVector& other) {
    return calculate(other, [](int a, int b) { return a + b; });
}

NVector& NVector::operator-=(const NVector& other) {
    return calculate(other, [](int a, int b) { return a - b; });
}
```

</details>

### `operator|` — перпендикулярност

Два вектора са перпендикулярни когато скаларното им произведение е нула: `v1 % v2 == 0`.

### `operator||` — успоредност

Два вектора са успоредни когато единият е скаларен кратен на другия:
`v1[i] * v2[j] == v1[j] * v2[i]` за всички `i`, `j`.

### `operator*` — от двете страни

```cpp
NVector v({1, 2, 3}, 3);

NVector a = v * 3;   // вектор * скалар — метод на класа
NVector b = 3 * v;   // скалар * вектор — friend функция
```

---

### Оператори за сравнение — лексикографски ред

Сравнението следва **лексикографски ред** — като при речник. Векторите се сравняват елемент по елемент от ляво надясно. При първата разлика резултатът е определен. Ако всички елементи съвпадат, по-краткият вектор е по-малък.

```
{1, 2, 3} < {1, 2, 4}   → true  (3 < 4 на позиция 2)
{1, 2, 3} < {1, 3, 0}   → true  (2 < 3 на позиция 1)
{1, 2}    < {1, 2, 0}   → true  (по-кратък)
{1, 2, 3} == {1, 2, 3}  → true
```

### Част 1 — ръчна имплементация

Имплементирай `operator==` и `operator<`. Останалите четири се извеждат от тях:

```cpp
bool operator==(const NVector& lhs, const NVector& rhs);   // ръчно
bool operator!=(const NVector& lhs, const NVector& rhs);   // чрез ==
bool operator< (const NVector& lhs, const NVector& rhs);   // ръчно
bool operator> (const NVector& lhs, const NVector& rhs);   // чрез <
bool operator<=(const NVector& lhs, const NVector& rhs);   // чрез <
bool operator>=(const NVector& lhs, const NVector& rhs);   // чрез <
```

```cpp
// Извеждане на останалите от == и <:
bool operator!=(const NVector& lhs, const NVector& rhs) { return !(lhs == rhs); }
bool operator> (const NVector& lhs, const NVector& rhs) { return rhs < lhs;     }
bool operator<=(const NVector& lhs, const NVector& rhs) { return !(rhs < lhs);  }
bool operator>=(const NVector& lhs, const NVector& rhs) { return !(lhs < rhs);  }
```

### Част 2 — с `operator<=>`

След като ръчната версия работи, замести всичките шест с един оператор:

```cpp
#include <compare>

std::strong_ordering operator<=>(const NVector& lhs, const NVector& rhs);
// operator== трябва да остане или да се добави отделно
```

`operator<=>` връща `std::strong_ordering`:
- `std::strong_ordering::less`    — lhs < rhs
- `std::strong_ordering::equal`   — lhs == rhs
- `std::strong_ordering::greater` — lhs > rhs

```cpp
NVector a({1, 2, 3}, 3);
NVector b({1, 2, 4}, 3);

auto result = a <=> b;
if (result < 0) std::cout << "a < b\n";    // a < b

// Всички останали оператори работят автоматично:
a == b;   a != b;   a < b;   a > b;   a <= b;   a >= b;
```

---

## Пример за използване

```cpp
#include <iostream>
#include <functional>
#include "NVector.h"

int main() {
    NVector v(4);
std::cin >> v;          // напр. 1 2 3 4

NVector v2(4);
std::cin >> v2;         // напр. 4 3 2 1

NVector result = v + v2;
std::cout << result << "\n";                  // {5, 5, 5, 5}

result *= 2;
std::cout << "Scaled: " << result << "\n";    // {10, 10, 10, 10}

if (v | v2)
    std::cout << "Перпендикулярни\n";

if (v || v2)
    std::cout << "Успоредни\n";

// operator bool
NVector zero(3);
if (!zero) std::cout << "Нулев вектор\n";
if (v)     std::cout << "v е ненулев\n";

// operator() с ламбда
NVector squares = v([](int x) { return x * x; });
std::cout << "Квадрати: " << squares << "\n";

// operator~
std::cout << "Размер: " << ~v << "\n";

// Оператори за сравнение
int arr1[3] = { 1,2,3 };
int arr2[3] = { 1,2,4 };
int arr3[3] = { 1,2,3 };
NVector va(arr1, 3);
NVector vb(arr2, 3);
NVector vc(arr3, 3);

std::cout << (va == vc ? "равни" : "различни") << "\n";  // равни
std::cout << (va < vb ? "va < vb" : "va >= vb") << "\n";  // va < vb
std::cout << (vb > va ? "vb > va" : "vb <= va") << "\n";  // vb > va

// С operator<=>
auto cmp = va <=> vb;
if (cmp < 0)       std::cout << "va е лексикографски по-малък\n";
else if (cmp == 0) std::cout << "равни\n";
else               std::cout << "va е лексикографски по-голям\n";
}
```

---

## Структура на файловете

```
NVector/
├── NVector.h      ← декларация на класа
├── NVector.cpp    ← дефиниции на методите
└── main.cpp       ← примерна употреба
```

# Задача: MyString

---

## Описание

Да се напише клас `MyString` — wrapper на `char*`, подобно на `std::string`.

Класът управлява динамична памет и трябва да поддържа:
- Голямата четворка
- Основни методи за работа с низове
- Конкатенация
- Сравнение — в две части

---

## Методи

- `getSize()` — дължина без нул терминатора
- `getCapacity()` — капацитет на заделената памет
- `c_str()` — C-style представяне
- `substr(startIndex, len)` — връща подстринг

---

## Оператори

- `operator[]` — с и без `const`
- `operator+=` — конкатенация към текущия обект
- `operator+` — връща нов обект от два низа
- `operator<<` и `operator>>`

---

## Оператори за сравнение

Сравнението е **лексикографско** — чрез `strcmp`.

### Част 1 — ръчна имплементация

Имплементирай `operator==` и `operator<`. Останалите четири изведи от тях.

### Част 2 — `operator<=>`

Замести всичките шест с един оператор. Използвай факта че:

```
strcmp(s1, s2) <=> 0   →   std::strong_ordering
```

---

## Пример за използване

```cpp
MyString a("apple");
MyString b("banana");
MyString c = a + MyString(", ") + b;

std::cout << c << "\n";               // apple, banana
std::cout << c.getSize() << "\n";     // 14
std::cout << c.substr(7, 6) << "\n";  // banana

std::cout << (a < b ? "a < b" : "a >= b") << "\n";  // a < b

auto cmp = a <=> b;
if (cmp < 0) std::cout << "a е по-малък\n";
```

---

## Структура на файловете

```
MyString/
├── MyString.h
├── MyString.cpp
└── main.cpp
```