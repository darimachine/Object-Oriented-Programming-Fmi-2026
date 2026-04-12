enum Color {
    red, blue, orange
};

enum Fruit {
    apple,
    orange // compile-time error: 'orange': redefinition, previous definition was 'enumerator',
           // because unscoped enums fields are treated as global variables
};

enum class ScopedColor {
    red, blue, orange
};

enum class ScopedFruit {
    apple, orange // no problem here, because scoped enum fields are treated as local variables
};

enum Animal {
    dog, cat
};

enum class ScopedAnimal {
    dog, cat
};

int main() {

    Animal cat = Animal::cat;
    Color blue = Color::blue;

    if (cat == blue) {
        // this will pass, because unscoped enums values implicitly convert to int,
        // and they are both equal to 1
        // which makes no sense, because a cat is not the color blue ?!
    }

    ScopedAnimal scopedCat = ScopedAnimal::cat;
    ScopedColor scopedBlue = ScopedColor::blue;

    /*
    if (scopedCat == scopedBlue) {
        // compile-time error, because it does not allow us to compare two different types of scoped enums like that
        // which is the correct behaviour in this case
    }
    */

    int x = Color::orange;
    // int y = ScopedColor::orange; // won't compile, because scoped enum values don't get implicitly converted to int
    int z = (int)ScopedColor::orange; // this works, we need to explicitly cast
}