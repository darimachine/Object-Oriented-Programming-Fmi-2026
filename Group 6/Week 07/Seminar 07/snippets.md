#### Какво ще се изведе
```c++
#include<iostream>

static int globalCounter=0;

void counterStatic(){
    globalCounter++;
    std::cout<<"globalCounter: "<< globalCounter <<std::endl;
}

void counterStatic2(){
    static int functionCounter;
    functionCounter++;
    std::cout<<"static in function: "<< functionCounter << std::endl;
}

void nonStaticCounter(){
    int scopeCounter = 0;
    scopeCounter++;
    std::cout<<"regular variable: "<< scopeCounter << std::endl;
}

int main(){
    for(int i = 0; i < 3; i++){
        counterStatic();
    }
       for(int i = 0; i < 3; i++){
        counterStatic2();
    }
       for(int i = 0; i < 3; i++){
        nonStaticCounter();
    }
}

```
#### Какво ще се изведе и каква е разликата между static функция и не static
```c++
#include<iostream>

static int globalCounter=0;

static void counterStatic(){
    globalCounter++;
}

static void printStaticGlobal(){
    counterStatic();
    std::cout<<"global static: "<< globalCounter<<std::endl;
}

int main(){
    for(int i = 0; i < 3; i++){
        printStaticGlobal();
    }
   
}
```
#### Достъп вътре в класа!
```c++
#include <iostream>

class MyClass {
private:
    int nonStaticVar = 10;
    static int staticVar;

public:
    // Не-статична функция: има достъп до всичко
    void normalFunction() {
        std::cout << "nonStaticVar = " << nonStaticVar << std::endl;
        std::cout << "staticVar = " << staticVar << std::endl;
    }

    // Статична функция: има достъп САМО до статични членове
    static void staticFunction() {
        // std::cout << nonStaticVar; ❌ Невъзможно – няма 'this'
        std::cout << "staticVar = " << staticVar << std::endl; // ✅ OK
    }
};

// Инициализация на статичния член
int MyClass::staticVar = 42;

int main() {
    MyClass obj;

    obj.normalFunction();     // Викаме не-статична функция
    MyClass::staticFunction(); // Викаме статична функция

    return 0;
}
```




#### Какво ще изведе следният код:
```c++
#include <iostream>
class A {
public:
	A() {
		std::cout << "A()\n";
	}

	~A() {
		std::cout << "~A()\n";
	}
};

class B {
public:
	B() {
		std::cout << "B()\n";
	}

	~B() {
		std::cout << "~B()\n";
	}
};

void print() {
	A a;
	static B b;
}
int main() {
	print(); 
	print(); 
	print(); 
	
	return 0;
}

```
#### Има ли проблем в следния код:
```c++
class Test {
	int a;
	static int p;
	double d;
public:
	double getD() const {
		return d;
	};

	int getP() const {
		return p;
	};
};
```
```c++
class Test {
	static int p;
	int* ptr;

public:
	static int getP() const {
		return p;
	}
	const int* getPtr() const {
		return ptr;
	}
};

```

**Бонус** Какво ще се случи след изпълнение на кода:

```c++
#include <iostream>
void f(int);

void (*fp)(int) = nullptr;

void g(int n) {
    static int count = 0;
    count += n;
    std::cout << count << " ";

    if (count < 10) {
        fp = f;
        fp(n + 1);
    }
}

void f(int n) {
    static int count = 0;
    count += n;
    std::cout << count << " ";

    if (count < 10) {
        fp = g;
        fp(n + 1);
    }
}
int main()
{
    fp = f;
    fp(1);
}
```