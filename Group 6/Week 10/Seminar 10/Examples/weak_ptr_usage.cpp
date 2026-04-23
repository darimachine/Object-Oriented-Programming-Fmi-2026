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

void inspectWeak(const std::weak_ptr<User>& weakUser) {
    std::cout << "inside inspectWeak:\n";
    std::cout << "  expired = " << std::boolalpha << weakUser.expired() << '\n';

    if (std::shared_ptr<User> shared = weakUser.lock()) {
        std::cout << "  lock() succeeded, name = " << shared->getName() << '\n';
        std::cout << "  use_count = " << shared.use_count() << '\n';
    } else {
        std::cout << "  lock() failed, object no longer exists\n";
    }
}

int main() {
    std::weak_ptr<User> wptr;

    {
        std::shared_ptr<User> sp1 = std::make_shared<User>("Alice");
        std::cout << "After make_shared, sp1.use_count = " << sp1.use_count() << '\n';

        wptr = sp1; // weak_ptr observes the same object
        std::cout << "After assigning to weak_ptr, sp1.use_count = " << sp1.use_count() << '\n';

        std::cout << "wptr.expired = " << std::boolalpha << wptr.expired() << '\n';

        if (std::shared_ptr<User> sp2 = wptr.lock()) {
            std::cout << "After lock(), sp2.use_count = " << sp2.use_count() << '\n';
            std::cout << "sp2->name = " << sp2->getName() << '\n';
        }

        std::cout << "Before leaving scope, sp1.use_count = " << sp1.use_count() << '\n';
    } // sp1 is destroyed here, so the User object is destroyed here too

    std::cout << "After sp1 scope ends:\n";
    std::cout << "wptr.expired = " << std::boolalpha << wptr.expired() << '\n';

    if (std::shared_ptr<User> sp3 = wptr.lock()) {
        std::cout << "lock() succeeded unexpectedly: " << sp3->getName() << '\n';
    } else {
        std::cout << "lock() returned empty shared_ptr because object is already destroyed\n";
    }
}
