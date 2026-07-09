#include "TypeConverter.h"
#include "Song.h"
#include <cstring>
#include <print>


void Song::copyFrom(const Song& other)
{

    size_t size = strlen(other.name) + 1;
    name = new char[size];
    strcpy_s(name, size, other.name);

    duration = other.duration;
    genre = other.genre;
}

void Song::free()
{
    delete[] name;
    name = nullptr;
}

Song::Song() : duration(), genre(Genre::OTHER)
{
    name = new char[1];
    name[0] = '\0';
}

Song::Song(const char*name, const Duration& duration, Genre genre) : duration(duration), genre(genre)
{
    size_t size = strlen(name) + 1;
    this->name = new char[size];
    strcpy_s(this->name, size, name);
}

Song::Song(const Song&other)
{
    copyFrom(other);
}

Song& Song::operator=(const Song&other)
{
    if (this != &other) {
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

Duration Song::getDuration() const
{
    return duration;
}

Genre Song::getGenre() const
{
    return genre;
}

void Song::setName(const char* newName)
{

    if (newName == nullptr) {
        delete[] name;
        name = new char[1];
        name[0] = '\0';
        return;
    }

    delete[] name;
    size_t size = strlen(newName) + 1;
    name = new char[size];
    strcpy_s(name, size, newName);
}

void Song::setDuration(const Duration& duration)
{
    this->duration = duration;
}

void Song::setGenre(Genre genre)
{
    this->genre = genre;
}

void Song::print() const
{
    std::println("Song name: {}, duration: {}:{:02}, genre: {}",
        name,
        duration.minutes,
        duration.seconds,
        TypeConverter::TypeToString(genre));
}
