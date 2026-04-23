#include <iostream>
#include <memory>
#include <string>

class User {
private:
    std::string name;

public:
    User(const std::string& n) : name(n) {
        std::cout << "User " << name << " created" << std::endl;
    }

    User(std::string&& n) : name(std::move(n)) {
        std::cout << "User " << name << " created" << std::endl;
    }

    ~User() {
        std::cout << "User " << name << " destroyed" << std::endl;
    }

    const std::string& getName() const { return name; }
};

// 1) Function that only uses the object, without taking ownership
void printUser(const std::unique_ptr<User>& user) {
    if (user) {
        std::cout << "printUser: " << user->getName() << '\n';
    }
}

// 2) Also without ownership - raw pointer version
void printUserRaw(const User* user) {
    if (user) {
        std::cout << "printUserRaw: " << user->getName() << '\n';
    }
}

// 3) Function that takes ownership
void consumeUser(std::unique_ptr<User>&& user) {
    if (user) {
        std::cout << "consumeUser took ownership of: " << user->getName() << '\n';
    }
    // user is destroyed here at the end of the function
}

int main() {
    std::unique_ptr<User> p1 = std::make_unique<User>("Alice");

    // unique_ptr cannot be copied:
    // std::unique_ptr<User> p2 = p1;

    // But it can be moved:
    std::unique_ptr<User> p2 = std::move(p1);

    std::cout << "p1 is " << (p1 ? "not null" : "null") << '\n';
    std::cout << "p2 is " << (p2 ? "not null" : "null") << '\n';

    // Pass without transferring ownership:
    printUser(p2);
    printUserRaw(p2.get());
    
    // Pass with ownership transfer:
    consumeUser(std::move(p2));

    std::cout << "After consumeUser, p2 is "
        << (p2 ? "not null" : "null") << '\n';
}
