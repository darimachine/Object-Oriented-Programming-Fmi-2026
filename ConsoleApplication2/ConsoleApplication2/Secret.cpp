#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

#include <iostream>
#include <cstring>

class Secret {
private:
    char* task;
    char* password;
    int loginFails;

    void copyFrom(const Secret& other) {
        this->task = new char[strlen(other.task) + 1];
        strcpy(this->task, other.task);

        this->password = new char[strlen(other.password) + 1];
        strcpy(this->password, other.password);

        this->loginFails = other.loginFails;
    }

    void free() {
        delete[] task;
        delete[] password;
    }

public:
    Secret(const char* task = "", const char* password = "") {
        this->task = new char[strlen(task) + 1];
        strcpy(this->task, task);

        this->password = new char[strlen(password) + 1];
        strcpy(this->password, password);

        this->loginFails = 0;
    }

    Secret(const Secret& other) {
        this->task = new char[strlen(other.task) + 1];
        strcpy(this->task, other.task);

        this->password = new char[strlen(other.password) + 1];
        strcpy(this->password, other.password);

        this->loginFails = other.loginFails;
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
        if (strcmp(this->password, pwd) == 0) {
            return this->task;
        }
        else {
            this->loginFails++;
            return nullptr; 
        }
    }

    bool setPassword(const char* newPassword, const char* oldPassword) {
        if (strcmp(this->password, oldPassword) == 0) {
            delete[] this->password; 
            this->password = new char[strlen(newPassword) + 1]; 
            strcpy(this->password, newPassword);
            return true;
        }
        else {
            this->loginFails++;
            return false;
        }
    }

    bool setTask(const char* newTask, const char* passwd) {
        if (strcmp(this->password, passwd) == 0) {
            delete[] this->task; 
            this->task = new char[strlen(newTask) + 1]; 
            strcpy(this->task, newTask);
            return true;
        }
        else {
            this->loginFails++;
            return false;
        }
    }

    int getLoginFails() const {
        return this->loginFails;
    }
};

