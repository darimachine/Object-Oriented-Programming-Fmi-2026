# ООП - Практикум 12 - 13.05.2026
# Templates & exceptions 

# Задача 1
Напишете следните темплейтни функции:

1. Функция `mySwap`, която разменя стойностите на два елемента от произволен тип.

```cpp
void mySwap(T& a, T& b) {...}
```

2. Функция `isEqual`, която проверява дали стойностите на два елемента от произволен тип са равни.
* Направете специализация на функцията за елементи от тип double като сравнявате стойностите с помощта на epsilon.

```cpp
bool isEqual(const T& a, const T& b) {...}
```

3. Функция `printArr`, която извежда елементите на подаден масив, разделени с интервал.
* Създайте concept с име Printable, който позволява само типове, които могат да бъдат извеждани чрез std::cout. Създайте функцията така че да приема само типове, удовлетворяващи concept-а Printable. 

```cpp
void printArr(const T* arr, size_t size) {...}
```

# Задача 2

Да се създаде темплейтен клас Pair със следните полета и член-функции:

### полета:
- T first
- U second

### член-функции:
- конструктор с параметри, който приема два аргумента, съответно стойности за first и за second
- getter-и за first и second
- setter-и за first и second

# Задача 3

1. Направете копие на класа Pair от Задача 2 и го наименовайте NumericPair.

2. Променете темплейта, така че first и second да са от един и същ произволен тип (т.е. template < typename T > ... T first; T second;).

3. Създайте concept с име Number, който позволява само цели числа и числа с плаваща запетая (използвайте std::integral и std::floating_point).

4. Направете съответните промени в класа NumericPair така че типът T да удовлетворява concept-а Number.

5. Добавете валидации в setter-ите на first и second, които при отрицателен аргумент хвърлят грешка std::invalid_argument.

6. Създайте "custom" exception, наследник на std::runtime_error, който да се казва DivisionByZeroException. Направете default constructor със съобщение "Division by zero" и контруктор с параметри, приемащ const string& message.

7. Добавете нова член-функция в класа NumericPair: T divide() {...}, която връща резултата от first/second, ако second е 0 да се хвърли "custom" exception-а DivisionByZeroException.

8. Копирайте следния код и направете нужните корекции, за да обработва правилно хвърлянето на грешки.

```cpp
int main() {
    NumericPair<double> p;

    p.setFirst(10.5);
    p.setSecond(-3.14);

    std::cout << "Values set successfully!" << std::endl;

    std::cout << "Division result: " << p.divide() << std::endl;

    std::cout << "Program finished successfully!" << std::endl;

    return 0;
}
```

# Задача 4 — Document System (Rule of Zero)

### 1. Да се създаде темплейтен клас Document< T >, който представя документ с произволен тип съдържание.

### полета:
- std::string title
- T content
- bool locked

### методи:
- void lock() — заключва документа
- void unlock() — отключва документа
- void updateContent(const T& value) - заменя старото съдържание на документа с новото

### изисквания:
- Ако документът е заключен и се опитаме да го променим → хвърля std::runtime_error
- Ако се повторно lock/unlock → std::logic_error

---

### 2. Да се създаде темплейтен клас User< T >, който представлява потребител и неговите документи.

### полета:
- std::string name
- int id
- std::vector<Document< T >> documents

### методи:
- void addDocument(const Document< T >& doc) — добавя документ
- const Document< T >& getDocument(size_t index) — връща документ по индекс
- void updateDocument(size_t index, const T& newContent) - променя съдържанието на документ на подаден индекс

### изисквания:
- Ако индексът е невалиден → хвърля std::out_of_range

---

### 3. Да се създаде темплейтен клас DocumentManager< T >, който управлява множество потребители.

### полета:
- std::vector<User< T >> users

### методи:
- void addUser(const User< T >& user) — добавя потребител
- User< T >& findUser(const std::string& name) — намира потребител по име

### изисквания:
- Ако потребителят не е намерен → хвърля std::runtime_error 

<br><br>

![](./images/Bugs_Bunny_1.png)