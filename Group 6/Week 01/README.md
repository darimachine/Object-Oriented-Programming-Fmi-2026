# 01. Увод в ООП. Енумерации, пространства от имена. Структури и класове

## **Какво означава Обектно-ориентирано програмиране?**

**Програмна парадигма** - представлява фундаменталния стил на програмиране, който се дефинира с редица от принципи, концепции и техники за това как да имплементираме нашите програми.

**Обектно-ориентирано програмиране** е програмна парадигма, при която една програмна система се моделира като набор от обекти, които взаимодействат помежду си, за разлика от традиционното виждане, в което една програма е списък от инструкции, които компютърът изпълнява. Всеки обект е способен да получава съобщения, обработва данни и праща съобщения на други обекти.

### **Принципи на ООП:**

(Интерфейс в програмирането (неформално) - всичко, което един обект предоставя на външния свят и може да бъде използвано)

- **Абстракция**
  - Скриване на имплементацията и ненужните детайли от потребителя на обекта
  - Потребителя на обекта работи с неговия интерфейс без да знае как точно са имплементирани неговите атрибути
- **Капсулация**
  - "скриване на информация"
  - Прави невъзможно за потребителите на даден обект да променят неговото вътрешно състояние по неочакван начин
- **Наследяване**
  - позволява да бъдат дефинирани и създавани обекти, които са специализирани варианти на вече съществуващи обекти.
  - класът наследник взема всички свойства и методи на класа-родител
- **Полиморфизъм**
  - представлява свойството на обектите от един и същи тип да имат един и същи интерфейс, но с различна реализация на този интерфейс.

## [**Структури**](https://en.cppreference.com/w/c/language/struct)

Структурите в C++ се използват за групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип(int, int[], bool и т.н.) и с различна големина.

```c++
struct Box {
	double height;
	double width;
	double length;
	// double height, width, length; is also possible
}
```

### **Деклариране на обекти от новия тип**

```c++
Box b; // default values to height and width and length

Box b2 = {3, 4, 3.4}; // height = 3, width = 3, length = 3.4;

Box b3;
b3.height = 13;
b3.width = 14;
b3.length = 20;
```

#### **Създаване на динамични обекти**

```c++
#include <iostream>

struct Box {
	double height, width, length;
};

double calculcateVolume(const Box& b) {
   return b.height * b.width * b.length;
}

int main() {
	Box* boxPtr = new Box();

	// different types of assigning a value to a property when you have a pointer
	(*boxPtr).height = 3;
	(*boxPtr).width = 1;
	boxPtr->length = 4;

	std::cout << calculcateVolume(*boxPtr) << std::endl;

	delete boxPtr; // allocated memory should always be deleted!
}
```

#### **Влагане на обекти**

```c++
struct Box {
	double height, width, length;
};

struct Warehouse {
	char name[1024];
	Box b1, b2;
};

int main() {
	Warehouse w = { "Ekont", { 1, 2, 3 }, { 4, 5, 3 } };

	std::cout << w.name;
}
```

### **Как да имаме структура, която съдържа член от същия тип в C++?**

В C++ **не можем директно** да имаме структура, която съдържа член от същия тип, защото това ще доведе до **безкрайна рекурсия** при заделянето на памет.

Например, ако се опитаме да направим следното:

```cpp
struct Node {
    int value;
    Node next;  // ❌ ГРЕШКА! Безкрайна рекурсия при заделяне на памет
};
```

⚠️ Това не работи, защото компилаторът трябва да знае точния размер на `Node`, но всеки `Node` ще съдържа друг `Node`, което води до безкрайно влагане.

За да избегнем този проблем, можем да използваме различни техники:

### **1. Използване на указател**

Това е най-често срещаният начин да се реферира към друг обект от същия тип, без да се предизвиква рекурсия.

```cpp
#include <iostream>

struct Node {
    int value;
    Node* next = nullptr;  // Указател към следващия елемент, със стойност nullptr по подразбиране
};

int main() {
    Node first = { 10 };
    Node second = { 20 };

    first.next = &second; // Свързваме first със second

    std::cout << "First: " << first.value << std::endl; // 10
    std::cout << "Second: " << first.next->value << std::endl; // 20
}

```

