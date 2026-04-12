## **Преговор. Указатели, референции, динамична памет.**

<img style="object-fit:contain;" align="right" width="450" height="600" src="https://study.com/cimages/multimages/16/1724cf83-a8ad-4ad5-aeca-0311114a819c_memory_alloc_cpp.png">

Паметта, която можем да използваме в **C++** има 4 основни типа:
<br />

- **Глобална (Статична)**: в тази памет се записват статичните/глобалните променливи.
- **Стекова (stack)**: тя съдържа "локалните" променливи, т.е. онези, които са дефинирани в телата на функции и са същевременно нестатични.
  - Заделя се в момента на дефиниция на променливите и се освобождава в момента на изход от scope-a, в която е дефинирана;
  - Последно заделената памет се освобождава първа (First in Last out);
  - Количеството заделена памет е определена по време на компилация;
  - Ние нямаме контрол над управлението над паметта
- **Динамична (heap)**: е "свободната" част от паметта, която се използва (<em>динамично</em>) в хода на програмата.
  - Заделя се и се освобождава по всяко време на изпълнение на програмата;
  - Областта за динамична памет е набор от свободни блокове памет;
  - Програмата може да заяви блок с произволна големина;
  - Имаме контрол над управлението на паметта;
- **Program Code**: памет, в която се пази нашият компилиран код
  - Може да се достъпва с function pointer-и

### **Създаване на променливи (в статичната и динамичната памет)**

```c++
int main() {
	int a = 10; // int in the stack
	int* ptr = new int(30); // int in the dyniamic memory
                           // we use a pointer on the stack to point to the int

	// print the value of the int in the stack and the one in the heap
	std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;

	// ptr holds an address in the dynamic memory where the int is placed
	std::cout << "Address of second number" << ptr << std::endl;

	delete ptr; // delete the int in the stack to prevent memory leak

	ptr = &a;   // redirect the pointer to int in the stack
	std::cout << "Address of first number" << ptr << std::endl; // now ptr holds the address that is in the stack

	int& b = a; // creates int which data is on the address of a => they share the same memory
	b = 30;

	std::cout << "First number" << a << std::endl // 30
}
```

### **Подаване на параметри във функция**

#### **Подаване по копие.**

```c++
#include <iostream>

void f(int a) {
	a++; // a++ will increment the value of the copy
}

int main() {
	int a = 10;
	f(a);
	std::cout << a << std::endl; //10
}
```

#### **Подаване по референция.**

```c++
#include <iostream>

void f(int& a) {
	a++; // a++ will increment the actual value of the passed variable
}

int main() {
	int a = 10;
	f(a);
	std::cout << a << std::endl; //11
}
```

#### **Подаване по указател.**

```c++
#include <iostream>

void f(int* a) {
	(*a)++; // a++ will increment the value at the address where the pointer points at
}

int main() {
	int a = 10;
	f(&a); // &a gives us the address of a which can be assigned to a pointer variable
	std::cout << a << std::endl; //11
}
```

---

_Credits: [Georgi Terziev](https://github.com/GeorgiTerziev02/)_
