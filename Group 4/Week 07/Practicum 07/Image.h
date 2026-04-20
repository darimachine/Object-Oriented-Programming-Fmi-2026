#pragma once
#include <iostream>
class Image {
    unsigned char* bytes;
    size_t width;
    size_t height;
    size_t maxVal;
    size_t byteCount;

    void copyFrom(const Image &other);
    void free();

public:
    Image();
    Image(size_t width_, size_t height_, size_t maxVal_, const unsigned char* bytes_);
    Image(const Image &other);
    Image& operator=(const Image& other);
    ~Image();
    size_t getByteCount() const;
    unsigned char* getBytes();
    size_t getWidth() const;
    size_t getHeight() const;
    size_t getMaxVal() const;
};