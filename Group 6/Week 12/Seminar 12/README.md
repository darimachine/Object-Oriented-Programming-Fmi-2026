# Обработка на Грешки и Изключения в C++

---

##  Съдържание

1. [Какво е грешка и защо трябва обработка?](#1-какво-е-грешка-и-защо-трябва-обработка)
2. [Error Codes — класическият подход](#2-error-codes--класическият-подход)
3. [Изключения — throw, try, catch](#3-изключения--throw-try-catch)
4. [Stack Unwinding — размотаване на стека](#4-stack-unwinding--размотаване-на-стека)
5. [Хващане по стойност vs. по референция](#5-хващане-по-стойност-vs-по-референция)
6. [Стандартни изключения и йерархия](#6-стандартни-изключения-и-йерархия)
7. [Собствен клас за изключение](#7-собствен-клас-за-изключение)
8. [Rethrow и std::current\_exception](#8-rethrow-и-stdcurrent_exception)
9. [Изключения в конструктори](#9-изключения-в-конструктори)
10. [Изключения в деструктори](#10-изключения-в-деструктори)
11. [Нива на Exception Safety](#11-нива-на-exception-safety)
12. [std::optional (C++17)](#12-stdoptional-c17)
13. [std::expected (C++23)](#13-stdexpected-c23)
14. [Edge Cases и капани](#14-edge-cases-и-капани)
15. [Обобщение](#15-обобщение)

---

## Основни дефиниции

> **Изключение (exception)** — обект, хвърлен при необичайна ситуация, която прекъсва нормалния поток на изпълнение и предава контрола нагоре по call stack-а.

> **Stack Unwinding** — при хвърлено изключение: деструкторите на всички локални обекти се извикват в обратен ред докато се намери `catch` блок.

> **`noexcept`** — гаранция, че функцията никога не хвърля изключение. Деструкторите са `noexcept` по подразбиране от C++11.

> **Exception Safety** — ниво на гаранция какво се случва с обектите при хвърлено изключение.


> **`std::optional<T>`** — обвивка за стойност, която може да липсва. Не е механизъм за грешки — просто „може да я няма".

> **`std::expected<T, E>`** — обвивка за стойност **или** грешка. Алтернатива на изключения без overhead.

---

## 1. Какво е грешка и защо трябва обработка?

Представете си функция за деление:

```cpp
int divide(int a, int b) {
    return a / b;   // Какво ако b == 0?
}

divide(10, 0);   // Деление на нула → програмата се срива!
```

Грешките в програмата се разделят на две категории:

**Очаквани ситуации** — нормална логика, предвидими:
- Търсиш нещо и то не е намерено
- Потребителят въвежда невалиден формат

**Изключителни ситуации** — нарушение на инварианта, невъзможно е да продължи:
- Конструкторът не може да създаде валиден обект
- Файлът не може да се отвори въпреки валидни аргументи
- Паметта свършва

### Кога да ползваме изключения

```
✅ Конструктори — нямат return value, единственият начин за сигнализиране
✅ Нарушения на инварианта на класа
✅ Грешки на границата между слоеве (I/O, OS, DB)
✅ Ситуации, непредвидими за текущата функция

❌ Нормален контролен поток
❌ Очаквани резултати — find() в контейнер
❌ Performance-critical вътрешни цикли
❌ Embedded системи без поддръжка на exceptions
```

### Защо `throw` е скъпа операция

`throw` включва: размотаване на стека, RTTI, копиране на обекта в специална exception зона. Времето е **непредсказуемо**. Не се ползва за нормален контролен поток.

---

## 2. Error Codes — класическият подход

Функцията връща специална стойност — код за грешка. Класическият C подход, все още валиден.

### С `enum class` — четимо и типово безопасно

```cpp
enum class ErrorCode {
    OK,
    DivisionByZero,
    InvalidInput,
    FileNotFound,
    Full
};

ErrorCode divide(int a, int b, int& result) {
    if (b == 0) return ErrorCode::DivisionByZero;
    result = a / b;
    return ErrorCode::OK;
}

int main() {
    int result;
    ErrorCode code = divide(10, 0, result);

    if (code == ErrorCode::OK)
        std::cout << "Резултат: " << result << "\n";
    else if (code == ErrorCode::DivisionByZero)
        std::cout << "Грешка: деление на нула!\n";
}
```

### Недостатъкът — кодът може да се игнорира

```cpp
int result;
divide(10, 0, result);   // ❌ кодът за грешка е игнориран!
std::cout << result;      // UB — result не е инициализиран
```

### Проблемът с вложени извиквания — boilerplate

```cpp
ErrorCode processFile(const std::string& path) {
    ErrorCode err = openFile(path);
    if (err != ErrorCode::OK) return err;
    err = readHeader();
    if (err != ErrorCode::OK) return err;
    err = readData();
    if (err != ErrorCode::OK) return err;
    return ErrorCode::OK;
    // Бизнес логиката се удавя в проверки
}
```

### Кога е подходящо

```
✅ Embedded системи, game engines, real-time системи
✅ Нулев overhead — без stack unwinding
✅ Предсказуем контролен поток
❌ Лесно се пропуска — компилаторът не предупреждава
```

---

## 3. Изключения — throw, try, catch

### `throw` — хвърляне

`throw` хвърля обект и **незабавно прекъсва** текущата функция. Кодът след `throw` не се изпълнява:

```cpp
void checkAge(int age) {
    if (age < 0)
        throw std::invalid_argument("Възрастта не може да е отрицателна!");
    // Тук се стига само ако age >= 0
    std::cout << "Валидна възраст: " << age << "\n";
}
```

`throw` хвърля **обект**, не тип. Обектът се **копира или премества** в специална exception зона:

```cpp
throw 42;                               // ❌ хвърля int — лоша практика
throw "грешка";                         // ❌ хвърля const char*
throw std::runtime_error("Описание");   // ✅ препоръчително
```

### `try` и `catch` — хващане

```cpp
try {
    checkAge(-5);
    std::cout << "Тук не се стига\n";   // прескача се
}
catch (const std::invalid_argument& e) {
    std::cout << "Хваната грешка: " << e.what() << "\n";
}
std::cout << "Продължаваме след catch\n";   // изпълнява се
```

```
Изход:
Хваната грешка: Възрастта не може да е отрицателна!
Продължаваме след catch
```

### Множество catch блокове — редът е критичен

Проверяват се **отгоре надолу**. Изпълнява се само **първият съвпадащ**. Задължително от **най-специфичен към най-общ**:

```cpp
try {
    riskyOperation();
}
catch (const std::invalid_argument& e) {   // ← най-специфичен
    std::cout << "Невалиден аргумент: " << e.what() << "\n";
}
catch (const std::out_of_range& e) {
    std::cout << "Извън граница: " << e.what() << "\n";
}
catch (const std::exception& e) {           // ← улавя всички std::exception
    std::cout << "Обща грешка: " << e.what() << "\n";
}
catch (...) {                               // ← улавя абсолютно всичко
    std::cout << "Неизвестна грешка!\n";
}
```

```cpp
// ❌ ГРЕШЕН РЕД — invalid_argument никога не се достига:
catch (const std::exception& e)        { ... }  // хваща ВСИЧКО
catch (const std::invalid_argument& e) { ... }  // мъртъв код!
```

### `catch (...)` — catch-all

Улавя всяко C++ изключение — включително `int`, `char*` и нестандартни типове. Полезен на **границата** на приложението:

```cpp
int main() {
    try {
        runApplication();
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << "\n";
    }
    catch (...) {
        std::cerr << "[ERROR] Неизвестна грешка!\n";
        // ⚠️ Никога не поглъщай без логване!
    }
}
```

**Лоши практики с `catch (...)`:**
- Да се използва без повторно хвърляне
- Да „поглъща" грешките без реакция

---

## 4. Stack Unwinding — размотаване на стека

Когато се хвърли изключение:
1. Текущата функция прекъсва
2. Започва размотаване на стека
3. Всички локални обекти се унищожават (деструкторите им се извикват в обратен ред)
4. Търси се първият `catch`, който може да улови изключението

```cpp
void functionC() {
    throw std::runtime_error("Грешка в C!");
}

void functionB() {
    std::string resource("Ресурс B");         // локален обект
    std::cout << "Влизаме в B\n";
    functionC();                               // хвърля!
    std::cout << "Излизаме от B\n";           // НЕ се изпълнява!
}   // ← ~string() се извиква тук при размотаване

int main() {
    try {
        functionB();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Хванато: " << e.what() << "\n";
    }
}
```

```
Изход:
Влизаме в B
Хванато: Грешка в C!
(resource се унищожава автоматично при размотаване)
```

### Визуализация

```
Нормален поток:
  main() → functionA() → functionB() → Успех → връщане

Поток с изключение:
  main() → functionA() → functionB() → THROW
      ↑                                    ↓
   catch                        Stack unwinding:
   хваща                        ~functionB locals
                                 ~functionA locals
                                 → catch в main()
```

Деструкторите се гарантирано извикват — именно затова RAII и `unique_ptr` работят надеждно дори при изключения.

---

## 5. Хващане по стойност vs. по референция

### Хващане по стойност — лоша практика (slicing!)

```cpp
catch (std::exception e)  // ❌ Slicing!
```

При хващане по стойност обектът се **нарязва** — ако е хвърлен `std::invalid_argument`, `e` ще е копие от тип `std::exception`. Полиморфизмът се губи:

```cpp
try {
    throw std::invalid_argument("лош аргумент");
}
catch (std::exception e) {           // ❌ e е std::exception, не invalid_argument
    std::cout << e.what() << "\n";   // може да не работи правилно
}
```

### Хващане по const референция — правилно

```cpp
catch (const std::exception& e)  // ✅
```

Предимства:
- Избягва object slicing
- Не прави излишни копия
- Позволява полиморфизъм — `e.what()` извиква правилния виртуален метод

```cpp
try {
    throw std::invalid_argument("лош аргумент");
}
catch (const std::exception& e) {   // ✅ e е референция към оригиналния invalid_argument
    std::cout << e.what() << "\n";  // "лош аргумент" — работи правилно
}
```

---

## 6. Стандартни изключения и йерархия

![](https://flylib.com/books/2/253/1/html/2/images/16fig11.jpg)

```
std::exception                        (базов — метод what())
│
├── std::logic_error                  (грешки в логиката — предотвратими)
│   ├── std::invalid_argument         — невалиден аргумент
│   ├── std::out_of_range             — индекс извън граница
│   ├── std::length_error             — невалидна дължина
│   └── std::domain_error             — невалиден домейн
│
└── std::runtime_error                (грешки при изпълнение — непредотвратими)
    ├── std::overflow_error           — аритметично препълване
    ├── std::underflow_error          — аритметично подпълване
    └── std::range_error              — резултатът е извън обхват
```
### Методът `what()`
 
Всяко изключение, наследяващо `std::exception`, има метод `what()` — връща текстово описание на грешката:
 
```cpp
const char* what() const noexcept;
```
 
```cpp
try {
    throw std::invalid_argument("Невалидна стойност: -5");
}
catch (const std::exception& e) {
    std::cout << e.what() << "\n";   // "Невалидна стойност: -5"
}
```
 
`what()` е **виртуален** в `std::exception` — затова при хващане по `const std::exception&` се извиква правилната версия дори при наследен клас:
 
```cpp
try {
    throw std::out_of_range("Индекс 10 е извън граница [0, 5)");
}
catch (const std::exception& e) {        // хваща като std::exception
    std::cout << e.what() << "\n";       // но what() е виртуален →
                                          // "Индекс 10 е извън граница [0, 5)"
                                          // (не се губи информацията)
}
```
 
При **собствен клас** — `what()` се предефинира с `override`:
 
```cpp
class MyException : public std::exception {
    std::string message;
public:
    explicit MyException(const std::string& msg) : message(msg) {}
 
    const char* what() const noexcept override {
        return message.c_str();
    }
};
```
 
Важното: `what()` е `noexcept` — не трябва да хвърля изключение.

### `logic_error` vs. `runtime_error`

`std::logic_error` — **бъг на програмиста**, предотвратим с правилен код:

```cpp
void setAge(int age) {
    if (age < 0 || age > 150)
        throw std::invalid_argument("Невалидна възраст: " + std::to_string(age));
}

const int* getElement(const int* arr, int size, int i) {
    if (i < 0 || i >= size)
        throw std::out_of_range("Индекс " + std::to_string(i) + " е извън граница");
    return &arr[i];
}
```

`std::runtime_error` — **зависи от средата**, не от кода:

```cpp
void openConfig(const std::string& path) {
    // Файлът може да не съществува — не е грешка на програмиста
    throw std::runtime_error("Конфигурационният файл '" + path + "' не е намерен");
}
```

---

## 7. Собствен клас за изключение

### Защо е нужен?

Стандартните изключения носят само текстово съобщение. В реален проект е нужна **допълнителна информация** — код на грешка, HTTP статус, ред от файл и т.н.

### Как се прави

Собственият клас наследява `std::exception` или негов наследник и предефинира метода `what()`:

```cpp
#include <stdexcept>
#include <string>

class MyException : public std::exception {
    std::string message;
public:
    explicit MyException(const std::string& msg) : message(msg) {}

    // Задължително: override на what()
    const char* what() const noexcept override {
        return message.c_str();
    }
};
```

```cpp
throw MyException("Нещо се обърка!");

try {
    throw MyException("Тестова грешка");
}
catch (const MyException& e) {
    std::cout << e.what() << "\n";   // Тестова грешка
}
```

### По-богат собствен клас — с допълнителна информация

```cpp
#include <stdexcept>
#include <string>

class DatabaseException : public std::runtime_error {
    int         errorCode;
    std::string failedQuery;

public:
    DatabaseException(const std::string& msg,
                      int code,
                      const std::string& query = "")
        : std::runtime_error(msg),
          errorCode(code),
          failedQuery(query) {}

    int         getErrorCode()   const { return errorCode;   }
    std::string getFailedQuery() const { return failedQuery; }
    // what() е наследен от std::runtime_error — не се пише отново
};
```

```cpp
void runQuery(const std::string& sql) {
    throw DatabaseException("Неуспешна заявка", 503, sql);
}

int main() {
    try {
        runQuery("SELECT * FROM students");
    }
    catch (const DatabaseException& e) {
        std::cout << "[" << e.getErrorCode() << "] "
                  << e.what() << "\n"
                  << "Заявка: " << e.getFailedQuery() << "\n";
    }
    catch (const std::exception& e) {
        // Хваща всичко останало наследяващо std::exception
        std::cout << "Обща грешка: " << e.what() << "\n";
    }
}
```

```
[503] Неуспешна заявка
Заявка: SELECT * FROM students
```

### Йерархия на собствени изключения — Rule of Zero

```cpp
// ------- Базово изключение за цялото приложение -------
class AppException : public std::exception {
    std::string message;
public:
    explicit AppException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
    // Деструктор, copy, move — генерирани правилно от компилатора
};

// ------- Категория: мрежови грешки -------
class NetworkException : public AppException {
public:
    explicit NetworkException(const std::string& msg)
        : AppException("Мрежова грешка: " + msg) {}
};

// ------- Специфичен вид мрежова грешка -------
class TimeoutException : public NetworkException {
    int seconds;
public:
    explicit TimeoutException(int sec)
        : NetworkException("Timeout след " + std::to_string(sec) + " сек."),
          seconds(sec) {}

    int getSeconds() const { return seconds; }
};

// ------- Категория: грешки с базата данни -------
class DatabaseException : public AppException {
    int errorCode;
public:
    DatabaseException(const std::string& msg, int code)
        : AppException("DB: " + msg), errorCode(code) {}

    int getErrorCode() const { return errorCode; }
};
```

```
AppException
├── NetworkException
│   └── TimeoutException
└── DatabaseException
```

```cpp
void simulate() {
    throw TimeoutException(30);
}

int main() {
    try {
        simulate();
    }
    catch (const TimeoutException& e) {
        // Хваща само TimeoutException
        std::cout << "Timeout след " << e.getSeconds() << " сек.\n";
        std::cout << e.what() << "\n";
    }
    catch (const NetworkException& e) {
        // Хваща NetworkException и всички негови наследници
        // (TimeoutException вече е хваната по-горе)
        std::cout << "Мрежова грешка: " << e.what() << "\n";
    }
    catch (const AppException& e) {
        // Хваща всички наши изключения
        std::cout << "Грешка в приложението: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        // Хваща всички STL изключения
        std::cout << "STL грешка: " << e.what() << "\n";
    }
}

// Изход:
// Мрежова грешка: Timeout след 30 сек.
```

---

## 8. Rethrow и std::current\_exception

### `throw;` — повторно хвърляне без загуба на тип

```cpp
void logAndRethrow() {
    try {
        riskyOperation();
    }
    catch (const std::exception& e) {
        std::cerr << "Логваме: " << e.what() << "\n";
        throw;      // ✅ хвърля оригиналния обект с оригиналния тип
        // throw e; // ❌ хвърля КОПИЕ от тип std::exception — губи типа!
    }
}
```

### `std::current_exception` — запазване за по-късно

```cpp
#include <exception>

std::exception_ptr saved;

void captureException() {
    try {
        throw std::runtime_error("Запазена грешка");
    }
    catch (...) {
        saved = std::current_exception();   // запазва изключението
    }
}

void rethrowLater() {
    if (saved)
        std::rethrow_exception(saved);   // хвърля отново
}
```

Полезно при: предаване на изключения между нишки, отложена обработка, логване на boundary слоеве:

```cpp
// Практически пример — логване с rethrow
int getValueFromDB(Database* db, const std::string& key) {
    try {
        return db->getValue(key);
    }
    catch (const DatabaseException& e) {
        globalLog.error("DB query failed: " + std::string(e.what()));
        throw;   // ✅ повторно хвърля — извикващият решава какво да прави
    }
}
```

---

## 9. Изключения в конструктори

Конструкторите нямат тип на връщане — **единственият начин** да съобщят за грешка е чрез изключение.

### Правилото

Ако обектът не може да бъде валидно конструиран — хвърляй в конструктора:

```cpp
class BankAccount {
    std::string owner;
    double      balance;
public:
    BankAccount(const std::string& o, double b)
        : owner(o), balance(b) {
        if (o.empty())
            throw std::invalid_argument("Името не може да е празно");
        if (b < 0.0)
            throw std::invalid_argument("Балансът не може да е отрицателен");
        std::cout << "Акаунт създаден за " << owner << "\n";
    }
};

int main() {
    try {
        BankAccount a1("Иван", 1000.0);   // ✅ OK
        BankAccount a2("", -500.0);        // ❌ хвърля invalid_argument
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Грешка: " << e.what() << "\n";
    }
}
```

### Какво се случва при хвърляне от конструктор

```
1. Обектът НЕ се счита за създаден
2. Деструкторът МУ не се извиква  ← важно!
3. Деструкторите на ВЕЧЕ конструираните член-данни се извикват автоматично
```

### Проблемът с ръчна памет — Rule of Zero е решението

```cpp
// ❌ ОПАСНО — при хвърляне деструкторът не се извиква!
class Dangerous {
    int* a = nullptr;
    int* b = nullptr;
public:
    Dangerous() {
        a = new int[100];   // (1) заделено
        b = new int[200];   // (2) заделено
        throw std::runtime_error("Грешка!");
        // ~Dangerous() НИКОГА не се извиква → a и b ИЗТИЧАТ!
    }
    ~Dangerous() { delete[] a; delete[] b; }
};
```

```cpp
// ✅ Rule of Zero — unique_ptr членовете се унищожават автоматично
class Safe {
    std::unique_ptr<int[]> a;
    std::unique_ptr<int[]> b;
public:
    Safe() {
        a = std::make_unique<int[]>(100);
        b = std::make_unique<int[]>(200);
        throw std::runtime_error("Грешка!");
        // a и b се унищожават автоматично при размотаване!
        // unique_ptr деструкторите се извикват — памет не изтича
    }
};
```

Деструкторите на **вече конструираните** член-данни се извикват при размотаване. `unique_ptr` освобождава паметта в своя деструктор — затова Rule of Zero е безопасен при изключения.

---

## 10. Изключения в деструктори

### Деструкторите НЕ трябва да хвърлят

В C++11 деструкторите са `noexcept(true)` по подразбиране. Хвърлянето от деструктор е **почти винаги бъг**.

### Защо е опасно — double exception → terminate


Когато се хвърля изключение, C++ размотава стека и извиква деструкторите на локалните обекти. Ако по време на това размотаване **деструктор хвърли ново изключение**, C++ не може да се справи с две изключения едновременно и извиква `std::terminate` — програмата се прекратява принудително:

```cpp
class Bad {
public:
    ~Bad() {
        throw std::runtime_error("От деструктора!");  // ❌ НИКОГА!
    }
};

int main() {
    try {
        Bad b;
        throw std::runtime_error("Първо изключение");
        // Stack unwinding: ~Bad() хвърля второ изключение
        // Системата е в нестабилно състояние:
        // 1) Кое изключение да оцелее?
        // 2) Няма механизъм за recovery
        // → std::terminate() → crash!
    }
    catch (...) {
        // Никога не се стига тук
    }
}
```

### Правилното поведение — улавяй вътре, логвай

```cpp
class Connection {
    bool isOpen = true;
public:
    void close() {
        if (!isOpen)
            throw std::runtime_error("Вече е затворено!");
        isOpen = false;
        std::cout << "Връзката е затворена\n";
    }

    ~Connection() noexcept {
        try {
            if (isOpen) close();
        }
        catch (const std::exception& e) {
            // Логваме, НО НЕ ХВЪРЛЯМЕ!
            std::cerr << "Грешка при затваряне: " << e.what() << "\n";
        }
    }
};
```

---

## 11. Нива на Exception Safety

**Exception safety** описва какво се случва с обектите при хвърлено изключение. Четири нива от най-лошо към най-добро.

### Ниво 1 — No Guarantee (Без гаранция) — ЛОШ ДИЗАЙН!

При изключение обектът е в **невалидно, неизползваемо** състояние. Инварианти са нарушени. Ресурсите могат да изтичат:

```cpp
// ❌ NO GUARANTEE
class MyArray {
    int* data;
    int  size;
public:
    MyArray& operator=(const MyArray& other) {
        delete[] data;                  // (1) изтриваме старото
        data = new int[other.size];     // (2) ако NEW хвърли тук →
                                        //     data е невалиден указател!
        size = other.size;
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];    // копираме елемент по елемент
        return *this;
    }
};
```

### Ниво 2 — Basic Guarantee (Основна гаранция)

При изключение обектът е в **валидно**, но може и **различно** от очакваното състояние. Ресурсите не изтичат:

```cpp
MyClass& operator=(const MyClass& other) {
    int* newData = new int[other.size];      // 1. Заделяме ново
                                              //    ако хвърли — *this е непроменен
   for (int i = 0; i < other.size; i++)
        newData[i] = other.data[i];          // копираме елемент по елемент

    delete[] data;                           // 2. Сега е безопасно да изтрием старото
    data = newData;
    size = other.size;
    return *this;
}
```

Ако `new` хвърли изключение, `*this` е непроменен — той е в същото, валидно състояние.


### Ниво 3 — Strong Guarantee (Силна гаранция) — Commit or Rollback

При изключение обектът е в **точно същото** състояние като преди операцията. Или всичко се случва, или нищо — **атомарност**.

Постига се чрез **Copy-and-Swap идиома**:

```cpp
// ✅ STRONG GUARANTEE — Copy-and-Swap идиомът
class MyArray {
    int* data;
    int  size;

    // swap е noexcept — не може да хвърли
    void swap(MyArray& other) noexcept {
        std::swap(data, other.data);
        std::swap(size, other.size);
    }

public:
    MyArray& operator=(const MyArray& other) {
        MyArray temp(other);   // (1) Правим копие в temp
                                //     Ако хвърли → *this е НЕПРОМЕНЕН!
        swap(temp);            // (2) Разменяме — noexcept, не може да хвърли
        return *this;
        // (3) temp (старото съдържание) се унищожава автоматично
    }
};
```
Стъпка по стъпка:
- Правим копие (`temp`) — ако `new` хвърли, `*this` изобщо не е бил докоснат
- Размяната (`swap`) е `noexcept` — гарантирано не хвърля
- Старите данни се унищожават автоматично чрез деструктора на `temp`

```cpp
// Пример
class IntCollection {
    std::vector<int> data;
public:
    void addTwo(int a, int b) {
        std::vector<int> temp = data;   // (1) Копие
        temp.push_back(a);
        temp.push_back(b);
        data.swap(temp);                // (2) Commit — noexcept
    }
    // Ако push_back хвърли → data е непроменен (Strong guarantee!)
};
```

### Ниво 4 — No-throw Guarantee (Без хвърляне)

Функцията **никога** не хвърля. Маркира се с `noexcept`:

```cpp
void swap(int& a, int& b) noexcept {
    int tmp = a;
    a = b;
    b = tmp;
}

~MyClass() noexcept { delete[] data; }  // деструкторите са noexcept по подразбиране
```

**Критично важно за:** деструктори, `swap`, move операции. Именно затова move операциите трябва да са `noexcept` — `std::vector` при реалокация ползва move само ако е `noexcept`, иначе copy:

```cpp
MyClass(MyClass&& other) noexcept : data(other.data) {
    other.data = nullptr;
    // noexcept → vector ще ползва move при реалокация (по-бързо)
}
```

### Обобщение на нивата

```
┌───────────────────────────────────────────────────────────────────┐
│ Ниво          │ Стоятието след изключение │ Постига се чрез       │
├───────────────────────────────────────────────────────────────────┤
│ No guarantee  │ Невалидно, leak          │ (избягвай!)            │
│ Basic         │ Валидно, може различно   │ Минимум при нов код    │
│ Strong        │ Същото като преди        │ Copy-and-Swap          │
│ No-throw      │ Никога не хвърля         │ noexcept               │
└───────────────────────────────────────────────────────────────────┘
```

---

## 12. `std::optional` (C++17)


### Идеята

Понякога функцията **може да не намери резултат** — и това не е грешка, а нормална ситуация. Например: търсим студент по ID и той просто не е в базата.

Преди C++17 решението беше специална стойност (`-1`, `nullptr`) или отделен bool параметър:

### Какво е?

`std::optional<T>` представя стойност, която **може да липсва**. Заменя `nullptr` проверки, магически стойности (`-1`), ръчни `bool hasValue` флагове:

```cpp
// Стар начин — неудобен
int findAge(const std::string& name, bool& found) {
    if (name == "Иван") { found = true; return 20; }
    found = false;
    return -1;   // специална стойност — лесно се бърка с истинска
}
```

`std::optional<T>` е по-елегантното решение:

```cpp
#include <optional>

std::optional<int> findAge(const std::string& name) {
    if (name == "Иван")  return 20;      // връщаме стойност
    if (name == "Мария") return 21;
    return std::nullopt;                  // не е намерено — не е грешка!
}
```

### Употреба

```cpp
auto result = findAge("Иван");

// Проверка и достъп
if (result.has_value())
    std::cout << "Възраст: " << result.value() << "\n";

// По-кратко с operator bool
if (result)
    std::cout << "Възраст: " << *result << "\n";

// Стойност по подразбиране ако е nullopt
int age = result.value_or(-1);   // -1 ако не е намерено
std::cout << age << "\n";        // 20 ако е Иван, -1 ако не е намерен

// При несъществуващо лице
auto missing = findAge("Петър");
std::cout << missing.value_or(0) << "\n";   // 0
```
### Достъп до полета с `->`

Когато `optional` съдържа обект, може да се достъпват полетата му директно с `->`:

```cpp
struct Student {
    std::string name;
    double      grade;
};

std::optional<Student> findStudent(const std::string& name) {
    if (name == "Иван") return Student{"Иван", 5.5};
    return std::nullopt;
}

auto s = findStudent("Иван");
if (s) {
    std::cout << s->name  << "\n";   // Иван
    std::cout << s->grade << "\n";   // 5.5
}
```


### Optional поле в клас — Rule of Zero

```cpp
class Student {
    std::string                name;
    std::optional<std::string> middleName;  // може да липсва
    std::optional<double>      scholarShip; // може да липсва

public:
    Student(std::string n,
            std::optional<std::string> m = std::nullopt,
            std::optional<double>      s = std::nullopt)
        : name(std::move(n)),
          middleName(std::move(m)),
          scholarShip(std::move(s)) {}

    void print() const {
        if (middleName)
            std::cout << name << " " << *middleName;
        else
            std::cout << name;

        if (scholarShip)
            std::cout << " (стипендия: " << *scholarShip << ")";

        std::cout << "\n";
    }

    // Rule of Zero — optional управлява паметта сам
    // Компилаторът генерира всички специални функции правилно
};

Student s1("Иван", "Петров", 500.0);
Student s2("Мария");

s1.print();   // Иван Петров (стипендия: 500)
s2.print();   // Мария
```

### Кога е подходящо

```
✅ Функция, която може да не намери резултат
✅ Optional полета в клас
✅ Lazy initialization
✅ Частично конструирани обекти

❌ Грешки с причина → използвай std::expected
❌ Колекции → използвай празен контейнер
❌ Ownership → използвай std::unique_ptr
```

---

## 13. `std::expected` (C++23)

### Идеята?

`std::expected<T, E>` съдържа **или** валидна стойност от тип `T`, **или** грешка от тип `E`. За разлика от `std::optional`, **носи информация защо** няма стойност.

Може да се мисли като: „Очаквам резултат, но ако не го получа — ето каква е грешката."

```cpp
#include <expected>

std::expected<int, std::string> divide(int a, int b) {
    if (b == 0)
        return std::unexpected("Деление на нула!");   // грешка с описание
    return a / b;                                      // успех
}

int main() {
    auto r1 = divide(10, 2);
    if (r1)
        std::cout << "Резултат: " << *r1 << "\n";     // 5

    auto r2 = divide(10, 0);
    if (!r2)
        std::cout << "Грешка: " << r2.error() << "\n"; // Деление на нула!

    // Стойност по подразбиране
    int val = r2.value_or(0);
}
```

### С `enum class` — типово безопасни грешки

```cpp
enum class ParseError { InvalidFormat, OutOfRange };

std::expected<int, ParseError> parseInteger(const std::string& s) {
    if (s.empty() || !std::isdigit(s[0]))
        return std::unexpected(ParseError::InvalidFormat);

    int value = 0;
    for (char c : s) {
        if (!std::isdigit(c))
            return std::unexpected(ParseError::InvalidFormat);
        value = value * 10 + (c - '0');
    }
    return value;
}

int main() {
    auto r1 = parseInteger("123");
    if (r1) std::cout << "Разобран: " << *r1 << "\n";  // 123

    auto r2 = parseInteger("abc");
    if (!r2) {
        switch (r2.error()) {
            case ParseError::InvalidFormat:
                std::cout << "Невалиден формат\n"; break;
            case ParseError::OutOfRange:
                std::cout << "Извън диапазон\n"; break;
        }
    }
}
```

### Методи на `std::expected`

```cpp
auto result = divide(10, 2);

result.value()      // стойността или хвърля std::bad_expected_access
result.error()      // грешката (само ако !result)
result.value_or(0)  // стойност или default
*result             // дереференциране — само ако result е true
if (result) { }     // operator bool — true ако съдържа стойност
```

### Сравнение на четирите подхода

```
┌──────────────────┬──────────┬──────────────────┬──────────────────┐
│ Подход           │ Overhead │ Носи информация  │ Може да се игн.  │
├──────────────────┼──────────┼──────────────────┼──────────────────┤
│ Error codes      │ Нула     │ Само код         │ Да ❌            │
│ Exceptions       │ При throw│ Клас с полета    │ Не ✅            │
│ std::optional    │ Нула     │ Само nullopt     │ Да ❌            │
│ std::expected    │ Нула     │ Тип E            │ Не ✅            │
└──────────────────┴──────────┴──────────────────┴──────────────────┘
```

---

## 14. Edge Cases и капани

### Хвърляне от деструктор → `std::terminate`

```cpp
class Bad {
public:
    ~Bad() {                     
        throw std::runtime_error("От ~Bad!");    // ❌ НИКОГА при unwinding!
    }
};
// При stack unwinding → двойно изключение → terminate() → crash
```

---

### Грешен ред на catch — мъртъв код

```cpp
// ❌ std::exception хваща всичко — invalid_argument никога не се достига:
catch (const std::exception& e)        { ... }
catch (const std::invalid_argument& e) { ... }  // мъртъв код!

// ✅ От специфично към общо:
catch (const std::invalid_argument& e) { ... }
catch (const std::exception& e)        { ... }
```

---

### `throw e` vs `throw;` — загуба на тип (slicing)

```cpp
catch (const std::exception& e) {
    throw e;    // ❌ хвърля КОПИЕ от тип std::exception — типът се губи!
    throw;      // ✅ хвърля оригиналния обект с оригиналния тип
}
```

---

### Хващане по стойност — slicing

```cpp
catch (std::exception e)        // ❌ slicing — губи полиморфизма
catch (const std::exception& e) // ✅ без slicing
```

---

### `std::optional` — достъп без проверка

```cpp
std::optional<int> opt = std::nullopt;

opt.value();  // ❌ хвърля std::bad_optional_access!
*opt;         // ❌ undefined behavior

// ✅ Винаги проверявай:
if (opt) std::cout << *opt;
std::cout << opt.value_or(0);
```

---

### Изтичане при изключение в конструктор — Rule of Zero е решението

```cpp
// ❌ Ръчна памет — деструкторът не се извиква при изключение!
class Dangerous {
    int* a = nullptr;
    int* b = nullptr;
public:
    Dangerous() {
        a = new int[100];
        b = new int[200];
        throw std::runtime_error("!");  // ~Dangerous() не се извиква → leak!
    }
    ~Dangerous() { delete[] a; delete[] b; }
};

// ✅ Rule of Zero — unique_ptr се унищожава автоматично:
class Safe {
    std::unique_ptr<int[]> a = std::make_unique<int[]>(100);
    std::unique_ptr<int[]> b = std::make_unique<int[]>(200);
public:
    Safe() {
        throw std::runtime_error("!");  // a и b се унищожават автоматично!
    }
};
```

---

### `catch (...)` не хваща системни грешки

```cpp
try {
    int* p = nullptr;
    *p = 5;         // Segmentation Fault — сигнал от OS-а
}
catch (...) { }    // ❌ НЕ хваща! catch(...) хваща само C++ throw exceptions.
```

`catch (...)` хваща само **хвърлени C++ изключения**. Segfault, stack overflow, деление на нула в C — сигнали от операционната система, не C++ изключения.

---

### No-throw без `noexcept` — пропусната оптимизация

```cpp
// ❌ Без noexcept — vector ползва copy при реалокация (по-бавно):
MyClass(MyClass&& other) : data(other.data) {
    other.data = nullptr;
}

// ✅ С noexcept — vector ползва move при реалокация (по-бързо):
MyClass(MyClass&& other) noexcept : data(other.data) {
    other.data = nullptr;
}
```

---

## 15. Обобщение

### Четирите нива на exception safety

```
No guarantee  → невалидно след изключение      (НИКОГА!)
Basic         → валидно, но може различно      (минимум)
Strong        → същото като преди              (copy-and-swap)
No-throw      → никога не хвърля              (noexcept)
```

### Кога се използва кое

```
Конструктор не може да конструира валиден обект → exception (задължително)
Деструктор                                       → noexcept, логвай вътре
Липсваща стойност, не е грешка                  → std::optional
Очаквана грешка с информация, без overhead       → std::expected
Изключителна, непредвидима ситуация              → exception
Embedded / real-time системи                     → error codes
```

### Структура на собствен exception клас

```cpp
class MyException : public std::exception {
    std::string message;
    int         code;
public:
    MyException(const std::string& msg, int code)
        : message(msg), code(code) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    int getCode() const { return code; }
};
```


### Правила

```
✅ Хвърляй обекти наследяващи std::exception
✅ Хващай по const референция: catch (const MyEx& e)
✅ Ред на catch — от специфично към общо
✅ Деструкторите са noexcept — никога не хвърляй от тях
✅ При повторно хвърляне — throw; (без аргумент, без загуба на тип)
✅ В конструктори — хвърляй при невалидно, несъществуващо обект
✅ Rule of Zero: unique_ptr вместо ръчен new — безопасен при изключения
✅ Move операциите трябва да са noexcept (оптимизация на vector)
✅ Strong guarantee чрез copy-and-swap идиома

❌ throw от деструктор по време на unwinding → std::terminate
❌ throw e в catch → slicing, губи типа — ползвай throw;
❌ catch(std::exception) преди catch(invalid_argument) → мъртъв код
❌ Хващане по стойност → slicing
❌ *optional без проверка → UB или bad_optional_access
❌ catch(...) не хваща Segfault, stack overflow, системни сигнали
❌ Пропускане на noexcept при move → vector копира вместо да мести
```

> **Основен извод:** Обработката на грешки е задължителна за всяка реална програма. Конструкторите съобщават за грешки само чрез изключения. Деструкторите никога не трябва да хвърлят. `std::optional` и `std::expected` са съвременните инструменти за функции, чийто неуспех е очакван и нормален
