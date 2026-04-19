#include <iostream>

class A {
    int n = 0;

public:
    A() {
        std::cout << "A()" << std::endl;
    }

    explicit A(int n) : n(n) {
        std::cout << "A(int)" << std::endl;
    }

    int getN() const {
        return n;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

int main() {
    {
        A array[5]; // A() A() A() A() A()
        for (int i = 0; i < 5; i++) {
            std::cout << array[i].getN() << ' '; // 0 0 0 0 0 (no empty A's, all are initialized with n=0)
        }
    } // ~A() ~A() ~A() ~A() ~A()

    {
        A* arrOfPointers[5] {nullptr}; // no constructors called yet, pointers are set to nullptr
        // we can call whichever constructor we want to
        arrOfPointers[0] = new A(); // A()
        arrOfPointers[2] = new A(24); // A(int)
        // the rest are nullptr
        for (int i = 0; i < 5; i++) {
            if (arrOfPointers[i]) {
                std::cout << arrOfPointers[i]->getN() << ' ';
            } else {
                std::cout << "nullptr "; // in array of pointers we can have empty (nullptr) positions
            }
        } // 0 nullptr 24 nullptr nullptr

        // we need to delete each of the elements in the array, since they point to dynamically allocated A objects in heap
        for (int i = 0; i < 5; i++) {
            delete arrOfPointers[i]; // ~A() x5
        }
        // no need to delete[]
    }

    {
        A* dynamicArr = new A[5]; // A() A() A() A() A()
        for (int i = 0; i < 5; i++) {
            std::cout << dynamicArr[i].getN() << ' '; // // 0 0 0 0 0 (no empty A's, all are initialized with n=0)
        }
        delete[] dynamicArr; // ~A() ~A() ~A() ~A() ~A()
    }

    {
        A** dynamicArrayOfPointers = new A*[5] {nullptr}; // nothing is called, pointers are set to nullptr
        // we can call whichever constructor we want to
        dynamicArrayOfPointers[1] = new A(7); // A(int)
        dynamicArrayOfPointers[2] = new A(8); // A(int)
        dynamicArrayOfPointers[4] = new A(); // A()
        for (int i = 0; i < 5; i++) {
            if (dynamicArrayOfPointers[i]) {
                std::cout << dynamicArrayOfPointers[i]->getN() << ' ';
            }
            std::cout << "nullptr ";
        }

        // for the deletion, since the pointers point to dynamically allocated A's, we need to delete each of them
        for (int i = 0; i < 5; i++) {
            delete dynamicArrayOfPointers[i]; // ~A() x5
        }
        // then we delete the array of pointers
        delete[] dynamicArrayOfPointers;
    }
}
