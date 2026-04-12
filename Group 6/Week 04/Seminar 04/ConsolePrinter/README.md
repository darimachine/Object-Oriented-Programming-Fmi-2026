# LIVE CODING:

## Задача: ConsolePrinter и Wrapper класове

Реализирайте клас `ConsolePrinter`, който отпечатва низове в конзолата. Той трябва да поддържа **предикатна функция**, която определя кои символи да бъдат цензурирани (заменяни със `*`).

Създайте два допълнителни класа, които поддържат **динамична смяна на принтера** (напр. чрез метод `setPrinter`):
- **`NumberWrapper`** – работи с цяло число и използва `ConsolePrinter` за отпечатване.
- **`StringWrapper`** – работи с низ и използва `ConsolePrinter` за отпечатване.

Добавете пространство от имена `Predicates`, в което да реализирате функции за комбиниране на правила: `combineOr(a, b)` (връща истина, ако поне едното е вярно) и `negate(a)` (обръща правилото).

## Пример:
### Вход:
```cpp
auto removeVowels = [](char ch) { 
    char c = tolower(ch); 
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
};
auto removeDigits = [](char ch) { 
    return ch >= '0' && ch <= '9'; 
};

ConsolePrinter vowelPrinter(removeVowels);
ConsolePrinter digitPrinter(removeDigits);

StringWrapper word("Apple123", vowelPrinter);
word.println(); 

// Сменяме принтера динамично!
word.setConsolePrinter(digitPrinter);
word.println(); 

// Комбинираме предикати
auto noVowelsOrDigits = Predicates::combineOr(removeVowels, removeDigits);
ConsolePrinter ultraPrinter(noVowelsOrDigits);

StringWrapper password("MyPass12", ultraPrinter);
password.println();
```
### Изход:
```
*ppl*123
Apple***
M*P*ss**
```

## Изисквания
- ConsolePrinter използва std::function<bool(char)> за предикатната функция.

- NumberWrapper и StringWrapper използват агрегация – не създават нов ConsolePrinter, а използват подаден като параметър.

- Използвайте lambda функции при създаването и комбинирането на предикатите.
