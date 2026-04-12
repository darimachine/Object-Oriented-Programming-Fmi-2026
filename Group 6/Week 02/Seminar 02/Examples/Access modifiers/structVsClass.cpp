// structs have public access by default
struct ExampleStruct {
    int x;
    int y;
};

// classes have private access by default
class ExampleClass {
    int x;
    int y;
};

int main() {
    ExampleStruct s;
    ExampleClass c;

    s.x = 5;
    c.x = 5; // Error: ExampleClass::x is private

    return 0;
}
