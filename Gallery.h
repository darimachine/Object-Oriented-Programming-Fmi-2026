#pragma once
#include"Image.h"
#include <functional>
#include"ImageUtils.h"

class Gallery
{
private:
	Image** images = nullptr;
	size_t size = 0;
	size_t capacity = 16;

    void copyFrom(const Gallery& other);
    void free();
    void moveFrom(Gallery&& other);
    void resize();

public:
    Gallery();
    Gallery(size_t capacity);
    ~Gallery();

    Gallery(const Gallery& other);
    Gallery& operator=(const Gallery& other);
    Gallery(Gallery&& other)noexcept;
    Gallery& operator=(Gallery&& other)noexcept;

    void add(Image* img);
    void add(Image* img, size_t index);
    void remove(size_t index);
    void showEmpty() const;
    void clear();

    const Image* operator[](size_t index) const;
    Image* operator[](size_t index);
    size_t getSize() const;

    Gallery filter(ImageType type) const;
    void applyToAll(std::function<void(Image*)> op);

    Gallery operator+(const Gallery& other) const;

    const Image* findLargest() const;
    void saveAll(const char* directory) const;
};