✅ **Предимства**:

- Компилаторът знае точния размер на `Node`, защото `next` е просто указател (адрес), а не друг `Node`.
- Позволява динамични структури от данни, като свързани списъци и дървета.

⚠️ **Недостатъци**:

Може да изисква ръчно управление на паметта, ако се използва динамично заделяне (`new` и `delete`).

### **2. Използване на референция**

Референциите също могат да бъдат използвани, но с някои ограничения:

```cpp
#include <iostream>

struct Node {
    int value;
    Node& next;  // Референция към друг Node (задължително трябва да се инициализира)

    Node(int val, Node& n) : value(val), next(n) {} // Няма default конструктор (не сме го учили още :D)
};

int main() {
    Node last = { 20, last }; // Dummy референция (не е много полезно)
    Node first = { 10, last };

    std::cout << "First: " << first.value << std::endl; // 10
    std::cout << "Second: " << first.next.value << std::endl; // 20
}
```
⚠️ **Ограничения**:

- Референцията трябва да се инициализира при създаването, което прави този метод неудобен за динамични структури.
- Не може да се сменя, защото референциите са **неизменяеми** след инициализация.
- Няма default-ен конструктор, защото референциите **задължително** трябва да сочат към нещо при създаването.

✅ **Кога върши работа?**

- Когато винаги ще има наличен `Node`, към който да се сочи.

---

#### **Масиви от обекти**

*При масиви от обекти, обектите се намират плътно един до друг в паметта.*

```c++
struct Box {
	double height, width, length;
};

int main() {
	Box arr1[30]; // 30 boxes in the stack
	Box* arr2 = new Box[20] // 20 boxes in dynamic memory and a pointer in the stack

	std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

	delete[] arr2;
}
````

#### **Подаване във функции**

Ако няма да променяме обекта го подаваме по **константна референция**!

```c++
double calculcateVolume(const Box& b) {
   return b.height * b.width * b.length;
}
```

Може и само по **референция**, но тогава може да се правят промени върху подадения аргумент.

```c++
void readBox(Box& b) {
   cin >> b.height >> b.width >> b.length;
}
```

Може и да го подаваме по **копие**. Тогава промените се отразяват само върху копието на обекта. Подаденият като аргумент обект остава непроменен!

```c++
Box revertBox(Box b) {
   int temp = b.height;
   b.height = b.width;
   b.width = temp;

   //...

   return b;
}
```

---

### **Извикване на функции, от функции приемащи обекти:**

Таблицата показва кои функции могат да бъдат извикани (по редове) от функция с даден тип параметър (по колони), в зависимост от това дали аргументът е подаден като копие/стойност, (const) референция или (const) указател.

По-ясно може да разберете таблицата от **[този снипет](https://github.com/StefanShivarov/oop-course-fmi-2026/tree/main/Seminar%2001/Examples/Struct/structsAsFunctionArguments.cpp)**.

| Извикана функция (редове) / Викаща функция (колони) | f1(A obj) | f2(const A obj) | f3(A& ref) | f4(const A& ref) | f5(A\* ptr) | f6(const A\* ptr) |
| --------------------------------- | --------- | --------------- | ---------- | ---------------- | ----------- | ----------------- |
| **f1(A obj)**             | ✅        | ✅              | ✅         | ✅               | ✅          | ✅                |
| **f2(const A obj))**             | ✅        | ✅              | ✅         | ✅               | ✅          | ✅                |
| **f3(A& ref))**             | ✅        | ❌              | ✅         | ❌               | ✅          | ❌                |
| **f4(const A& ref)**             | ✅        | ✅              | ✅         | ✅               | ✅          | ✅                |
| **f5(A\* ptr)**             | ✅        | ❌              | ✅         | ❌               | ✅          | ❌                |
| **f6(const A\* ptr))**             | ✅        | ✅              | ✅         | ✅               | ✅          | ✅                |

✅ - възможно извикване, ❌ - грешка при компилация

## **Представяне в паметта и подравняване.**

- Паметта е байт-адресируема, т.е. може да достъпва всеки байт индивидуално;
- Колко памет може да прочете процесорът за един memory read cycle-a зависи от архектурата му (x32 - 4 bytes, x64 - 8 bytes);
- В паметта променливите са разположени в същия ред, в който са декларирани в структурата;
- Подравняването на една структура става по **големината на най-голямата член-данна (даже и в случая на вложена структура)** на структурата (с цел минимизация на подравняването и броя read cycle-и за прочитане на най-голямата член-данна да бъде оптимален);
- За да бъде минимална паметта, която ползва една структура, трябва да подредим нейните член-данни в нарастващ или намаляващ ред по големина на променливата
- sizeof на празна структура (без член-данни) е равна на 1

❗ Свалете [**"Struct Layout"**](https://marketplace.visualstudio.com/items?itemName=RamonViladomat.StructLayout) extension-a на Visual studio, за да можете да видите визуализация на това как са подредени член-данните и тяхното подравняване в паметта за вашите структури.

```c++
struct Example1 {
    bool b;         // 1 byte
    int c;	    // 4 bytes
} ex1;

