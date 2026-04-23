#pragma once
#include "Duration.h"

class Song 
{
private:
    char* name;
    Duration duration;
    char* genre;
    void copyFrom(const Song& other);
    void free();
public:
    Song(const char* name, Duration duration, const char* genre);
    Song(const Song& other);
    Song& operator=(const Song& other);
    ~Song();
    const char* getName() const;
    Duration getDuration() const;
    const char* getGenre() const;
    void setName(const char* name);
    void setDuration(Duration duration);
    void setGenre(const char* genre);
    void print() const;
};
