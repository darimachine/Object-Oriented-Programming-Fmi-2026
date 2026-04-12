# Теория `std::stringstream`:

### Какво е `std::stringstream`?  
`std::stringstream` е поток, който ни позволява да работим с низове, така както бихме работили с файлове или стандартния вход/изход.  

### Защо да използваме `std::stringstream`?  
- Позволява **форматирано извеждане** и **четене** от низове.  
- Улеснява **преобразуването** на различни типове данни в текстов формат и обратно.  

---

## Основни операции с `std::stringstream`

### Записване и четене от `stringstream`  
За да запишем стойности в `std::stringstream`, използваме оператора `<<`, подобно на `std::cout`.  
За да прочетем стойности от `std::stringstream`, използваме оператора `>>`, подобно на `std::cin`.  

#### Пример:  
```cpp
#include <iostream>
#include <sstream>

int main() {
	std::stringstream ss;

	// Записване в stringstream
	ss << "Число: " << 42 << ", Дробно: " << 3.14;

	// Извеждане на съдържанието
	std::cout << "Съдържание на ss: " << ss.str() << std::endl;

	// Подаване на нова стойност за четене
	ss.str("123 45.67 пример");

	int x;
	double y;
	char word[1024];

	// Четене от stringstream
	ss >> x >> y >> word;

	std::cout << "x = " << x << ", y = " << y << ", word = " << word << std::endl;

	return 0;
}
```

#### Изчистване на stringstream:

```c++
ss.str(""); // Изчиства съдържанието 
ss.clear(); // Нулира флаговете за грешки
```

#### Друг начин за създаване на stringstream:

```c++
#include <iostream>
#include <sstream>

int main() {
	std::stringstream ss("123 45.67 example");
	// Подаване на низ в конструктора. Потокът ще работи с подадения стринг.

	int x;
	double y;
	char word[1024];
	ss >> x >> y;
	ss.getline(word, 1024);
    
	std::cout << "x = " << x << ", y = " << y << ", word = " << word << std::endl;
	return 0;
}

```