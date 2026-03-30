#define _CRT_SECURE_NO_WARNINGS
#include "Song.h"
#include <cstring>
#include <iostream>

void Song::copyFrom(const Song& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    genre = new char[strlen(other.genre) + 1];
    strcpy(genre, other.genre);

    duration = other.duration;
}
void Song::free()
{
    delete[] name;
    delete[] genre;
}
Song::Song(const char* name, Duration duration, const char* genre)
    : duration(duration)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);
}
Song::Song(const Song& other)
{
    copyFrom(other);
}
Song& Song::operator=(const Song& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
Song::~Song()
{
    free();
}
const char* Song::getName() const 
{ 
    return name;
}
const char* Song::getGenre() const 
{
    return genre;
}
Duration Song::getDuration() const
{ 
    return duration;
}
void Song::setName(const char* newName)
{
    if (!newName)
    {
        return;
    }
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}
void Song::setGenre(const char* newGenre)
{
    if (!newGenre)
    {
        return;
    }
    delete[] genre;
    genre = new char[strlen(newGenre) + 1];
    strcpy(genre, newGenre);
}
void Song::setDuration(Duration newDuration)
{
    duration = newDuration;
}
void Song::print() const
{
    std::cout << name << " (" << genre << ") " << duration.getMinutes() << ":";
    if (duration.getSeconds() < 10)
    {
        std::cout << "0";
    }
    std::cout << duration.getSeconds() << std::endl;
}