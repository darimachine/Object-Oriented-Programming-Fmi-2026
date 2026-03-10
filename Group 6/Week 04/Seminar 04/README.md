# Разделна компилация. Композиция, Агрегация, Копиращ конструктор и оператор за присвоявяне (=)

# Разделна Компилация в C++



## 1. Защо разделна компилация?

Представи си, че целият ти проект е в **един файл** `main.cpp`:

```
main.cpp — 3000 реда код
```

### Проблемите:
- Невъзможно е да се ориентираш
- При всяка промяна се **прекомпилира ВСИЧКО** (бавно)
- Двама души не могат да работят по един файл едновременно
- Не можеш да преизползваш класа в друг проект

### Решението — разделна компилация:

```
Student.h      ← „договорът" — какво предлага класът
Student.cpp    ← „изпълнението" — как го прави
main.cpp       ← „клиентът" — ползва класа
```

Всеки `.cpp` файл се компилира **отделно** и после се **свързват** заедно.

---

## 2. Видове файлове — `.h` и `.cpp`

### Header файл (`.h`) — Декларации

Съдържа **КАКВО** съществува, без да казва **КАК** работи.

Тук се пишат:
- Декларации на класове
- Декларации на функции (без тяло)
- Константи и типове

```cpp
// Student.h
int add(int a, int b);   // декларация — само подпис, без тяло
```

### Source файл (`.cpp`) — Дефиниции

Съдържа **КАК** работи кодът.

Тук се пишат:
- Тела на методи и функции
- Логиката на програмата

```cpp
// Student.cpp
#include "Student.h"

int add(int a, int b) {   // дефиниция — тялото е тук
    return a + b;
}
```

### Аналогия 

Представи си меню на ресторант:

| | Ресторант | C++ |
|---|---|---|
| **Менюто** | „Предлагаме пица, паста, салата" | `.h` файл — декларации |
| **Кухнята** | Как точно се готви всяко ястие | `.cpp` файл — дефиниции |
| **Клиентът** | Поръчва от менюто, без да знае рецептата | `main.cpp` — ползва класа |

---

## 3. Include Guard — защита от двойно включване

### Проблемът

Ако два файла включат един и същи header, той ще се „вмъкне" два пъти и ще получиш грешка за дублирани декларации.

```cpp
// main.cpp
#include "Student.h"   // включва Student.h
#include "Course.h"    // Course.h вътрешно също включва Student.h
                       // → Student.h е включен ДВАПЪТИ → ГРЕШКА!
```

### Решение 1: Include Guard (класически)

```cpp
// Student.h
#ifndef STUDENT_H      // Ако STUDENT_H НЕ е дефиниран...
#define STUDENT_H      // ...дефинирай го (и продължи)

// ... целият код на хедъра ...

#endif                 // край на защитата
```

При второ `#include "Student.h"` — `STUDENT_H` вече е дефиниран, затова цялото съдържание се **прескача**.

### Решение 2: `#pragma once` (модерен, по-прост)

```cpp
// Student.h
#pragma once           // Включи този файл само ВЕДНЪЖ

// ... целият код на хедъра ...
```

> **ВАЖНО:** Използваме `#pragma once` — по-кратко и по-ясно. Повечето модерни компилатори го поддържат.

---

## 4. Пълен пример — клас `Student`

Ще разделим клас `Student` на три файла:

```
📁 project/
├── Student.h      ← декларация на класа
├── Student.cpp    ← дефиниции на методите
└── main.cpp       ← основна програма
```

### `Student.h` — само декларации

```cpp
#pragma once
#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;
    double grade;

public:
    // Конструктор — само декларация
    Student(std::string name, int age, double grade);

    // Методи — само декларации (без тела!)
    std::string getName() const;
    int         getAge()  const;
    double      getGrade() const;

    void setGrade(double newGrade);
    void print() const;

};
```

### `Student.cpp` — дефиниции на методите

