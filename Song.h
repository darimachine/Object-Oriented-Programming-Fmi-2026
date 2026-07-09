#pragma once
#include"Duration.h"
#include"GenreConverter.h"
#include<print>

class Song
{
private:
	static constexpr size_t DEFAULT_SIZE = 0;
	char* name;
	Duration duration;
	Genre genre;

	void copyFrom(const Song& other);
	void free();

public:
	Song();

	Song(const char* name, Duration d, Genre g);

	Song(const char* name, Duration d, const char* genre);

	~Song();

	Song(const Song& other);

	Song& operator = (const Song & other);

    bool operator==(const Song& ohter)const;

	const char* getName()const;

	Duration getDuration()const;

	Genre getGenre()const;

	void setName(const char* name);

	void setDuration(const Duration& d);

	void setGenre(const Genre& g);

	void printSong()const;
};

