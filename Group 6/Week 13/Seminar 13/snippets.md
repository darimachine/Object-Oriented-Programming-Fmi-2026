

##### 1. Можем ли да правим обекти от абстрактен клас?
 
##### 2. Може ли да правим указатели и референция към обект от абстрактен клас?

---
##### 3. Какво ще се случи след изпълнението на следния фрагмент код?

```cpp
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() = 0;
};
int main(void)
{
    Base b;
    Base *bp;
    return 0;
}
```


##### 4. Какво ще се случи след изпълнението на следния фрагмент код?

```cpp
class Base {
public:
    virtual void show() = 0;
};

class Derived : public Base {
public:
    void show() { cout << "In Derived\n"; }
};

int main() {
    Derived d;
    Base &br = d;
    br.show();
}
```

#####  5. Може ли конструктор да е виртуален?

<details>
<summary> Отговор </summary>
Проблемът:
За да използваме виртуалност, трябва обектът вече да е създаден и да има vtable.
Но конструкторът създава обекта — тоест, още няма готова vtable структура!
Следователно няма как конструктор да бъде виртуален.
</details>

##### 6. Какво ще се отпечата след изпълнението на следния фрагмент код?  
```cpp
#include <iostream>
using namespace std;
class Base {
public:
    virtual void show() { cout << "In Base\n"; }
};

class Derived : public Base {
public:
    void show() { cout << "In Derived\n"; }
};

int main() {
    Base *bp, b;
    Derived d;
    bp = &d;
    bp->show();
    bp = &b;
    bp->show();
}
```

##### 7. Допусната ли е грешка в следния фрагмент код? Обосновете отговора си.

```cpp
#include <iostream>
class A {
    int a;
};

class B : public A {
    char c;
};

int main()
{
    A* tmp = new B();
    delete tmp;
}
```

##### 8. Каква стойност ще върне `sizeof(A)` `sizeof(B)` `sizeof(C)`?

```cpp
#include <iostream>
class A {
    int a;
};

class B : public A {
    char c;
public:
    virtual void print() const {
        std::cout << "B";
    }
};

class C : public B {
    char c;
};
```

##### 9. Какво ще се отпечата след изпълнението на следния фрагмент код?

```cpp
#include <iostream>
class A {
public:
    virtual void fun();
};

class B {
public:
    void fun();
};

int main() {
    int a = sizeof(A), b = sizeof(B);
    if (a == b)
        std::cout << "a == b";
    else if (a > b)
        std::cout << "a > b";
    else
        std::cout << "a < b";
}
```
##### 9. Какво ще се отпечата след изпълнението на следния фрагмент код?
```c++
#include <iostream>

using namespace std;

class A
{
    int a;
public:
    virtual void f()
    {
        std::cout << "A";
    }
};

class B : public A
{
    double b;
    bool c;
public:
    void f() override
    {
        std::cout << "B";
    }
};

int main()
{
    std::cout << sizeof(A);
    std::cout << sizeof(B);
}
```

##### 10. Какво ще се отпечата след изпълнението на следния фрагмент код?

```cpp
class Base {
public:
    Base() { std::cout << "Base() "; }
    virtual ~Base() { std::cout << "~Base() "; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived() "; }
    ~Derived() { std::cout << "~Derived() "; }
};

int main() {
    Base *Var = new Derived();
    delete Var;
}
```

##### 11. Може ли да имаме static виртуални функции?

```cpp
#include <iostream>
using namespace std;

class Test {
public:
    virtual static void fun() { }
};
```
##### 12. Какво ще се отпечата след изпълнението на следния фрагмент код?

```cpp
class Base {
public:
    virtual void show() { cout << " In Base\n"; }
};

class Derived : public Base {
public:
    void show() { cout << "In Derived\n"; }
};

int main(void) {
    Base *bp = new Derived;
    bp->Base::show();
}
```

##### 13. Какво ще се отпечата след изпълнението на следния фрагмент код?

```cpp
class Parent {
public:
    void display() { std::cout << "Parent"; }
};

class Child : public Parent {
public:
    void display() { std::cout << "Child"; }
    ~Child() { std::cout << "Child class Destructor called"; }
};

int main() {
    Parent* p = new Child;
    p->display();
    delete p;
}
```

##### 14. Какво ще се отпечата след изпълнението на следния фрагмент код?  

```cpp
class Superclass {
public:
    virtual void display() { std::cout << "Superclass "; }
};
class Subclass : public Superclass {
public:
    void display() override { std::cout << "Subclass "; }
};

int main() {
    Superclass a;
    Subclass b;
    Superclass c;
    Superclass *pa[] = { &a, &b, &c };
    for (int j = 0; j < 3; j++) {
        pa[j]->display();
    }
}
```

##### 15. Какво ще се отпечата след изпълнението на следния фрагмент код?

```cpp
class Base {
public:
    ~Base() { std::cout << "Base Destructor"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived Destructor"; }
};

int main() {
    Base* b = new Derived;
    delete b;
}
```


##### 16. Какво ще се отпечата?
```c++
#include <iostream>
using namespace std;

class A {
public:
    virtual void f() {
        cout << "A::f()" << endl;
    }
    virtual ~A() = default;
};

class B : public A {
public:
    void f() override {
        cout << "B::f()" << endl;
    }
    virtual void g() {
        cout << "B::g()" << endl;
    }
};

class C : public B {
public:
    void f() const {
        cout << "C::f()" << endl;
    }
    void g() override {
        cout << "C::g()" << endl;
    }
};

int main() {
    A* ptr1 = new C();
    ptr1->f();
    
    B* ptr2 = new C();
    ptr2->f();
    ptr2->g();

    C obj;
    obj.f();

    delete ptr1;
    delete ptr2;
}
```
##### 17. Какво ще се отпечата? Има ли проблем в кода?
```c++
#include <iostream>
using namespace std;
class Base {
	int a = 0;
public:
	Base() {
		std::cout << "Base()" << std::endl;
	}
	virtual void f() const {
		std::cout << "Base::f()" << std::endl;
	}
	~Base() {
		std::cout << "~Base()";
	}

};

class Der1 : public Base {
	int b = 0;
public:
	Der1() {
		std::cout << "Der1()" << std::endl;
	}
	void f() const override {
		Base::f();
		std::cout << "Der1::f()" << std::endl;
	}

	~Der1() {
		std::cout << "~Der1()" << std::endl;
	}
};

class Der2 : public Der1 {
	int c = 0;
public:
	Der2() {
		std::cout << "Der2()" << std::endl;
	}

	~Der2() {
		std::cout << "~Der2()" << std::endl;
	}

};

int main() {
	Base* ptr = new Der2();
	ptr->f();
	delete ptr;
}
```

##### 18. Какво ще се изведе на конзолата?

```cpp
#include <iostream>
class Base {
public:

    virtual void f() {
        std::cout << "Base::f()" << std::endl;
    }
};

class A : public Base {
public:
    void f() override {
        std::cout << "A::f()" << std::endl;
    }
};

class B : public Base {
public:
    void f() {
        std::cout << "B::f()" << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;

    Base* ptr = (n % 2 == 0 ? new A() : new B());
    ptr->f();
    delete ptr;
}
```