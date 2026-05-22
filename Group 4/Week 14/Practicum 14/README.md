## Задача Cartographer

---

### Cartographer

Представлява картограф, участвал в създаването на карта. Съдържа:
- `name`
- `yearsExperience`

Задължителни виртуални методи:
- `string getRole() const`
- `print() const`

Конкретни наследници:

| Клас | Допълнителни полета |
|---|---|
| `FieldSurveyor` | `string region` - регионът, в който специализира |
| `Archivist` | `string institution` - институцията, към която принадлежи |
| `ExpeditionLeader` | `int expeditionsLed` - брой ръководени експедиции |

Един и същи картограф може да е допринесъл за множество карти.

---

### Landmark

Представлява забележителност върху карта. Съдържа:
- `name` - име
- `coords` - координати (`Coords { double x, y }`)
- `threat` - ниво на заплаха (0–10); при невалидна стойност се хвърля `std::invalid_argument`

Задължителни виртуални методи:
- `string getType() const`
- `print() const`

Конкретни наследници:

| Клас | Допълнителни полета |
|---|---|
| `Settlement` | `int population` |
| `Dungeon` | `int depth` (брой етажи) |
| `NaturalFeature` | `FeatureKind kind` (enum class) |
| `Ruin` | `string civilization` |

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

Притежава `vector<unique_ptr<Landmark>> landmarks`. Две различни територии **не** споделят забележителности.

Основни методи:
- `addLandmark(unique_ptr<Landmark>)`
- `unique_ptr<Landmark> removeLandmark(const std::string& name)` - връща извадената забележителност; хвърля `std::invalid_argument`, ако не е намерена
- `setDangerLevel(int)` - ниво 1–10; хвърля `std::invalid_argument`, ако е невалидно
- `bool hasLandmark(const std::string& name) const`
- `print() const`

---

### Command

```cpp
Command                   (абстрактен)
├── AddLandmarkCommand
├── RemoveLandmarkCommand
└── SetDangerLevelCommand
```

Всяка команда има `Territory&` за контекст и реализира:
- `execute()`
- `undo()`
- `string description() const`

---

### CommandFactory

```cpp
static std::unique_ptr<Command> create(
    const std::string& type, // "add" | "remove" | "danger"
    const std::string& args, // зависи от типа
    Territory& target
);
```

При непознат тип се хвърля `std::invalid_argument`. `"add"` делегира парсването на аргументите на `LandmarkFactory`.

---

### Map

Картата или **споделя** територия с други карти (`shared_ptr<Territory>`, `use_count > 1`), или **притежава** собствено копие (`use_count == 1`).

Освен територия, всяка карта пази списък от картографи: `vector<shared_ptr<Cartographer>>`.

`Map` управлява историята на редакциите си.

При копиране на `Map`, новият започва с празна история на редакциите.

Методи:
- `unlink()` - ако картата е свързана (`use_count > 1`), прави ново независимо копие, в което историята се занулява, а картографите остават споделени.
- `addCartographer(shared_ptr<Cartographer>)`
- `execute(unique_ptr<Command>)` - изпълнява командата и я добавя в историята
- `undo()` - отменя последната команда
- `printHistory() const`
- `getTerritory()`, `isLinked()`, `useCount()`, `print()`

---

### Curator

Управлява колекция от карти `vector<unique_ptr<Map>> maps`.

Методи:
- `Map& addLinkedMap(title, shared_ptr<Territory>)`
- `Map& addIndependentMap(title, Territory)`
- `Map& copyAsIndependent(sourceTitle, newTitle)` - създава независимо копие на картата с име `sourceTitle` и го променя на `newTitle`, вмъква копието в `maps` и връща референция към него
- `Map& getMap(title)`
- `listMaps() const`

---

## Изисквания към `main()`

Демонстрирайте следната последователност:

1. Създайте няколко `Cartographer` обекта като `shared_ptr`.
2. Създайте споделена `Territory` "The Ashfields" с две забележителности и прикачете картографи към картите.
3. Добавете две **свързани** карти - `"Northern Survey"` и `"Southern Survey"`.
4. Добавете забележителност чрез `"Northern Survey"`. Покажете, че `"Southern Survey"` я вижда.
5. **Shallow копиране:** копирайте `"Northern Survey"` като `Map copy = north`. Покажете, че `use_count` на територията е нараснал, картографите са същите обекти, и промяна в данните е видима от всички копия.
6. **Deep копиране:** създайте независима карта `"Expedition Copy"` чрез `copyAsIndependent`. Покажете, че `use_count` на територията не се е променил, но картографите все още са споделени (`use_count` на картограф е нараснал).
7. Добавете забележителност към `"Expedition Copy"`. Покажете, че `"Northern Survey"` **не** я вижда.
8. Отменете последната промяна върху `"Expedition Copy"`. Потвърдете, че забележителността е изчезнала.
9. Извикайте `unlink()` върху `"Northern Survey"`. Отпечатайте `use_count` на територията преди и след, и потвърдете, че картографите са непроменени.