```cpp
#include "Student.h"   // включваме нашия header

// Конструктор
Student::Student(std::string name, int age, double grade)
    : name(name), age(age), grade(grade) {}
//  ↑
//  Student:: означава "този метод принадлежи на клас Student"

// Getters
std::string Student::getName()  const { return name; }
int         Student::getAge()   const { return age; }
double      Student::getGrade() const { return grade; }

// Setter
void Student::setGrade(double newGrade) {
    if (newGrade >= 2.0 && newGrade <= 6.0)
        grade = newGrade;
    else
        std::cout << "Невалидна оценка!\n";
}

// Принтиране
void Student::print() const {
    std::cout << "Студент: " << name
              << ", Възраст: " << age
              << ", Оценка: " << grade << "\n";
}


```

### `main.cpp` — основна програма

```cpp
#include "Student.h"   // включваме само header-а, не .cpp!
#include <iostream>

int main() {
    Student ivan("Иван", 20, 5.5);
    Student maria("Мария", 21, 6.0);
    Student petar("Петър", 19, 5.5);

    ivan.print();
    maria.print();
    petar.print();

    if (ivan < maria)
        std::cout << ivan.getName() << " има по-ниска оценка от "
                  << maria.getName() << "\n";

    if (ivan == petar)
        std::cout << ivan.getName() << " и " << petar.getName()
                  << " имат еднакви имена и оценки\n";

    ivan.setGrade(5.75);
    std::cout << "\nСлед промяна: ";
    ivan.print();

    return 0;
}
```

### Изход:

```
Студент: Иван, Възраст: 20, Оценка: 5.5
Студент: Мария, Възраст: 21, Оценка: 6
Студент: Петър, Възраст: 19, Оценка: 5.5
Иван има по-ниска оценка от Мария
Иван и Петър имат еднакви имена и оценки

След промяна: Студент: Иван, Възраст: 20, Оценка: 5.75
```

---


## 5. Какво се случва вътрешно?

```
Student.cpp ──► [Компилатор] ──► Student.o  ─┐
                                               ├──► [Линкер] ──► program.exe
main.cpp    ──► [Компилатор] ──► main.o     ─┘
```

### Три фази:

**1. Препроцесор** — обработва `#include`, `#define`, `#pragma once`  
`#include "Student.h"` буквално **копира** съдържанието на `Student.h` в `.cpp` файла

**2. Компилатор** — превежда `.cpp` до машинен код → `.o` (обектен файл)  
`.o` файлът знае за своите функции, но още не знае адресите на чуждите

**3. Линкер** — свързва всички `.o` файлове  
Разрешава „Иванов вика `Student::print()` — ето го адресът в `Student.o`"

---

## 6. Няколко класа в един проект

В реален проект имаме много класове. Структурата изглежда така:

```
📁 project/
├── Student.h
├── Student.cpp
├── Course.h
├── Course.cpp
├── University.h
├── University.cpp
└── main.cpp
```

### `Course.h`

```cpp
#pragma once
#include <string>

class Course {
private:
    std::string title;
    int credits;

public:
    Course(std::string title, int credits);
    std::string getTitle()   const;
    int         getCredits() const;
    void        print()      const;
};
```

### `Course.cpp`

```cpp
#include "Course.h"
#include <iostream>

Course::Course(std::string title, int credits)
    : title(title), credits(credits) {}

std::string Course::getTitle()   const { return title; }
int         Course::getCredits() const { return credits; }

void Course::print() const {
    std::cout << "Курс: " << title
              << " (" << credits << " кредита)\n";
}
```

### `University.h` — ползва и двата класа

```cpp
#pragma once
#include "Student.h"   // включваме хедъра на Student
#include "Course.h"    // включваме хедъра на Course
#include <vector>

class University {
private:
    std::string name;
    std::vector<Student>  students;   // композиция
    std::vector<Course*>  courses;    // агрегация

public:
    University(std::string name);

    void addStudent(const Student& s);
    void addCourse(Course* c);
    void printAll() const;
};
```

### `main.cpp`

```cpp
#include "University.h"   // само това е нужно!
                          // University.h вече включва Student.h и Course.h

int main() {
    University uni("Технически Университет");

    uni.addStudent(Student("Иван",  20, 5.5));
    uni.addStudent(Student("Мария", 21, 6.0));

    Course cpp("C++ Програмиране", 5);
    Course algo("Алгоритми", 6);

    uni.addCourse(&cpp);
    uni.addCourse(&algo);

    uni.printAll();

    return 0;
}
```



---

## 7. Чести грешки

