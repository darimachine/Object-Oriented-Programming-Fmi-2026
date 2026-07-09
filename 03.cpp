
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Secret {
private:
    char* task;
    char* password;
    unsigned loginFails;

    void copyFrom(const Secret& other) {
        task = new char[strlen(other.task) + 1];
        strcpy(task, other.task);

        password = new char[strlen(other.password) + 1];
        strcpy(password, other.password);

        loginFails = other.loginFails;
    }

    void free() {
        delete[] task;
        delete[] password;
    }

public:

    Secret() {
        task = new char[1];
        task[0] = '\0';

        password = new char[1];
        password[0] = '\0';

        loginFails = 0;
    }

    Secret(const char* task, const char* password) {
        this->task = new char[strlen(task) + 1];
        strcpy(this->task, task);

        this->password = new char[strlen(password) + 1];
        strcpy(this->password, password);

        loginFails = 0;
    }

    Secret(const Secret& other) {
        copyFrom(other);
    }

    Secret& operator=(const Secret& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~Secret() {
        free();
    }

    const char* getTask(const char* pwd) {
        if (strcmp(pwd, password) == 0) {
            return task;
        }

        loginFails++;
        return "Wrong password";
    }

    void setPassword(const char* newPassword, const char* oldPassword) {
        if (strcmp(oldPassword, password) == 0) {
            delete[] password;
            password = new char[strlen(newPassword) + 1];
            strcpy(password, newPassword);
        }
        else {
            loginFails++;
        }
    }

    void setTask(const char* newTask, const char* passwd) {
        if (strcmp(passwd, password) == 0) {
            delete[] task;
            task = new char[strlen(newTask) + 1];
            strcpy(task, newTask);
        }
        else {
            loginFails++;
        }
    }

    unsigned getLoginFails() const {
        return loginFails;
    }
};
int main() {

    Secret s("Write class Secret", "1234");

    std::cout << s.getTask("1111") << std::endl;
    std::cout << s.getTask("1234") << std::endl;

    s.setTask("New exercise OOP", "1234");

    std::cout << s.getTask("1234") << std::endl;

    s.setPassword("abcd", "1234");

    std::cout << "Login fails: " << s.getLoginFails() << std::endl;


}

