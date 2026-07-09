#pragma once
#include "ImageG.h"
#include <functional>

class Gallery
{
private:
	static constexpr size_t INITIAL_CAP = 50;
	Image** gallery = { nullptr };
	size_t size;
	size_t capacity;

	void copyFrom(const Gallery&);
	void free();
	void moveFrom(Gallery&&);
	void resize(size_t);

public:
	Gallery();
	Gallery(Image**, size_t, size_t);
	Gallery(const Gallery&);
	Gallery& operator=(const Gallery&);

	Gallery(Gallery&&)noexcept;
	Gallery& operator=(Gallery&&)noexcept;

	~Gallery();

	void add(Image*);
	void add(Image*, size_t);
	void remove(size_t);
	void showEmpty();
	void clear();
	Image* operator[](size_t);
	size_t getSize();

	Gallery filter(ImageType type);
	void applyToAll(std::function<void(Image*)>);
	Gallery& operator+=(const Gallery&);
	Gallery operator+(const Gallery&) const;
	Image* findLargest();
	void saveAll(const char*);

	static void intToString(size_t, char*);
};