struct Example2 {
    short int s;    //2 bytes
    char c;         //1 byte
    int i;          //4 bytes
} ex2;

// How can the following struct use less memory?
struct Example3 {
    char c;         //1 byte
    double d;       //8 bytes
    int s;          //4 bytes
} ex3;

// the padding is equal to the biggest variable, if it is an int => 4 bytes
std::cout << sizeof(ex1) << std::endl; // 8
std::cout << sizeof(ex2) << std::endl; // 8
std::cout << sizeof(ex3) << std::endl; // 24
```

_Представяне на Example1 в паметта: `[ b ][ ][ ][ ][ c ][ c ][ c ][ c ]`_

## Little-endian and Big-endian

Съществуват следните два начина за запазване на байтовете на типове данни, които имат размер по-голям от 1 байт:

- **Little-endian** - Най-старшият байт е на последна позиция, най-младшият е на първа
- **Big-endian** - Най-старшият байт е на първа позиция, най-младшият е на последна

## [**Обединения (unions)**](https://www.geeksforgeeks.org/cpp-unions/)

_(за по-любознателните)_

Обединението е специален вид структура, чиито член-данни(дори и от различен тип) споделят една и съща памет. <br />
Едно обединение заема памет, колкото е големината на най-голямата му променлива в обединението. <br />
Във всеки един момент обаче може да се ползва само една променлива от състава на обединението.<br />

```c++
union Example {
	int a;
	char b;
} var;

int main() {
	var.a = 65;
	std::cout << var.a << " " << var.b; // 65 A
}
```

```c++
union Example {
	int a;
	char b;
	double c;
	float d;
};

int main() {
	std::cout << sizeof(union Example); //8
}
```

```c++
union Example {
	int a;
	char b;
} var;

int main() {
	var.a = 90;
	union Example *p = &var;
	std::cout << p->a << " " << p->b; //90 Z
}
```

![Union](https://miro.medium.com/v2/resize:fit:1200/1*edHeoRBfPgxcXHp2zIkP-A.jpeg)

## [Енумерации (Enums)](https://en.cppreference.com/w/cpp/language/enum)

Eнумерацията е отделен тип, чиято стойност е ограничена до диапазон от стойности, който може да включва няколко изрично посочени константи(енумератори). Стойностите на константите са стойности от интегрален тип, известен като основен тип на eнумерацията Eнумерацията има същия размер, представяне на стойност и изисквания за подравняване като неговия основен тип. Освен това всяка стойност на енумерацията има същото представяне като съответната стойност на основния тип. <br />

```c++
enum <name> {
	<element>, //0
	<element>, //1
	.
	.
	.
};

enum IceCream1 {
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};

enum IceCream2 : char {
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};

