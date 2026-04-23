#include <iostream>
#include <memory>
#include <string>

class User {
private:
    std::string name;

public:
    explicit User(const std::string& n) : name(n) {
        std::cout << "User " << name << " created" << std::endl;
    }

    explicit User(std::string&& n) : name(std::move(n)) {
        std::cout << "User " << name << " created" << std::endl;
    }

    ~User() {
        std::cout << "User " << name << " destroyed" << std::endl;
    }

    const std::string& getName() const { return name; }
};

// Passing by const reference does NOT increase the reference count
void printUser(const std::shared_ptr<User>& user) {
    if (user) {
        std::cout << "printUser: " << user->getName()
                  << ", use_count = " << user.use_count() << '\n';
    }
}

// Passing by value creates one more shared_ptr owner
void shareUser(std::shared_ptr<User> user) {
    std::cout << "shareUser entered, use_count = " << user.use_count() << '\n';

    if (user) {
        std::cout << "shareUser: " << user->getName() << '\n';
    }

    // user goes out of scope here, so the count decreases by 1
}

int main() {
    std::shared_ptr<User> p1 = std::make_shared<User>("Alice");
    std::cout << "After make_shared, p1.use_count = " << p1.use_count() << '\n';

    {
        std::shared_ptr<User> p2 = p1; // copy is allowed
        std::cout << "After copying to p2:\n";
        std::cout << "  p1.use_count = " << p1.use_count() << '\n';
        std::cout << "  p2.use_count = " << p2.use_count() << '\n';

        printUser(p1);
        std::cout << "After printUser, p1.use_count = " << p1.use_count() << '\n';

        shareUser(p1);
        std::cout << "After shareUser, p1.use_count = " << p1.use_count() << '\n';

        {
            std::shared_ptr<User> p3 = p2;
            std::cout << "After copying to p3:\n";
            std::cout << "  p1.use_count = " << p1.use_count() << '\n';
            std::cout << "  p2.use_count = " << p2.use_count() << '\n';
            std::cout << "  p3.use_count = " << p3.use_count() << '\n';
        } // p3 is destroyed here

        std::cout << "After p3 scope ends, p1.use_count = " << p1.use_count() << '\n';
    } // p2 is destroyed here

    std::cout << "After p2 scope ends, p1.use_count = " << p1.use_count() << '\n';

    p1.reset(); // last owner releases the object here, manually calls destructor
    std::cout << (p1 ? "not null" : "null") << '\n';
    std::cout << "After p1.reset()\n";
}
