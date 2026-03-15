#include <cstddef>
#include <cstring>

class Secret {
private:
    char* task{};
    char* password{};
    size_t failedAttempts{};

public:

    Secret() = default;

    Secret(const char* task_, const char* password_) : failedAttempts(0){
        task = new char[strlen(task_) + 1];
        strcpy(task, task_);

        password = new char[strlen(password_) + 1];
        strcpy(password, password_);
    }

    ~Secret() {
        delete[] task;
        delete[] password;
    }

    const char* getTask(const char* pwd) {
        if (strcmp(password, pwd) == 0) {
            return task;
        }
        else {
            failedAttempts++;
            return nullptr;
        }
    }

    void setPassword(const char* newPassword, const char* oldPassword)  {
        if (strcmp(password, oldPassword) == 0) {
            strcpy(password, newPassword);
        }
        else {
            failedAttempts++;
        }
    }

    void setTask(const char* newTask, const char* passwd) {
        if (strcmp(password, passwd) == 0) {
            strcpy(task, newTask);
        }
        else {
            failedAttempts++;
        }
    }

// Не трябва да има setLoginFails(), защото увеличаваме counter-а във самите функции вече.
// Може и да направим copy и assignment оператори за да нямаме проблеми като double free или споделяне на указатели

    int getLoginFails() const {
        return failedAttempts;
    }
};