int main() {
	std::cout << sizeof(IceCream1) << std::endl; // 4
	std::cout << sizeof(IceCream2) << std::endl; // 1
}

```

### Unscoped enumеrations (plain enums) vs Scoped enumеrations (enum class | struct)

```c++
enum class Color { red, green, blue }; // enum class
enum Animal { dog, cat, bird, human }; // plain enum
```

- **Еnum classes**
  
   Енумераторите са локални за enum-a и техните стойности не се преобразуват имплицитно към други типове (друг enum или int).
- **Plain enums**
  
  Енумераторите са в същия scope като enuma и техните стойности се преобразуват имплицитно към integers и други типове (включително други enum-и ).

```c++
enum Color { red, green, blue };                    // plain enum
enum Card { red_card, green_card, yellow_card };    // another plain enum
enum class Animal { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

void fun() {
    // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;    // no problem

    if (color == Card::red_card) // no problem (bad)
        cout << "bad" << endl;

    if (card == Color::green)   // no problem (bad)
        cout << "bad" << endl;

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    int num2 = a;   // error
    if (m == a)     // error (good)
        cout << "bad" << endl;

    if (a == Mammal::deer) // error (good)
        cout << "bad" << endl;
}
```

Извод: Винаги използвайте enum (class | struct), за да избегнете имплицитното преобразуване и двусмислици.

## [Namespaces](https://en.cppreference.com/w/cpp/language/namespace)

Пространствата от имена предоставят метод за __предотвратяване на конфликти с имена__. <br />
Символите, декларирани вътре в namespace block, се поставят в наименуван scope, който не позволява да бъдат сбъркани със символи с идентични имена в други диапазони. <br />

---

**Пример за това кога бихме използвали namespace:**

Имаме две функции, които имат еднаква декларация, но се използват за различни неща (имат различна имплементация):

```cpp
#include <iostream>

namespace ip {
    unsigned parse(const char* s) {
        int result = 0;
        // parsing ip address to a 32-bit number
        // ...
        return result;
    }
}

namespace timeutil {
    int parse(const char* s) {
        // Demo: "HH:MM" -> минути от 00:00
        // Пак опростено като идея.
        int hh = (s[0]-'0')*10 + (s[1]-'0');
        int mm = (s[3]-'0')*10 + (s[4]-'0');
        return hh * 60 + mm;
    }
}

int main() {
    const char* t = "10:30";
    const char* addr = "127.0.0.1";

    int minutes = timeutil::parse(t);
    unsigned ipValue = ip::parse(addr);

    std::cout << minutes << "\n";
    std::cout << ipValue << "\n";
}

```

Ако нямаме namespace-ове, компилаторът ще се чуди коя функция parse да извика.

---

Друг пример за използване на namespace-ове:
```cpp
namespace config {
    const int MAX_STUDENTS = 30;
    const int NAME_LEN = 32;
}
```

Тук групираме константи, за да не замърсяваме глобалния scope.

---

Свойства на namespace-овете:

```c++
namespace A {
    int i;
}

namespace B {
    int i;
    int j;

    namespace C {
        namespace D {
            using namespace A; // all names from A injected into global namespace

            int j;
            int k;
            int a = i;         // i is B::i, because A::i is hidden by B::i
        }

        using namespace D; // names from D are injected into C
                           // names from A are injected into global namespace

        int k = 89; // OK to declare name identical to one introduced by a using
        int l = k;  // ambiguous: C::k or D::k
        int m = i;  // ok: B::i hides A::i
        int n = j;  // ok: D::j hides B::j
    }
}

namespace Q {
    namespace V   	// V is a member of Q, and is fully defined within Q
    { 			 	// namespace Q::V // C++17 alternative to the lines above
        class C		// C is a member of V and is fully defined within V
	{
		void m(); // C::m is only declared
	};
        void f(); // f is a member of V, but is only declared here
    }

