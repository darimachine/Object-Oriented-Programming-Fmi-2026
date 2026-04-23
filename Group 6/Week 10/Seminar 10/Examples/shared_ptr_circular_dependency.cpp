#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string name;

    /*  
        if we use shared_ptr for both, we get a circular reference and the objects will never be destroyed
        because each one holds a shared_ptr to the other,
        so the reference count will never reach zero 
    */
        
    // std::shared_ptr<Person> partner; // owning reference - this will cause a memory leak due to circular reference

    // Therefore we can use weak_ptr to break the circular reference
    std::weak_ptr<Person> partner; // non-owning reference


    Person(std::string n) : name(std::move(n)) {
        std::cout << "Person created: " << name << '\n';
    }

    ~Person() {
        std::cout << "Person destroyed: " << name << '\n';
    }
};

int main() {
    auto alice = std::make_shared<Person>("Alice");
    auto bob = std::make_shared<Person>("Bob");

    alice->partner = bob;
    bob->partner = alice;

    std::cout << "alice.use_count = " << alice.use_count() << '\n';
    std::cout << "bob.use_count = " << bob.use_count() << '\n';
}
