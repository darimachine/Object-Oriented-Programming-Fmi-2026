# Семинар 12

На лекции 12 е взимано:
- Изключения.
- Обработка на изключения.
- Йерархия на изключенията и примери.
- Изключения в конструктори и деструктори.
- Нива на exception safety.
- std::expected(C++23)
- std::optional(C++17)

---

## Задачи

1. Създайте проста система за банкова сметка (`BankAccount`). Класът трябва да се напише по всеки от 4те начина, описано по-долу. Също така трябва да поддържа следните операции:
  - Конструктор, който приема `std::string owner` и `double initialBalance`.
  - `deposit(double amount)` – добавя сума (трябва да е положителна).
  - `withdraw(double amount)` – тегли сума (трябва да има достатъчно средства и сумата да е положителна).
  - `getBalance() const` – връща текущия баланс.
  - `getOwner() const` – връща името на собственика.
  - `transfer(BankAccount& to, double amount)` – прехвърля сума към друга сметка.

Валидации / грешки, които трябва да се обработват:
  - Празно име на собственик.
  - Отрицателен начален баланс.
  - Отрицателна или нулева сума при deposit/withdraw/transfer.
  - Опит за теглене/прехвърляне на сума, по-голяма от баланса.

1.1. Решаване на задачата само с **error codes** (без exceptions, без std::optional/std::expected). Изисквания:
  - Функциите връщат `enum class ErrorCode { Success, InvalidOwner, NegativeAmount, InsufficientFunds, ... };`
  - `deposit`, `withdraw`, `transfer` връщат `ErrorCode`.
  - Конструкторът не може да хвърля – вместо това може да има статичен фабричен метод `static std::pair<BankAccount, ErrorCode> create(...)` или конструкторът да оставя обекта в "invalid" състояние + метод `isValid()` / `getLastError()`.

1.2. Решаване на задачата само с **exceptions + custom exception**. Изисквания:
  - Създайте собствен клас `BankAccountException`, наследник на `std::runtime_error`, който има единствен не-конвертиращ конструктор, приемащ съобщение
  - Конструкторът на `BankAccount` хвърля грещка от тип `BankAccountException` при невалидни данни.
  - Методите `deposit`, `withdraw`, `transfer` хвърлят `BankAccountException` при проблем.

1.3. Решаване на задачата с **std::expected**. Изисквания:
  - Дефинирайте `enum class BankError { ... };`
  - `deposit`, `withdraw`, `transfer` връщат `std::expected<void, BankError>` (или `std::expected<double, BankError>` за операциите, които връщат нов баланс).

1.4. Решаване на задачата с **std::optional**. Изисквания:
  - Добавете `std::optional<std::string> middleName` и `std::optional<double> overdraftLimit` като полета в `BankAccount`.
  - Създайте следните функции:
    - `std::optional<BankAccount> findAccountByOwner(const std::vector<BankAccount>& accounts, const std::string& owner);`
    - `std::optional<double> tryWithdraw(BankAccount& acc, double amount);` – връща новия баланс при успех, `nullopt` при грешка.
    - `std::optional<std::string> getMiddleName(const Student& s);`