    void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
    {}             // enclosing namespaces are the global namespace, Q, and Q::V
}
```

---

## **Процедурен стил vs ООП**

### **Процедурен стил (procedural programming)**
При процедурния стил програмата често изглежда като:
- **данни** (структури/масиви/глобални променливи)
- **функции**, които работят върху тези данни

Обикновено логиката е разпиляна между много функции, които:
- трябва да знаят **вътрешните детайли** на данните
- лесно започват да си “пречат” (особено при глобално състояние)
- става трудно да се гарантира, че данните са винаги валидни

Примерна ситуация: имаме `BankAccount`, пазим го като структура и го променяме с функции:

```cpp
struct BankAccount {
    char owner[32];
    double balance;
};

void deposit(BankAccount& acc, double amount) {
    acc.balance += amount; // няма проверки
}

void withdraw(BankAccount& acc, double amount) {
    acc.balance -= amount; // може да стане отрицателен баланс
}
```

Тук **всеки**, който има достъп до `BankAccount`, може да направи:
```cpp
acc.balance = -1000000; // "счупваме" състоянието
```
_Това е пряко свързано с капсулация и модификаторите за достъп, което ще покрием следващата седмица._

---

### **ООП (Оbject-oriented programming)**
При ООП целта е да моделираме системата като **обекти**, които:
- пазят своето **състояние** (данни);
- предоставят операции чрез **интерфейс** (методи);
- контролират валидността на своето състояние

```cpp
class BankAccount {
private:
    char owner[32];
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};
```

### **Какво подобрява ООП (в сравнение с процедурния стил)?**
- **По-ясна структура на кода**: групираш логиката около конкретен обект/концепция.
- **По-малко “случайни” зависимости**: кодът работи през интерфейс, а не през вътрешни полета.
- **По-лесна поддръжка**: промяна в имплементация не чупи всички, които ползват обекта (ако интерфейсът е стабилен).
- **По-лесно разширяване**: могат да се добавят нови поведения / типове без да се преправя половината проект.
- **По-лесно налагане на правила**: обектът може да пази валидността си локално.
---

## **Класове и структури в C++ — какво са и защо ги ползваме**

В процедурното програмиране често имаме “данни” отделно и “функции” отделно.  
В C++ структурите и класовете ни позволяват да съберем **свързани данни** в една обща единица (нов тип), която описва някаква концепция от задачата.

### **`struct` — “пакет” от свързани данни**
`struct` най-често използваме, когато:
- имаме няколко стойности, които логически вървят заедно (имат някаква логическа връзка, причина да са обвити в структура)
- искаме да ги подаваме като една променлива

_Пример: точка в равнината_
```cpp
struct Point {
    int x;
    int y;
};
```

Сега вместо да носим навсякъде `x` и `y` отделно, просто работим с `Point`:

```cpp
void printPoint(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")\n";
}
```

### **`class`
`class` в C++ изпълнява почти същата роля като `struct` (може да има полета и функции), но обикновено се използва, когато искаме типът да има:
- **по-ясен публичен интерфейс** (какво може да се прави с обекта);
- **вътрешна логика**, която поддържа обекта в “коректно състояние”;
- (по-късно) контрол кой има достъп до кои данни.

_Пример: брояч_

```cpp
class Counter {
public:
    void increment() { value++; }
    int get() const { return value; }

private:
    int value = 0;
};
```

Тук външният код работи през функции(интерфейс), а не чрез “каквото му хрумне” върху данните.  
➡️ Това е **първа стъпка към идеята**, че обектът предоставя операции, а детайлите “как е реализиран отвътре” и ненужните за потребителя данни могат да се скрият. _(по - подробно ще го разгледаме при капсулацията.)_

Хубаво е да се запомни следната **конвенция**:
- `struct` → “обект като запис/пакет от данни”
- `class` → “обект с по-комплексно поведение (вътрешна логика, данни които не трябва да се достъпват от потребителя, и вътрешна валидация) + по-ясен интерфейс”

### **Разлика между `struct` и `class`**

- при `struct` членовете са **public по подразбиране**
- при `class` членовете са **private по подразбиране**

```cpp
struct A {
    int x; // public по подразбиране
};

class B {
    int x; // private по подразбиране
};
```

```cpp
struct Rectangle {
    int a;
    int b;
};

int area(const Rectangle& r) {
    return r.a * r.b;
}
```

```cpp
class Rectangle {
public:
    void setSides(int a, int b) {
        // тук бихме могли да правим проверки (по-късно)
        sideA = a;
        sideB = b;
    }

