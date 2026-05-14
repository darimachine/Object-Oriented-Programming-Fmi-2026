#include <iostream>
#include "Secret.h"

int main()
{
    Secret s("OOP exam task", "1234");

    std::cout << s.getTask("1111") << std::endl;
    std::cout << s.getTask("1211") << std::endl;
    std::cout << s.getTask("1141") << std::endl;
    std::cout << s.getTask("1219") << std::endl;
    std::cout << s.getTask("1234") << std::endl;
    s.setPassword("asd", "1234");
    s.setTask("New OOP exam task", "asd");
    std::cout << s.getTask("asd") << std::endl;
    std::cout << "Login fails: " << s.getLoginFails() << std::endl;

    Secret s2 = s;
    std::cout << s2.getTask("asd") << std::endl;
}