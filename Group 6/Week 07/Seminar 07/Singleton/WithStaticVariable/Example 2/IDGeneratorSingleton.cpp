#include "IDGeneratorSingleton.h"

IDGeneratorSingleton::IDGeneratorSingleton() {};
IDGeneratorSingleton& IDGeneratorSingleton::getInstance()
{
    static IDGeneratorSingleton instance;
    return instance;

}

int IDGeneratorSingleton::generate()
{
    return nextID++;
}

void IDGeneratorSingleton::print() const
{
    cout << "Hello";
}

int IDGeneratorSingleton::getId() const
{
    return nextID;
}