    int area() const {
        return sideA * sideB;
    }

private:
    int sideA = 0;
    int sideB = 0;
};
```
---

## **Интуиция: как да представяме информацията като обекти и как да “мислим в обекти”**

### **1) Какви “неща” съществуват в задачата?**
Прочети условието и си задай:  
**Кои са основните участници / елементи / единици?**  
Това са кандидатите за типове (`struct`/`class`).

Практичен трик: търси **съществителни** в текста. Примери:
- “Точка”, “Отсечка”, “Триъгълник”
- “Студент”, “Група”
- “Книга”, “Библиотека”
- “Продукт”, “Поръчка”

### **2) Каква информация описва всяко “нещо”?**
За всеки клас запиши:
- какви данни го характеризират (полета);
- какъв тип са те (в рамките на това, което знаем: `int`, `double`, `char[]`, други структури).

Пример: студент  
- име → `char name[32]`  
- факултетен номер → `int fn`  
- курс → `int year`

```cpp
struct Student {
    char name[32];
    int fn;
    int year;
};
```

### **3) Какво може да се прави с обектите от този клас? (операции)**
Това са кандидатите за функции/методи:
- прочитане от вход;
- отпечатване;
- пресмятане на стойност (лице, обем, цена);
- промяна (преместване на точка, увеличаване на брояч).

### **4) Граници и отговорности: кой за какво отговаря?**
- ако дадена функция работи “естествено” върху **точно един обект** → много вероятно е да е свързана с него;
- ако функцията изисква **две или повече** различни неща → често е по-удачно да е отделна.

Пример:
- `area(rect)` → очевидно е операция на правоъгълника  
- `distance(p1, p2)` → логически е свързана с две точки (и е нормално да е отделна функция)

```cpp
struct Point { int x, y; };

int dist2(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy; // квадрат на разстоянието (без sqrt)
}
```

### **5) Мисли за “колекция от обекти”, не за “много отделни променливи”**
В задачите почти винаги има “много еднакви неща”:
- много студенти
- много точки
- много кутии

Вместо:
```cpp
Student s1, s2, s3, s4, s5;
```

Правим:
```cpp
Student students[30];
```

Или динамично:
```cpp
Student* students = new Student[n];
// ...
delete[] students;
```
---

## Масив от обекти и динамични обекти

```cpp
#include <iostream>

struct Student {
    char name[32];
    int fn;
    int year;
};

void printStudent(const Student& s) {
    std::cout << s.name << " (" << s.fn << "), year " << s.year << "\n";
}

int main() {
    Student group[3] = {
        { "Ivan", 12345, 2 },
        { "Maria", 23456, 1 },
        { "Georgi", 34567, 3 }
    };

    for (int i = 0; i < 3; i++) {
        printStudent(group[i]);
    }
}
```

Динамичен масив от обекти:

```cpp
#include <iostream>

struct Box {
    double h, w, l;
};

double volume(const Box& b) {
    return b.h * b.w * b.l;
}

int main() {
    int n;
    std::cin >> n;

    Box* boxes = new Box[n];

    for (int i = 0; i < n; i++) {
        std::cin >> boxes[i].h >> boxes[i].w >> boxes[i].l;
    }

    for (int i = 0; i < n; i++) {
        std::cout << volume(boxes[i]) << "\n";
    }

    delete[] boxes;
}
```

---

### Правете разлика между “обект” и "клас"
- **Тип/клас**: `Student`
- **Обект**: `Student stefo;` (конкретна променлива/**инстанция** от този тип)

```cpp
Student stefo = { "Ivan", 12345, 2 };
Student niki = { "Niki", 23456, 1 };
```

Това са **два различни обекта** (две различни инстанции), от един и същи тип (клас).