### Грешка 1: `#include "Student.cpp"` вместо `"Student.h"`

```cpp
// main.cpp
#include "Student.cpp"   // ❌ ГРЕШКА!
```

Включването на `.cpp` файл директно води до **дублирани дефиниции** при линкване. Винаги включвай само `.h` файлове.

---

### Грешка 2: Дефиниция на метод в `.h` файла (без `inline`)

```cpp
// Student.h
void Student::print() const {
    std::cout << name;   // ❌ Ако два .cpp файла включат Student.h,
}                        //    функцията ще се дефинира ДВАПЪТИ → грешка
```

**Решение:** Дефинициите на методи трябва да са в `.cpp` файла. В `.h` оставяй само декларации.

---

### Грешка 3: Забравен include guard

```cpp
// Student.h — без #pragma once или #ifndef
class Student { ... };

// Ако се включи два пъти:
// error: redefinition of 'class Student'
```

**Решение:** Слагай `#pragma once` като първи ред на всеки `.h` файл.

---

### Грешка 4: Липсващ `Student::` пред метода в `.cpp`

```cpp
// Student.cpp
void print() const {    // ❌ Това е свободна функция, НЕ метод на Student!
    std::cout << name;  //    name не е достъпен → грешка
}

// Правилно:
void Student::print() const {   // ✅
    std::cout << name;
}
```

---

## 8. Обобщение

### Структура на файловете

```
Клас X
├── X.h    → #pragma once
│           → #include на нужните хедъри
│           → декларация на класа (полета + методи БЕЗ тела)
│
└── X.cpp  → #include "X.h"
             → дефиниции на методите с X::
             → тук е логиката
```

### Правила за запомняне

| Правило | Обяснение |
|---|---|
| `.h` = Декларации | Само подписи, без тела |
| `.cpp` = Дефиниции | Тук е кодът |
| `#include "X.h"` | Включвай само хедъри |
| `#pragma once` | Слагай го в началото на всеки `.h` |
| `X::метод()` | Задължително в `.cpp` файла |
| Компилация | `g++ A.cpp B.cpp main.cpp -o program` |

### Визуален поток

```
[Student.h]  ←── включва се от ──→  [Student.cpp]
     ↑                                    ↓
     └──── включва се от ──────  [main.cpp]
                                      ↓
                                 [Компилатор]
                                      ↓
                          Student.o + main.o
                                      ↓
                                 [Линкер]
                                      ↓
                                  program ✅
```

> **Правило:**
> - В `.h` файла — само **КАКВО** (декларации)
> - В `.cpp` файла — само **КАК** (дефиниции)
> - В `main.cpp` — включвай само `.h` файлове, **никога** `.cpp`

# Композиция и агрегация

### Композиция

При **композиция** един обект съдържа друг обект като своя част ("притежава" го) и обикновено контролира неговия жизнен цикъл (`owns-a`).

```cpp
class Engine {
};

class Car {
private:
    Engine engine;
};
```

Тук `engine` е част от `Car`. Когато се създаде `Car`, се създава и `engine`. Когато `Car` се разруши, `engine` също се разрушава.

### Агрегация

При **агрегация** един обект пази връзка към друг, но **не го притежава** и не управлява неговия жизнен цикъл, а само го "използва" (`uses-a`).

```cpp
class Engine {
};

class Car {
private:
    Engine& engine;

public:
    Car(Engine& engine) : engine(engine) {
    }
};
```

Тук `Car` използва вече съществуващ `Engine`, но не го създава и не го унищожава.

Същата идея може да се реализира и с указател:

```cpp
class Car {
private:
    Engine* engine;

public:
    Car(Engine* engine) : engine(engine) {
    }
};
```

### Основната разлика

- При **композиция** вътрешният обект е част от външния и обикновено живее точно колкото него. Външният обект контролира жизнения цикъл на вътрешния.
- При **агрегация** външният обект само сочи или реферира към друг обект, който може да живее независимо.

---


## Копиращ конструктор и оператор =
Заедно с конструктора по подразбиране и деструктора във всеки клас се дефинират и следните член-функции:
 - **Копиращ конструктор** - конструктор, който приема обект от същия клас и създава новият обект като негово копие.
 - **Оператор=** - функция/оператор, който приема  обект от същия клас и променя данните на съществуващ обект от същия клас (обектът от който извикваме функцията).

