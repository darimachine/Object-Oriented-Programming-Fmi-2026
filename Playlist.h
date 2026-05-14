#pragma once
#include"Song.h"

class Playlist
{
private:
	static constexpr unsigned int MAX_SIZE = 256;
	char name[MAX_SIZE];
	Song* songs = nullptr;
	size_t count = 0;
	size_t capacity = 0;

	void copyFrom(const Playlist&);
	void free();

public:
	Playlist();
	Playlist(const char*, size_t);
	Playlist(const Playlist&);
	Playlist& operator=(const Playlist&);
	~Playlist();

	int getSongIndex(const char*);
	void resize();
	void addSong(const Song&);
	bool removeSong(const char*);
	void printPlaylistInfo() const;
};

