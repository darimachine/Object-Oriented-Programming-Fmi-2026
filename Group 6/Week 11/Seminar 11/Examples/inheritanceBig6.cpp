#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base()" << std::endl;
    }

    Base(const Base& other) {
        std::cout << "Base(const Base&)" << std::endl;
        copyFrom(other);
    }

    Base& operator=(const Base& other) {
        std::cout << "operator=(const Base&)" << std::endl;
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    Base(Base&& other) noexcept {
        std::cout << "Base(Base&&)" << std::endl;
        moveFrom(std::move(other));
    }

    Base& operator=(Base&& other) noexcept {
        std::cout << "operator=(Base&&)" << std::endl;
        if (this != &other) {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    ~Base() {
        std::cout << "~Base()" << std::endl;
        free();
    }
private:
    // char* or int* or some dynamic memory

    void free() {
        //...
    }

    void copyFrom(const Base& other) {
        // ...
    }

    void moveFrom(Base&& other) noexcept {
        // ...
    }
};

class Der : public Base {
public:
    Der() {
        std::cout << "Der()" << std::endl;
    }

    Der(const Der& other) : Base(other) /* copies only Base members */ {
        std::cout << "Der(const Der&)" << std::endl;
        copyFrom(other); // copies only Der members
    }

    Der& operator=(const Der& other) {
        std::cout << "operator=(const Der&)" << std::endl;
        if (this != &other) {
            Base::operator=(other); // copies only base members
            free(); // frees only der members
            copyFrom(other); // copies only der members
        }
        return *this;
    }

    Der(Der&& other) noexcept : Base(std::move(other)) /* moves only Base members*/ {
        std::cout << "Der(Der&&)" << std::endl;
        moveFrom(std::move(other)); // moves Der members
    }

    Der& operator=(Der&& other) noexcept {
        std::cout << "operator=(Der&&)" << std::endl;
        if (this != &other) {
            Base::operator=(std::move(other)); // moves only Base members
            free(); // frees only Der members
            moveFrom(std::move(other)); // moves only Der members
        }
        return *this;
    }

    ~Der() {
        std::cout << "~Der()" << std::endl;
        free();
    }

private:
    // dynamic memory

    void free() {
        // ...
    }

    void copyFrom(const Der& other) {
        // ...
    }

    void moveFrom(Der&& other) noexcept {
        // ...
    }
};

int main() {
    {
        Der d; // Base() Der()
        Der d2 = d; // Base(const Base&) Der(const Der&)
        Der d3; // Base() Der()
        d3 = d; // operator=(const Der&) operator=(const Base&) , here the order depends on where you print
    } // ~Der() ~Base() ~Der() ~Base() ~Der() ~Base()

    {
        Der d; // Base() Der()
        Der d2 = std::move(d); // Base(Base&&) Der(Der&&)
        Der d3; // Base() Der()
        d3 = std::move(d); // operator=(Der&&) operator=(Base&&) , here the order depends on where you print
    } // ~Der() ~Base() ~Der() ~Base() ~Der() ~Base()
}
