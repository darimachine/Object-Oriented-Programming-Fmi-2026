#include <iostream>

using std::cout;
using std::endl;

class Heart {
private:
    int bpm;

public:
    Heart(int bpm = 70) : bpm(bpm) {
        cout << "Heart(" << bpm << ")" << endl;
    }

    void print() const {
        cout << "Heart bpm: " << bpm << '\n';
    }

    ~Heart() {
        cout << "~Heart()" << endl;
    }
};

class Human {
private:
    int age;
    Heart heart; // composition: а Human "owns" a heart and is responsible for its lifecycle
    // ...

public:
    Human(int age, int bpm) : age(age), heart(bpm) {
        cout << "Human()" << endl;
    }

    void print() const {
        cout << "Human age: " << age << '\n';
        heart.print();
    }

    ~Human() {
        cout << "~Human()" << endl;
    }
};

int main() {
    Human h(25, 72); //~Heart(72) ~Human()
    h.print();
} // ~Human() ~Heart()
