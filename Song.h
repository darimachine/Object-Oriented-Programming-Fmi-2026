#pragma once
#include "Duration.h"

enum class Genre {
    ROCK,
    POP,
    JAZZ,
    HIPHOP,
    ELECTRONIC,
    OTHER
};

class Song
{
private:
    char* name = nullptr;
    Duration duration;
    Genre genre;

    void copyFrom(const Song&);
    void free();

public:
    Song();
    Song(const char*, const Duration&, Genre);
    Song(const Song&);
    Song& operator=(const Song&);
    ~Song();

    const char* getName() const;
    Duration getDuration() const;
    Genre getGenre() const;

    void setName(const char*);
    void setDuration(const Duration&);
    void setGenre(Genre);

    void print()const;
};

