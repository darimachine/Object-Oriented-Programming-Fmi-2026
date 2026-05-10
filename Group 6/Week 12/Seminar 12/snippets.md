### За задачите може да се възползвате от следното изображение:

![](https://flylib.com/books/2/253/1/html/2/images/16fig11.jpg)

**Задача 1.**
Какво ще се случи след изпълнението на кода?
```c++
int main()
{
    try
	{
		throw std::invalid_argument("invalid argument");
		throw std::runtime_error("runtime error");
	}
        catch (const std::runtime_error& re)
        {
            std::cout << re.what();
        }
	catch (const std::invalid_argument& ia)
	{
		std::cout << ia.what();
	}
}
```
A) Ще се изпише "ivalid argumentruntime error"

B) Ще се изпише "invalid argument"

C) Ще се изпише "runtime error"

D) Извикването ще се терминира - std::terminate()

**Задача 2.** Какъв ще е резултатът на конзолата от изпълнение на:
```c++
int main()
{
	try
	{
		throw std::invalid_argument("ERROR");
	}
	catch (const std::runtime_error&)
	{
		std::cout << "Runtime error";
	}
	catch (const std::logic_error&)
	{
		std::cout << "Logic error";
	}
	catch (const std::invalid_argument&)
	{
		std::cout << "Invalid argument";
	}
	catch (const std::exception&)
	{
		std::cout << "Exception";
	}
}
```
А) "Runtime error"

B) "Logic error"

C) "Invalid argument"

D) "Exception"

**Задача 3.** Какво ще се се случи след изпълнение на следният код:

```c++
struct A{
	A(){
		std::cout << "A()";
	}
	~A(){
		std::cout << "~A()";
	}
};
struct B{
	B(){
		std::cout << "B()";
		throw std::exception();
	}
	~B(){
		std::cout << "~B()";
	}
};
struct C{
	C(){
		std::cout << "C()";
	}
	~C(){
		std::cout << "~C()";
	}
};

struct X{
	A a;
	B b;
	C c;
	X(){
		std::cout << "X()";
	}
	~X(){
		std::cout << "~X()";
	}
};

int main() {
    try{
        X x;
    }
    catch(const std::exception& e){
        // HANDLE ERROR
    }
}
```

**Задача 4.** Обяснете защо не хвърляме грешки в деструкторите и дайте пример.

**Задача 5.** Какво ще се изведе на изхода ще стане ли нещо?
```c++
#include <iostream>

struct Test {
    ~Test() {
        std::cout << "Hello from destructor" << std::endl;
        throw 3;
    }
};

void g() {
    throw std::exception("Exception from g");
}

void f() {
    Test t; 
    try {
        g();
    }
    catch (int code) {
        std::cout << "Catched in f()";
        throw code;
    }
}

int main() {
    try {
        f();
    }
    catch (int code) {
        std::cout << "Catched in main()";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }
}
```

**Задача 6.** Какво ще се отпечата на конзолата:

```c++
#include <iostream>
struct A {
	static int counter;
	A() {
		counter++; // 2
		if (counter == 3)
		{
			throw std::exception();
		}

		std::cout << "A()";
	}
	~A()
	{
		std::cout << "~A()";
	}
};

int A::counter = 0;

struct B {
	B() {
		static int counter = 0;
		counter++; //1
		A::counter++; // 2
		if (counter == 2)
		{
			throw std::exception();
		}

		std::cout << "B()";
	}

	~B() {
		std::cout << "~B()";
	}
};

struct C {
	C() {
		std::cout << "C()";
	}
	~C() {
		std::cout << "~C()";
	}
};

struct X {
	A a; 
	B b; 
	C c; 
	X() {
		std::cout << "X()";
	} 
	~X() {
		std::cout << "~X()";
	}
};

int main()
{
	try {
		X x[5]; 
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl;
		std::cout << e.what();
		
	}
	
}
```