#include "Image.h"

void Image::copyFrom(const Image& other) {
    width = other.width;
    height = other.height;
    maxVal = other.maxVal;
    byteCount = other.byteCount;
    bytes=new unsigned char[byteCount];
    for (int i = 0; i < byteCount; i++) {
        bytes[i] = other.bytes[i];
    }

}

void Image::free() {
    delete [] bytes;
    bytes = nullptr;
    width = 0;
    height = 0;
    maxVal = 0;
    byteCount = 0;
}

Image::Image() {
}

Image::Image(size_t width_, size_t height_, size_t maxVal_, const unsigned char *bytes_): width(width_), height(height_), maxVal(maxVal_) {
    byteCount = width_ * height_ * 3;
    bytes = new unsigned char[byteCount];
    for (int i = 0; i < byteCount; i++) {
        bytes[i] = bytes_[i];
    }
}

Image::Image(const Image &other) {
    copyFrom(other);
}

Image & Image::operator=(const Image& other){
    if (this == &other){return *this;}
    free();
    copyFrom(other);
    return *this;
}

Image::~Image() {
    free();
}

size_t Image::getByteCount() const {
    return byteCount;
}

unsigned char* Image::getBytes() {
    return bytes;
}

size_t Image::getWidth() const {
    return width;
}

size_t Image::getHeight() const {
    return height;
}

size_t Image::getMaxVal() const {
    return maxVal;
}