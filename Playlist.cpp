#include "Playlist.h"
#include <cstring>
#include <iostream>
#include <print>


void Playlist::copyFrom(const Playlist& other)
{
	strcpy_s(this->name, MAX_SIZE, other.name);

	count = other.count;
	capacity = other.capacity;

	songs = new Song[capacity];
	

	size_t elementsToCopy = std::min(count, capacity);


	for (size_t i = 0; i < elementsToCopy; i++)
	{
		songs[i] = other.songs[i];
	}

}

void Playlist::free()
{
	delete[] songs;
	songs = nullptr;
	count = 0;
}

Playlist::Playlist(): count(0), capacity(8)
{
	name[0] = '\0';
	songs = new Song[capacity];
}

Playlist::Playlist(const char* name, size_t capacity): count(0), capacity(capacity)
{
	strcpy_s(this->name, MAX_SIZE, name);
	songs = new Song[capacity];
}

Playlist::Playlist(const Playlist& other)
{
	copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Playlist::~Playlist()
{
	free();
}

int Playlist::getSongIndex(const char* songName)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(songs[i].getName(), songName) == 0) {
			return i;
		}
	}

	return -1;

}

void Playlist::resize()
{
	capacity *= 2;
	Song* newSongs = new Song[capacity];

	for (size_t i = 0; i < count; i++)
		newSongs[i] = songs[i];

	delete[] songs;
	songs = newSongs;
	
}

void Playlist::addSong(const Song& songToAdd)
{
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(songs[i].getName(), songToAdd.getName()) == 0) {
			return;
		}
	}

	if (count >= capacity) {
		resize();
	}

	songs[count++] = songToAdd;
}

bool Playlist::removeSong(const char* songName)
{
	for (size_t i = 0; i < count; i++)
	{
		if (strcmp(songs[i].getName(), songName) == 0) {
			std::swap(songs[i], songs[count - 1]);
			count--;
			return true;
		}
	}

	return false;
}

void Playlist::printPlaylistInfo() const
{
	std::println("Playlist: {}", name);

	for (size_t i = 0; i < count; i++)
	{
		std::println("Song number {}:", i + 1);
		songs[i].print();
	}
}
