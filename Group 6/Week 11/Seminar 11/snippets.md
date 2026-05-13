## Snippets - Наследяване

##### 1. Ще възникне ли грешка в следния фрагмент код?

```cpp
#include <iostream>
using namespace std;

class Base {};

class Derived : public Base {};

int main()
{
    Base *bp = new Derived();   //(upcasting)
    Derived *dp = new Base();   //(downcasting)
}
```

##### Задача 2. Какво ще се отпечата?
```c++
#include <iostream>
using namespace std;

class Base
{
  public:
  Base() { cout << "Base"; }
};

class Derived : public Base
{
  public:
  Derived(int i) { cout << i; }
};

int main()
{
  Derived d2(10);
  return 0;
}
```

##### Задача 3. Какво ще се отпечата?
```c++
#include <iostream>
using namespace std;

class A
{
  int x;
};

class B : public A
{
  public:
  void show()
  {
    x=10;
    cout << x;
  }
};

int main()
{
  B b;
  b.show();
  return 0;
}
```

##### 4. Какво ще се случи след изпълнението на следния фрагмент код?
```cpp
#include <iostream>
using namespace std;
class Base {
public:
    void show() {
        cout << "In Base\n";
    }
};
class Derived : public Base {
public:
    int x;
    void show() {
        cout << "In Derived\n";
    }
    Derived() {
        x = 10;
    }
};

int main(void) {
    Base* bp, b;
    Derived d;
    bp = &d;
    bp->show();       //
    cout << bp->x;    // 
    return 0;
}
```


##### 5. Какво ще се отпечата на конзолата?

```cpp
#include <iostream>
class A 
{
    int* arr;

public:
    A() {
        std::cout << "A()" << std::endl;
    }

    A(const A& other) {
        std::cout << "Copy const A()" << std::endl;
    }

    A& operator=(const A& other) {
        std::cout << "Op=A()" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

class B : public A 
{
    int x;

public:
    B() {
        std::cout << "B()" << std::endl;
    }

    B(const B& other) {
        std::cout << "Copy const B()" << std::endl;
    }

    B& operator=(const B& other) {
        std::cout << "Op=B()" << std::endl;
    }

    ~B() {
        std::cout << "~B()" << std::endl;
    }
};

class C : public B 
{
    char* name;

public:
    C() {
        std::cout << "C()" << std::endl;
    }

    C(const C& other) {
        std::cout << "Copy const C()" << std::endl;
    }

    C& operator=(const C& other) {
        std::cout << "Op=C()" << std::endl;
    }

    ~C() {
        std::cout << "~C()" << std::endl;
    }
};

int main()
{
   //testvai copy i op= izvikvaniq!
    C c1;
    C c2 = c1;
}
```

##### 6. Какво ще се отпечата на конзолата?

```cpp
class A {
public:
    static int counter;

    A() {
        counter++;
        std::cout << "A()" << std::endl;
    }
};

int A::counter = 0;

class B : public A {
public:
    B() {
        counter++;
        std::cout << "B()" << std::endl;
    }
};

class C : public B {
public:
    C() {
        counter++;
        std::cout << "C()" << std::endl;
    }
};

int main() {
    C arr[2];
    std::cout << B::counter << std::endl;
}
```


##### Задача 7. Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;
class A
{
	float d;
public:
	int a;
	void change(int i){
		a = i;
	}
	void value_of_a(){
		cout<<a<<endl;
	}
};
 
class B: public A
{
	int a = 15;
public:
	void print(){
		cout<<a<<endl;
	}
};
 
int main(int argc, char const *argv[])
{
	B b;
	b.change(10);
	b.print();
	b.value_of_a();
 
	return 0;
}
```

##### Задача 8. Какво ще се опечата след изпълнението на следния фрагмент код?
```cpp
class A {
public:
    void print() {
        std::cout << "In A" << std::endl;
    }
};
class B : public A {
public:
    void print() {
        std::cout << "In B" << std::endl;
    }
};
class C : public B {
public:
    void print() {
        std::cout << "In C" << std::endl;
    }
};
int main() {
    C c;
    c.print();
}
```
##### Задача 9. Какво ще се опечата след изпълнението на следния фрагмент код?

```cpp
class A {
public:
    void print() {
        std::cout << "In A" << std::endl;
    }
};

class B : public A {
public:
    void print() {
        std::cout << "In B" << std::endl;
    }
};

class C : public B {};

int main() {
    C c;
    c.print();
}
```


##### Задача 10: Какво ще се случи след изпълнението на следния код?

```cpp
class Base {
    int i, j;
public:
    Base(int _i = 0, int _j = 0) : i(_i), j(_j) {}
};

class Derived : public Base {
public:
    void show() {
        cout << "i = " << i << " j = " << j;
    }
};

int main(void) {
    Derived d;
    d.show();
    return 0;
}
```
##### Задача 11: Какво ще се случи след изпълнението на следния код?
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int fun() { cout << "Base::fun() called\n"; }
    int fun(int i) { cout << "Base::fun(int i) called\n"; }
};

class Derived : public Base {
public:
    int fun() { cout << "Derived::fun() called\n"; }
};

int main() {
    Derived d;
    d.fun(5);  // Какво ще се случи тук?
    return 0;
}
```

---

```c++
// using Base::fun; // прави и двете функции от Base видими
```
##### Задача 12: Какво ще се случи след изпълнението на следния код?
```c++
#include <iostream>
using namespace std;
class Base {
public:
    int x, y;
    Base() { x = 2; y = 4; }
    Base(int i, int j) { x = i; y = j; }
};

class Derived : public Base {
public:
    Derived(int i, int j) : x(i), y(j) {}  
    void print() { cout << x << " " << y; }
};

int main() {
    Derived q(10, 10);
    q.print();
}
```

##### Задача 13:Какво ще се случи след изпълнението на следния код?
```c++
#include <iostream>
using namespace std;
class A {
public:
	void f() const {
		cout << "A::f()" << endl;
	}
};
class B : public A {
public:
	void f() const {
		cout << "B::f()" << endl;
	}
};

class C : protected B {
public:
	void g() const {
		cout << "C:g()" << endl;
	}
};
void func1(const A& obj) {
	obj.f();
}
void func2(const B& obj) {
	obj.f();
}
void func3(const C& obj) {
	obj.g();
	obj.f();
}

int main() {
	B obj1;
	C obj2;
	func1(obj1);
	func2(obj2);
	func3(obj2);
	return 0;
}
```

##### Задача 14. Какво ще се отпечата?

```c++
#include <iostream>
#include <string>
using namespace std;

class MyException : public logic_error {
public:
    MyException(const string& message) : logic_error(message) {}
};

int main(int argc, char const* argv[]) {
    try {
        throw MyException("Custom exception occurred!");
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    } catch (const MyException& e) {
        cout << "Caught MyException: " << e.what() << endl;
    }

    return 0;
}
```