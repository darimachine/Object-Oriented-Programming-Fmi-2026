# SOLID принципи
## 5 принципа за добър код

SOLID принципите целят да направят обектно-ориентирания код по-лесен за поддръжка, разширяване и тестване, но също така могат да имат и обратния ефект, ако се прилагат винаги, без да се замисляме дали реално решават някакъв проблем.

---

### S - Single responsibility
Един клас трябва да има **точно една** отговорност/причина да се променя.

#### Лош пример:
```c++
struct Circle {
    double radius;
    double area() const { return 3.14159 * radius * radius; }

    // Лошо: Кръгът няма причина да знае как се сериализира.
    //       Ами ако решим, че искаме да променим формата?
    string toJson() const {
        return "{\"type\":\"circle\",\"radius\":" + std::to_string(radius) + "}";
    }
};
```

#### Добър пример:
```c++
struct Circle {
    double radius;
    double area() const { return 3.14159 * radius * radius; }
};

// Отделен клас, който има само една причина да се променя.
struct JSONSerializer {
    string toJson(const Circle& c) const {
        return "{\"area\":" + std::to_string(c.area()) + "}";
    }
};

// Можем да създадем и други класове за различни формати на сериализация.
struct XMLSerializer {
    string toXml(const Circle& c) const {
        // ...
    }
};
```

---

### O - open(for extension)-closed(for modification)
Добавянето на нова функционалност трябва да се случва чрез писане на нов код, а не чрез променяне на съществуващия.

#### Лош пример:
```c++
enum struct ShapeType { Circle, Rectangle };

struct Shape {
    ShapeType type;
    double a, b; // радиус или ширина+дължина, зависещи от типа

    double area() const {
        switch (type) {
            case ShapeType::Circle:    return 3.14159 * a * a;
            case ShapeType::Rectangle: return a * b;
            // Ще трябва да променяме тази функция всеки път,
            // когато искаме да добавим нов тип фигура.
            default:                   return -1;
        }
    }
};
```

#### Добър пример:
```c++
struct IShape {
    virtual double area()   const = 0;
    virtual ~IShape() = default;
};

struct Circle : public IShape {
    double radius;
    double area() const override { return 3.14159 * radius * radius; }
};

struct Rectangle : public IShape {
    double width, height;
    double area() const override { return width * height; }
};

// Искаме да добавим нова фигура -> създаваме нов клас, без да пипаме старите
struct Triangle : public IShape {
    double base, height;
    double area() const override { return 0.5 * base * height; }
};
```

---

### L - Liskov substitution
Обектите от клас-родител трябва да могат да се заменят с който и да е техен наследник, без това да чупи логиката на програмата.

#### Лош пример:
```c++
struct Rectangle {
    double width, height;
    virtual void setWidth(double w)  { width  = w; }
    virtual void setHeight(double h) { height = h; }
    double area() const { return width * height; }
};

struct Square : public Rectangle {
    // Лошо: очаква се, че правоъгълник ще има различни(независими) ширина и дължина
    void setWidth(double w)  override { width = height = w; }
    void setHeight(double h) override { width = height = h; }
};

void test(Rectangle& r) {
    r.setWidth(4);
    r.setHeight(5);
    // очаква се 20(4х5), но се получава 25(5х5)
    // класът Rectangle НЕ се замества правилно от своя наследник Square
    assert(r.area() == 20);
}
```

#### Добър пример:
```c++
struct IShape {
    virtual double area() const = 0;
    virtual ~IShape() = default;
};

struct Rectangle : IShape {
    double width, height;
    void setWidth(double width) { this->width = width; }
    void setHeight(double height) { this->height = height; }
    double area() const override { return width * height; }
};

// Square is-NOT a Rectangle — различна фигура е
struct Square : IShape {
    double side;
    void setSide(double side) { this->side = side; }
    double area() const override { return side * side; }
};

void printArea(const IShape& s) {
    // работи правилно за всеки наследник
    std::cout << s.area() << "\n";
}
```

---

### I - Interface segregation
За предпочитане е да се ползват малки, конкретни интерфейси вместо "обемни", които биха наложили имплементирането на поведение, което даден клас реално не поддържа.

#### Лош пример:
```c++
struct IOfficeMachine {
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

struct Printer : IOfficeMachine {
    virtual void print() override { /* printing logic... */ }
    virtual void scan() override { /* scanning logic... */ }
    virtual void fax() override { 
        // Принтерът може само да принтира и да сканира,
        // затова тук хвърля изключение, което обаче би
        // могло да счупи програмата, понеже се очаква,
        // че щом класът имплементира интерфейса IOfficeMachine,
        // значи имплементира цялото поведение.
        throw "Not implemented";
    }
};

struct Fax : IOfficeMachine {
    virtual void print() override { throw "Not implemented"; }
    virtual void scan() override { throw "Not implemented"; } // същият проблем
    virtual void fax() override { /* faxing logic... */ }
};
```

#### Добър пример:
```c++
struct IPrint {
    virtual void print() = 0;
    virtual ~IPrint() = default;
};

struct IScan {
    virtual void scan() = 0;
    virtual ~IScan() = default;
};

struct IFax {
    virtual void fax() = 0;
    virtual ~IFax() = default;
};

// Сега Printer и Fax имплементират само поведението, което искат
struct Printer : IPrint, IScan {
    virtual void print() override { /* printing logic... */ }
    virtual void scan() override { /* scanning logic... */ }
};

struct Fax : IFax {
    virtual void fax() { /* faxing logic... */ }
};
```

---

### D - Dependency inversion
Бизнес логиката на приложението не трябва да зависи от конкретни имплементации, а от абстракции.

#### Лош пример:
```c++
struct Client {
    ShoppingCart cart;
    Paypal paypal;

    void pay() {
        // Ами ако искаме клиентът да плати по друг начин?
        paypal.pay();
    }
};
```

#### Добър пример:
```c++
struct PaymentService {
    virtual void pay() = 0;
};

struct Paypal : public PaymentService {
    virtual void pay() override { /* ... */ }
};

struct Card : public PaymentService {
    virtual void pay() override { /* ... */ }
};

struct Client {
    ShoppingCart cart;
    PaymentService* paymentService;

    Client(PaymentService* paymentService) : paymentService(paymentService) { }

    void pay() {
        // Клиентът вече може да плаща по всеки един от възможните начини.
        paymentService->pay();
    }
};
```
