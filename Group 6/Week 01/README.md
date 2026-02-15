# 01. Увод в ООП. Структури. Вложени структури. Функции със структури. Представяне на обекти в паметта. Енумерации, обединения, пространства от имена.

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

   return b;
}
```

#### **Извикване на функции, от функции приемащи обекти:**

| Извикана функция / Викаща функция | f1(A obj) | f2(const A obj) | f3(A& ref) | f4(const A& ref) | f5(A\* ptr) | f6(const A\* ptr) |
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

❗ Ако искате да прочете повече детайли за подравняването, може да го направите [тук](https://github.com/IvanMakaveev/FMI-Extra/blob/main/Object%20Oriented%20Programming/StructuresPadding/README.md)

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

- enum classes
  - енумераторите са локални за enuma и техните стойности не се преобразуват имплицитно към други типове (another enum or int).
- Plain enums
  - енумераторите са в същия scope като enuma и техните стойности се преобразуват имплицитно към integers и други типове (включително да други enum-и ).

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

Пространствата от имена предоставят метод за предотвратяване на конфликти с имена. <br />
Символите, декларирани вътре в namespace block, се поставят в наименуван scope, който не позволява да бъдат сбъркани със символи с идентични имена в други диапазони. <br />

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

_Credits: [Georgi Terziev](https://github.com/GeorgiTerziev02/)_