**При липсата на дефиниран/и копиращ конструктор и/или оператор=, компилаторът автоматично създава такива по подразбиране.**
**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

```c++
#include <iostream>

struct Example {
    Example() {
        std::cout << "Example()" << std::endl;
    }

    Example(const Example& other) {
        std::cout << "Copy constructor of Example" << std::endl;
    }

    Example& operator=(const Example& other) {
        std::cout << "operator= of Example" << std::endl;
	    return *this;
    }

    ~Example() {
        std::cout << "~Example()" << std::endl;
    }
};

void f(Example object) {
    //do Stuff
}

void g(Example& object) {
    //do Stuff
}

int main() {
    Example e;      //Default constructor;

    Example e2(e);  // Copy constructor
    Example e3(e2); // Copy constructor	
    e2 = e3;     // operator=
    e3 = e;      // operator=

    Example newExample = e; //Copy constructor !!!!!!!

    f(e);   // Copy constructor	
    g(e);   // nothing. We are passing it as a reference. We are not copying it!

    Example* ptr = new Example();  // Default constructor // we create a new object in the dynamic memory. The destructor must be invoked explicitly  (with delete)

    delete ptr; // Destructor	

} //Destructor Destructor Destructor Destructor
```

### RVO (Return Value Optimization)
#### Какво е това?

Компилаторът **не създава временен обект**, когато връщаш обект директно от return.

Вместо:
- създай обект
- копирай го
- унищожи временния

Компилаторът директно го създава в мястото, където ще бъде използван.

#### Пример за RVO
```c++
#include <iostream>

class Test {
public:
    Test() { std::cout << "Constructor\n"; }
    Test(const Test&) { std::cout << "Copy Constructor\n"; }
};

Test createObject() {
    return Test();   // <-- временен обект
}

int main() {
    Test t = createObject();
}
```
#### Какво става?

**Без RVO:**
```
Constructor
Copy Constructor
```
**С RVO (в модерните компилатори):**
```
Constructor
```
**Няма копиране.**
**Обектът се създава директно в t.**

### NRVO (Named Return Value Optimization)
#### Какво е разликата?

Тук връщаме **именувана променлива**, не временен обект.

#### Пример за NRVO
```c++
#include <iostream>

class Test {
public:
    Test() { std::cout << "Constructor\n"; }
    Test(const Test&) { std::cout << "Copy Constructor\n"; }
};

Test createObject() {
    Test obj;   // именуван обект
    return obj; // <-- NRVO
}

int main() {
    Test t = createObject();
}
```
#### Какво става?

**Без NRVO:**
```
Constructor
Copy Constructor
```
**С NRVO:**
```
Constructor
```
**Отново няма копиране.**
**Компилаторът директно създава obj в паметта на t.**

### Кога NRVO може да НЕ се приложи?

**Ако имаш повече от един return:**
```C++
Test createObject(bool flag) {
    Test obj1;
    Test obj2;

    if (flag)
        return obj1;
    else
        return obj2;
}
```
**Тук компилаторът често не може да приложи NRVO, защото има два различни обекта.**

**Друг пример:** <br />
 В рамките на курса ще възприемаме, че няма да се извикват нито излишни copy constructor-и(защото връщаме по копие), нито destructor-и(в scope на функцията обектът умира, но преди това би трябвало да се копира, за да се върне по копие) в scope-a на функцията, защото се случва [RVO - return value optimization](https://en.cppreference.com/w/cpp/language/copy_elision), което ни спестява излишни копирания, тоест единствено ще се извикат constructor и destructor на съответние места индикирани с коментари.

```c++
struct Example {
	Example() {
		std::cout << "Example()" << std::endl;
	}
	
	Example(const Example& other) {
		std::cout << "Copy constructor of Example" << std::endl;
	}
	
	Example& operator=(const Example& other) {
		std::cout << "operator=" << std::endl;
		return *this;
	}
	
	~Example() {
		std::cout << "~Example()" << std::endl;
	}
};

Example create() {
	return Example(); // default constructor 
}

int main() {
	Example e = create(); // Example()
} // destructor
```
