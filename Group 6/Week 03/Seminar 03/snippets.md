
### **Задача 1.** Ще се компилира ли следният код? Ако не, защо?
```c++
#include <iostream>

class A {
public:
    void f() const
    {
        g();
    }
    void g() const{}
};
```

### **Задача 2** Ще се компилира ли следният код? Ако не, защо?
```c++
#include <iostream>

class A {
public:
    void t() {}
    void foo() const
    {
        t();
    }
};
```

### **Задача 3** Кои от следните твърдения са верни (отбележете с **да** или **не** за всяко едно):
 1. Можем да викаме в конструктор друг конструктор на същия клас;
 2. Можем да имаме няколко деструктора и няколко конструктора;
 3. Можем да имаме няколко деструктора, но само един конструктор;
 4. Можем да имаме няколко конструктора, но само един деструктор;
 5. Можем да имаме само един конструктор и само един деструктор;
 6. Задължително трябва да имаме конструктор и деструктор в класа;
 7. Ако си напишем конструктор с параметри, то дефолтния конструктор се запазва;
 8. Ако си напишем конструктор с параметри, то за да ползваме дефолтния конструктор трябва да напишем и него.
 9. Ако си напишем констуктор с параметри, то тогава можем да създаваме масив от дадения клас.


### **Задача 4** Посочете грешките в кода:
```c++
#include <iostream>
class Point {
    int x;
    int y;

    Point(int x, int y) {
        x = x;
        y = y;
    }
};
int main()
{
    Point p1;
}
```
---

### **Задача 5**
Какво ще се изведе на конзолата след изпълнението на следния код?

```cpp
#include <iostream>

const int MAX_NAME_SIZE = 64;

class Person {
    int age;
    char name[MAX_NAME_SIZE + 1];
};

int main() {
    Person p;
    std::cout << p.age << std::endl;
}
```
**Възможни отговори:**
- а) 0
- б) undefined
- в) няма да се компилира

---

### **Задача 6**
Какво ще се изведе на конзолата след изпълнението на следния код?

```cpp
#include <iostream>

const int MAX_NAME_SIZE = 64;

class Person {
    int age;
    char name[MAX_NAME_SIZE + 1];
public:
    int getAge() const {
        return age;
    }
};

int main() {
    Person p;
    std::cout << p.getAge() << std::endl;
}
```
**Възможни отговори:**
- а) 0
- б) undefined
- в) няма да се компилира

---

### **Задача 7**
Какво ще се изведе на конзолата?

```cpp
#include <iostream>
#include <cstring>

const int MAX_NAME_SIZE = 64;

class Person {
    int age;
    char name[MAX_NAME_SIZE + 1];
public:
    Person(const char* name, int age) {
        strcpy(this->name, name);
        this->age = age;
    }
    int getAge() const {
        return age;
    }
};

int main() {
    Person p;
    std::cout << p.getAge() << std::endl;
}
```
**Възможни отговори:**
- а) 0
- б) undefined
- в) няма да се компилира



---
### **Задача 8**
**Какво ще отпечата кода? Има ли грешки в него?**

```c++
#include <iostream>

struct A {
	char* arr;

	A() {
    		arr = new char[10];
    		std::cout << "A()" << std::endl;
	}

	~A() {
    		std::cout << "~A()" << std::endl;
	}
};

int main() {
	A arr[2];
	A* ptr = new A[3];
}
```
### **Задача 9**
**Какво ще се отпечата?**

```c++
#include <iostream>

struct C {
	double d;
	C() {
    		std::cout << "C()" << std::endl;
	}
	~C() {
    		std::cout << "~C()" << std::endl;
	}
};

struct B {
	int b;
	char c;
	B() {
    		std::cout << "B()" << std::endl;
	}
	~B() {
    		std::cout << "~B()" << std::endl;
	}
};

struct A {
	B b;
	C c;
	A()  {
    		std::cout << "A()" << std::endl;
	}
	~A() {
    		std::cout << "~A()" << std::endl;
	}
};

int main() {
	A arr[2];
	A* ptr = new A[1];

	delete[] ptr;
}
```

### **Задача 10**
Какво ще се изведе на конзолата?

```cpp
#include <iostream>

class A {
    int a;
public:
    A(int a) {
        this->a = a;
    }
    void setValue(int number){
        this->a = number;
    }
};

class B {
    double b;
    A a;
public:
    B(double b, int number) {
        this->b = b;
        a.setValue(number);
    }
    double getDoubleValue() const {
        return b;
    }
};

int main() {
    B b(8.5, 4);
    std::cout << b.getB();
}
```
**Възможни отговори:**
- а) 8.5
- б) undefined
- в) няма да се компилира

---
### **Задача 11**
```c++
#include <iostream>

struct C {
	double d;

	C() {
		d = 3.14;
		std::cout << "C()" << std::endl;
	}

	C(double d) {
		this->d = d;
		std::cout << "C(double d)" << std::endl;
	}

	~C() {
		std::cout << "~C()" << std::endl;
	}
};

void f(C obj)
{
	std::cout << "f(C obj)" << std::endl;
}

int main() {
	f(5.12);
}
```
---

### **Задача 12**
```c++
#include <iostream>

struct C {
	double d;

	C() {
    	std::cout << "C()" << std::endl;
	}

	C(double d) {
    	this->d = d;
    	std::cout << "C(double d)" << std::endl;
	}

	~C() {
    	std::cout << "~C()" << std::endl;
	}
};


int main() {
	C c = 5.2;
	C* ptr = new C[3];

	delete ptr;
}
```
---

### **Задача 13**
В какъв ред ще бъдат инициализирани член-данните за дадения клас и конструктор?

```cpp
#include <iostream>

class Person {
    char gender;
    int fn;
    int age;
    double averageGrade;
public:
    Person(char gender, int fn, int age, double averageGrade)
        : fn(fn), averageGrade(averageGrade), gender(gender), age(age) {}
};
```

---

### **Задача 14**
Какво ще се изведе на конзолата?

```cpp
#include <iostream>

class Person {
    char gender;
    int fn;
    int age;
    mutable double averageGrade;

public:
    Person(char gender, int fn, int age, double averageGrade)
        : fn(fn), averageGrade(averageGrade), gender(gender), age(age) {}

    double getAverageGrade() const {
        return ++averageGrade;
    }
};

int main() {
    Person p('f', 600123, 21, 4.43);
    std::cout << p.getAverageGrade();
}
```
**Възможни отговори:**
- а) 5.43
- b) 4.43
- c) undefined
- d) няма да се компилира

---

### **Задача 15**
Какво ще се отпечата на конзолата?

```cpp
#include <iostream>

class Test {
    void g() const {
        t();
    }
public:
    void t() {
        std::cout << "Hello" << std::endl;
    }
    void f() const {
        g();
    }
};

int main() {
    Test t;
    t.f();
}
```
**Възможни отговори:**
- а) Hello
- б) undefined
- в) няма да се компилира

---

### **Задача 16**
Какво ще се изведе на екрана?

```cpp
#include <iostream>

class A {
    int a;
public:
    A() { std::cout << "A()\n"; }
    A(int a) : a(a) {}
    ~A() { std::cout << "~A()\n"; }
};

class B {
    int b;
    A a;
public:
    B() { std::cout << "B()\n"; }
    B(int b) : b(b) {}
    ~B() { std::cout << "~B()\n"; }
};

class C {
    A a;
    B b;
public:
    C() : b(), a() { std::cout << "C()\n"; }
    ~C() { std::cout << "~C()\n"; }
};

int main() {
    C arr1[2];
    C* arr2 = new C[2];
    return 0;
}
```


