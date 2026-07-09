#pragma once
#include"Song.h"

class Playlist
{
private:
	static constexpr size_t DEFAULT_SONGS = 16;
	Song* songs;
	char name[256];
	size_t countSongs = 0;
	size_t capacity;

	void copyFrom(const Playlist& other);
	void free();
	void resize(size_t newCapacity);
	int getSongIndex(const char* songName)const;

public:
	Playlist();

	~Playlist();

	Playlist(const char* name,size_t capacity);

	Playlist(const Playlist& other);

	Playlist& operator=(const Playlist& other);

	const char* getNamePlaylist()const;

	void setNamePlaylist(const char* name);

	void addSong(const Song& songToAdd);

	bool removeSong(const char* songName);

	void printPlaylistInfo()const;
};

