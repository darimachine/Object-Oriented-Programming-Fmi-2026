#define _CRT_SECURE_NO_WARNINGS
#include "Secret.h"
#include <string.h>

static char* copyString(const char* src)
{
    if (!src)
    {
        return nullptr;
    }
    char* copy = new char[strlen(src) + 1];
    strcpy(copy, src);
    return copy;
}

Secret::Secret() : task(nullptr),
password(nullptr), loginFails(0)
{

}

Secret::Secret(const char* _task, const char* _password) : 
    task(copyString(_task)),
    password(copyString(_password)),
    loginFails(0)
{

}

Secret::Secret(const Secret& other) :
    task(copyString(other.task)), 
    password(copyString(other.password)), 
    loginFails(other.loginFails)
{

}

Secret& Secret::operator=(const Secret& other)
{
    if (this != &other)
    {
        delete[] task;
        delete[] password;
        task = copyString(other.task);
        password = copyString(other.password);
        loginFails = other.loginFails;
    }
    return *this;
}

Secret::~Secret()
{
    delete[] task;
    delete[] password;
}

const char* Secret::getTask(const char* passwd)
{
    if (password && passwd && strcmp(passwd, password) == 0)
    {
        return task;
    }
    loginFails++;
    return "Wrong password!";
}

void Secret::setPassword(const char* newPassword, const char* oldPassword)
{
    if (password && oldPassword && strcmp(oldPassword, password) == 0)
    {
        delete[] password;
        password = copyString(newPassword);
    }
    else
    {
        loginFails++;
    }
}

void Secret::setTask(const char* newTask, const char* pwd)
{
    if (password && pwd && strcmp(pwd, password) == 0)
    {
        delete[] task;
        task = copyString(newTask);
    }
    else
    {
        loginFails++;
    }
}

int Secret::getLoginFails() const
{
    return loginFails;
}