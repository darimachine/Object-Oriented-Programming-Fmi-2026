#define _CRT_SECURE_NO_WARNINGS
#include "Playlist.h"
#include <cstring>
#include <iostream>

void Playlist::resize() 
{
    capacity = capacity * 2;
    Song** newSongs = new Song* [capacity];
    for (int i = 0; i < count; i++)
    {
        newSongs[i] = songs[i];
    }
    delete[] songs;
    songs = newSongs;
}
void Playlist::copyFrom(const Playlist& other) 
{
    strcpy(name, other.name);
    name[256] = '\0';
    count = other.count;
    capacity = other.capacity;
    songs = new Song * [capacity];
    for (int i = 0; i < count; i++)
    {
        songs[i] = new Song(*other.songs[i]);
    }
}
void Playlist::free() 
{
    for (int i = 0; i < count; i++)
    {
        delete songs[i];
    }
    delete[] songs;
}
Playlist::Playlist(const char* name) : count(0), capacity(4) 
{
    strcpy(this->name, name);
    this->name[256] = '\0';
    songs = new Song* [capacity];
}

Playlist::Playlist(const Playlist& other)
{
    copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other) 
{
    if (this != &other) 
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Playlist::~Playlist() 
{
    free();
}

const char* Playlist::getName() const 
{
    return name;
}
int Playlist::getSongCount() const 
{
    return count;
}
void Playlist::setName(const char* name) 
{
    if (!name)
    {
        std::cout << "Invalid name!" << std::endl;
        return;
    }
    strcpy(this->name, name);
    this->name[256] = '\0';
}
int Playlist::getSongIndex(const char* songName) 
{
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(songs[i]->getName(), songName) == 0)
        {
            return i;
        }
    }
    return -1;
}

void Playlist::addSong(const Song& songToAdd) 
{
    if (getSongIndex(songToAdd.getName()) != -1) 
    {
        std::cout << "Song " << songToAdd.getName() << " already exists in the playlist. Skipping." << std::endl;
        return;
    }
    if (count == capacity)
    {
        resize();
    }
    songs[count++] = new Song(songToAdd);
}

bool Playlist::removeSong(const char* songName) 
{
    int index = getSongIndex(songName);
    if (index == -1) 
    {
        std::cout << "Song " << songName << " not found in playlist." << std::endl;
        return false;
    }
    delete songs[index];
    for (int i = index; i < count - 1; i++)
    {
        songs[i] = songs[i + 1];
    }
    songs[--count] = nullptr;
    return true;
}
void Playlist::printPlaylistInfo() 
{
    unsigned int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += songs[i]->getDuration().totalSeconds();
    }
    unsigned int totalMin = total / 60;
    unsigned int totalSec = total % 60;
    std::cout << "Playlist: " << name << std::endl;
    std::cout << "Songs (" << count << "):" << std::endl;
    for (int i = 0; i < count; i++) 
    {
        std::cout << "  " << (i + 1) << ". ";
        songs[i]->print();
    }
    std::cout << "Total duration: " << totalMin << ":";
    if (totalSec < 10)
    {
        std::cout << "0";
    }
    std::cout << totalSec << std::endl;
}