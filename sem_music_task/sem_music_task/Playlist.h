#pragma once
#include "Song.h"

class Playlist 
{
private:
    static const int MAX_NAME = 257;
    char name[MAX_NAME];
    Song** songs;
    int count;
    int capacity;
    void resize();
    void copyFrom(const Playlist& other);
    void free();

public:
    Playlist(const char* name);
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);
    ~Playlist();
    const char* getName() const;
    void setName(const char* name);
    int getSongCount() const;
    int  getSongIndex(const char* songName);
    void addSong(const Song& songToAdd);
    bool removeSong(const char* songName);
    void printPlaylistInfo();
};