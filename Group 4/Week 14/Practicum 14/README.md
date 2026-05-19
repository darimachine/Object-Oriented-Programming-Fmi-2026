## Задача Cartographer

---

### Landmark

Представлява забележителност върху карта. Съдържа:
- `name` - име
- `coords` - координати (`Coords { float x, y }`)
- `threat` - ниво на заплаха (0–10); при невалидна стойност се хвърля `std::invalid_argument`

Задължителни виртуални методи:
- `getType() const → std::string`
- `print() const`
- `clone() const → std::unique_ptr<Landmark>` - полиморфно клониране

Конкретни наследници:

Клас - Допълнителни полета:
- `Settlement` - `int population`
- `Dungeon` - `int depth` (брой етажи)
- `NaturalFeature` - `FeatureKind kind` (enum class)
- `Ruin` - `string civilization`

`FeatureKind` е `enum class` с членове: `Volcano, Forest, Lake, Bog, Mountain, Desert`.

---

### LandmarkFactory

Статичен метод:

```cpp
static std::unique_ptr<Landmark> create(
    const std::string& type,   // "settlement" | "dungeon" | "ruin" | "natural"
    const std::string& name,
    Coords coords,
    int threat,
    const std::string& extra = "" // population (int str) / depth (int str) / civilization / FeatureKind name
);
```

При непознат тип се хвърля `std::invalid_argument`.

---

### Territory

Притежава `vector<unique_ptr<Landmark>> landmarks`.

**Копирането е дълбоко копие** - всяка забележителност се клонира полиморфно чрез `clone()`. Двa независими `Territory` обекта не споделят памет.

Основни методи:
- `addLandmark(unique_ptr<Landmark>)`
- `unique_ptr<Landmark> removeLandmark(const std::string& name)` - връща извадената забележителност; хвърля `std::invalid_argument`, ако не е намерена
- `setDangerLevel(int)` - ниво 1–10; хвърля `std::out_of_range`, ако е невалидно
- `bool hasLandmark(const std::string& name) const`
- `print() const`

---

### Command и EditLog

Всяка промяна на `Territory` минава през команда.

```cpp
Command                   (абстрактен)
├── AddLandmarkCommand
├── RemoveLandmarkCommand
└── SetDangerLevelCommand
```

Всяка команда реализира:
- `execute(Territory&)`
- `undo(Territory&)`
- `string description() const`

`EditLog` пази история от команди и препратка към целевата `Territory`. Методи: `execute(unique_ptr<Command>)`, `undo()`, `printHistory()`.

**Важно:** ако две карти споделят `Territory`, техните `EditLog` обекти сочат към един и същи обект - `execute()` през едната е видимо от другата.

---

### Map

Картата или **споделя** територия с други карти (`shared_ptr<Territory>`, `use_count > 1`), или **притежава** собствено копие (`use_count == 1`).

**Семантика на копиране и преместване:**

Операция - Поведение:
- `Copy` - Дълбоко копие -> независима карта, нова територия, нов празен лог
- `Move` - `= default` - `Territory` остава на същия адрес в heap-а, логът остава валиден

Метод `unlink()`: ако картата е свързана (`use_count > 1`), прави дълбоко копие на територията и пренасочва лога към новия обект. Ако вече е независима - no-op.

Методи: `getTerritory()`, `getLog()`, `isLinked()`, `useCount()`, `print()`.

---

### Curator

Управлява колекция от карти `vector<unique_ptr<Map>>`.

Методи:
- `Map& addLinkedMap(title, shared_ptr<Territory>)`
- `Map& addIndependentMap(title, Territory)`
- `Map& copyAsIndependent(sourceTitle, newTitle)` - използва copy конструктора на `Map`
- `Map& get(title)`
- `listMaps() const`

---

## Изисквания към `main()`

Демонстрирайте следната последователност:

1. Създайте споделена `Territory` "The Ashfields" с две забележителности.
2. Добавете две **свързани** карти към нея - `"Northern Survey"` и `"Southern Survey"`.
3. Добавете забележителност чрез лога на `"Northern Survey"`. Покажете, че `"Southern Survey"` я вижда.
4. Копирайте `"Northern Survey"` като независима карта `"Expedition Copy"`. Отпечатайте `use_count` преди и след.
5. Добавете забележителност към `"Expedition Copy"`. Покажете, че `"Northern Survey"` **не** я вижда.
6. Отменете последната промяна върху `"Expedition Copy"`. Потвърдете, че забележителността е изчезнала.
7. Извикайте `unlink()` върху `"Northern Survey"`. Отпечатайте `use_count` преди и след.
