#define _CRT_SECURE_NO_WARNINGS
#include "Playlist.h"

Playlist::Playlist():countSongs(0),capacity(DEFAULT_SONGS)
{
	songs = new Song[capacity];
	name[0] = '\0';
}

Playlist::Playlist(const char* name,size_t capacity) : 
	countSongs(0), capacity(capacity)
{
	songs = new Song[capacity];
	setNamePlaylist(name);
}

Playlist::~Playlist()
{
	delete[]songs;
	songs = nullptr;
}

const char* Playlist::getNamePlaylist()const
{
	return name;
}

void Playlist::setNamePlaylist(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	strcpy(this->name, name);
}

void Playlist::copyFrom(const Playlist& other)
{
	countSongs = other.countSongs;
	capacity = other.capacity;
	strcpy(name, other.name);

	songs = new Song[capacity];

	for (size_t i = 0;i < countSongs;i++)
	{
		songs[i] = other.songs[i];
	}
}

void Playlist::free()
{
	delete[]songs;
	songs = nullptr;
	countSongs = 0;
	capacity = 0;
}

void Playlist::resize(size_t newCapacity)
{
	Song* newSongs = new Song[newCapacity];

	for (size_t i = 0;i < countSongs;i++)
	{
		newSongs[i] = songs[i];
	}

	delete[]songs;
	songs = newSongs;
	capacity = newCapacity;
}

Playlist::Playlist(const Playlist& other)
{
	copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return  *this;
}

int Playlist::getSongIndex(const char* songName)const
{
	for (size_t i = 0;i < countSongs;i++)
	{
		if (strcmp(songs[i].getName(), songName) == 0)
		{
			return i;
		}
	}

	return -1;
}

void Playlist::addSong(const Song& songToAdd)
{
	if (countSongs == capacity)
	{
	   size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
	   resize(newCapacity);
	}
	
	for (size_t i = 0;i < countSongs;i++)
	{
		if (songs[i] == songToAdd)
		{
			std::println("The song is already in the playlist!");
			return;
		}
	}

	songs[countSongs++] = songToAdd;
}

bool Playlist::removeSong(const char* songName)
{
	if (songName == nullptr)
	{
		return false;
	}

	for (size_t i = 0;i < countSongs;i++)
	{
		if (strcmp(songs[i].getName(), songName) == 0)
		{
			for (size_t j = i + 1;j < countSongs;j++)
			{
				songs[j - 1] = songs[j];
			}
			countSongs--;
			return true;
		}
	}
	return false;
}

void Playlist::printPlaylistInfo()const
{
	std::println("Playlist:");
	for (size_t i = 0;i < countSongs;i++)
	{
		songs[i].printSong();
	}
}