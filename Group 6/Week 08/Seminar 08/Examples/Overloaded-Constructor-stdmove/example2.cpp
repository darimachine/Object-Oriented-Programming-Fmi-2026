
#include <iostream>
#include <crtdbg.h>

using namespace std;
struct Student {
    std::string name;
    //Student(std::string t) : name(std::move(t)) { std::cout << "Hello " << name << "\n"; } 1
    //Student(std::string& t) : name(std::move(t)) { std::cout << "Hello " << name << "\n"; }
    //Student(const std::string& t) : name(std::move(t)) { std::cout << "Hello " << name << "\n"; }
    //Student(std::string&& t) : name(std::move(t)) { std::cout << "Hello " << name << "\n"; } 4 cannot live with 1

    ~Student() { std::cout << "Bye " << name << "\n"; }
    void warn(std::string m) { std::cout << name << ": " << m << "\n"; }
};
int main() {
    {
        Student L("Serhan");
        L.warn("Not here");
    }
    std::cout << "End\n";
}
